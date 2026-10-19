package com.ipcmobile.snapipc.androidnative

import com.ipcmobile.snapipcsdk.models.ConnectionState
import com.ipcmobile.snapipcsdk.SnapHalo
import com.ipcmobile.snapipcsdk.events.SnapHaloEvent
import com.ipcmobile.snapipcsdk.models.Barcode
import com.ipcmobile.snapipcsdk.models.DeviceDetails
import com.ipcmobile.snapipcsdk.models.BarcodeScanMode
import com.ipcmobile.snapipcsdk.models.ScannerSymbology
import kotlinx.coroutines.CancellationException
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.CoroutineStart
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job
import kotlinx.coroutines.SupervisorJob
import kotlinx.coroutines.cancel
import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch
import kotlin.random.Random

class SnapIPCDemoController(
    val snapHalo: SnapHalo = SnapHalo(),
    private val cancelPendingPairing: () -> Unit = {},
) : AutoCloseable {
    private val scope = CoroutineScope(SupervisorJob() + Dispatchers.Default)
    private val mutableState = MutableStateFlow(createState())
    private var connectionJob: Job? = null
    private var detailsJob: Job? = null
    private var scanDisplayJob: Job? = null
    private var scanCommandJob: Job? = null
    private var sequence = 0

    val state: StateFlow<SnapIPCDemoUiState> = mutableState.asStateFlow()

    private val eventJob = scope.launch(start = CoroutineStart.UNDISPATCHED) {
        snapHalo.events.collect { event ->
            when (event) {
                is SnapHaloEvent.OnConnectionStatus -> onStateChanged(event.connectionState, event.errorMessage)
                is SnapHaloEvent.OnBarcodeScanned -> onBarcodeScanned(event.barcode)
                is SnapHaloEvent.OnBatteryTelemetryChanged ->
                    mutableState.update { it.copy(batteryTelemetry = event.telemetry) }
                is SnapHaloEvent.OnFirmwareVersionChanged ->
                    mutableState.update { it.copy(firmwareVersion = event.version) }
                is SnapHaloEvent.OnSecurityWarning ->
                    mutableState.update { it.copy(connectionError = event.message) }
                is SnapHaloEvent.OnTriggerChanged -> Unit
            }
        }
    }

    fun reportPairingError(message: String) {
        mutableState.update { it.copy(connectionError = message) }
    }

    fun disconnect() {
        cancelPendingPairing()
        connectionJob?.cancel()
        connectionJob = scope.launch {
            resetScanSession()
            snapHalo.disconnect()
            mutableState.update {
                createState().copy(deviceState = DeviceUiState.WaitingForPairing)
            }
        }
    }

    fun setScanMode(mode: BarcodeScanMode) {
        launchDeviceUpdate(
            action = { snapHalo.barcode.setScanMode(mode) },
            update = { it.copy(scanMode = mode) },
        )
    }

    fun toggleScan() {
        val current = mutableState.value
        if (!current.canToggleScan) return
        val start = !current.isSoftScanActive
        mutableState.update { it.copy(isScanCommandPending = true) }
        scanCommandJob = scope.launch {
            try {
                if (start) snapHalo.barcode.startScan() else snapHalo.barcode.stopScan()
                mutableState.update {
                    it.copy(isSoftScanActive = start, isScanCommandPending = false, connectionError = null)
                }
            } catch (cancelled: CancellationException) {
                throw cancelled
            } catch (failure: Exception) {
                mutableState.update { it.copy(isScanCommandPending = false, connectionError = failure.message) }
            }
        }
    }

    fun setSymbology(symbology: ScannerSymbology, enabled: Boolean) {
        launchDeviceUpdate(
            action = { snapHalo.barcode.setSymbology(symbology, enabled) },
            update = { it.copy(symbologyEnabled = it.symbologyEnabled + (symbology to enabled)) },
        )
    }

    fun setAllSymbologies(enabled: Boolean) {
        launchDeviceUpdate(
            action = { snapHalo.barcode.setEnableAllSymbologies(enabled) },
            update = { state -> state.copy(symbologyEnabled = state.symbologies.associateWith { enabled }) },
        )
    }

    fun simulateScan() {
        if (mutableState.value.isScanning) return
        scope.launch {
            mutableState.update { it.copy(isScanning = true, deviceState = DeviceUiState.Connected) }
            delay(250)
            val barcode = buildString { repeat(13) { append(Random.nextInt(10)) } }
            val types = listOf("EAN-13", "Code 128", "QR Code", "Data Matrix")
            showScan(barcode, types.random())
        }
    }

    private fun onStateChanged(state: ConnectionState, errorMessage: String?) {
        val wasConnected = mutableState.value.connectionState == ConnectionState.Connected
        if (state != ConnectionState.Connected) {
            detailsJob?.cancel()
            detailsJob = null
        } else if (!wasConnected) {
            detailsJob = scope.launch {
                try {
                    applyDeviceDetails(snapHalo.details())
                } catch (cancelled: CancellationException) {
                    throw cancelled
                } catch (failure: Exception) {
                    mutableState.update { it.copy(connectionError = failure.message) }
                }
            }
        }
        if (state != ConnectionState.Connected) {
            resetScanSession()
            mutableState.update {
                createState().copy(
                    deviceState = DeviceUiState.WaitingForPairing,
                    connectionState = state,
                    connectionError = errorMessage,
                )
            }
        } else if (!mutableState.value.isScanning) {
            refresh { it.copy(deviceState = DeviceUiState.Connected, connectionState = state, connectionError = errorMessage) }
        }
    }
    private fun applyDeviceDetails(details: DeviceDetails) {
        mutableState.update { state ->
            state.copy(
                scanMode = details.scanWorkMode ?: state.scanMode,
                symbologyEnabled = state.symbologies.associateWith(details::isSymbologyEnabled),
                connectionError = null,
            )
        }
    }

    private fun onBarcodeScanned(barcode: Barcode) {
        showScan(barcode.value, barcode.symbology)
        if (mutableState.value.scanMode == BarcodeScanMode.Single && mutableState.value.isSoftScanActive) {
            toggleScan()
        }
    }

    private fun showScan(barcode: String, symbology: String) {
        sequence += 1
        val timestamp = currentDateTimeLabels()
        scanDisplayJob?.cancel()
        mutableState.update { previous ->
            previous.copy(
                deviceState = DeviceUiState.ValidScan,
                lastScan = ScanRecord(sequence, barcode, symbology, timestamp.date, timestamp.time),
                isScanning = true,
            )
        }
        scanDisplayJob = scope.launch {
            delay(1_600)
            mutableState.update { previous ->
                previous.copy(
                    deviceState = if (snapHalo.getConnectionState() == ConnectionState.Connected) {
                        DeviceUiState.Connected
                    } else {
                        DeviceUiState.WaitingForPairing
                    },
                    connectionState = snapHalo.getConnectionState(),
                    isScanning = false,
                )
            }
        }
    }

    private fun resetScanSession() {
        scanCommandJob?.cancel()
        scanCommandJob = null
        scanDisplayJob?.cancel()
        scanDisplayJob = null
        sequence = 0
        mutableState.update {
            it.copy(lastScan = null, isScanning = false, isSoftScanActive = false, isScanCommandPending = false)
        }
    }

    private fun refresh(transform: (SnapIPCDemoUiState) -> SnapIPCDemoUiState = { it }) {
        mutableState.update { previous ->
            transform(
                createState().copy(
                    deviceState = previous.deviceState,
                    connectionError = previous.connectionError,
                    lastScan = previous.lastScan,
                    isScanning = previous.isScanning,
                    isSoftScanActive = previous.isSoftScanActive,
                    isScanCommandPending = previous.isScanCommandPending,
                    scanMode = previous.scanMode,
                    symbologies = previous.symbologies,
                    symbologyEnabled = previous.symbologyEnabled,
                ),
            )
        }
    }

    private fun createState() = SnapIPCDemoUiState(
        connectionState = snapHalo.getConnectionState(),
        batteryTelemetry = snapHalo.battery.telemetry,
    )

    private fun launchDeviceUpdate(
        action: suspend () -> Unit,
        update: (SnapIPCDemoUiState) -> SnapIPCDemoUiState,
    ) {
        scope.launch {
            try {
                action()
                mutableState.update { update(it).copy(connectionError = null) }
            } catch (cancelled: CancellationException) {
                throw cancelled
            } catch (failure: Exception) {
                mutableState.update { it.copy(connectionError = failure.message) }
            }
        }
    }

    override fun close() {
        detailsJob?.cancel()
        connectionJob?.cancel()
        scanDisplayJob?.cancel()
        scanCommandJob?.cancel()
        eventJob.cancel()
        snapHalo.close()
        scope.cancel()
    }
}

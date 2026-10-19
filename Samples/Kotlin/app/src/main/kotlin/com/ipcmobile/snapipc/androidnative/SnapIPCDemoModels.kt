package com.ipcmobile.snapipc.androidnative

import com.ipcmobile.snapipcsdk.models.ConnectionState
import com.ipcmobile.snapipcsdk.models.BatteryTelemetry
import com.ipcmobile.snapipcsdk.models.BarcodeScanMode
import com.ipcmobile.snapipcsdk.models.ScannerSymbology

enum class DeviceUiState {
    WaitingForPairing,
    Connected,
    ValidScan,
}

data class ScanRecord(
    val sequence: Int,
    val barcode: String,
    val symbology: String,
    val date: String,
    val time: String,
)

data class SnapIPCDemoUiState(
    val deviceState: DeviceUiState = DeviceUiState.WaitingForPairing,
    val connectionState: ConnectionState = ConnectionState.WaitingForNfc,
    val connectionError: String? = null,
    val lastScan: ScanRecord? = null,
    val isScanning: Boolean = false,
    val isSoftScanActive: Boolean = false,
    val isScanCommandPending: Boolean = false,
    val batteryTelemetry: BatteryTelemetry? = null,
    val firmwareVersion: String? = null,
    val scanMode: BarcodeScanMode = BarcodeScanMode.Single,
    val symbologies: List<ScannerSymbology> = ScannerSymbology.Supported,
    val symbologyEnabled: Map<ScannerSymbology, Boolean> = ScannerSymbology.Supported.associateWith { true },
) {
    val canDisconnect: Boolean
        get() = connectionState == ConnectionState.Connected ||
            connectionState == ConnectionState.Reconnecting

    val canToggleScan: Boolean
        get() = connectionState == ConnectionState.Connected && !isScanCommandPending

    val enabledSymbologyCount: Int get() = symbologyEnabled.count { it.value }
    val allSymbologiesEnabled: Boolean get() = symbologyEnabled.values.all { it }

    val statusText: String
        get() = when (connectionState) {
            ConnectionState.WaitingForNfc -> "Awaiting NFC pairing"
            ConnectionState.RequestingBluetooth -> "Requesting Bluetooth"
            ConnectionState.Scanning -> "Finding scanner"
            ConnectionState.Connecting -> "Connecting"
            ConnectionState.DiscoveringServices -> "Preparing scanner"
            ConnectionState.Connected -> "Connected"
            ConnectionState.Reconnecting -> "Reconnecting"
            ConnectionState.Error -> "Connection failed"
        }

    val stateLabel: String
        get() = when (deviceState) {
            DeviceUiState.WaitingForPairing -> statusText
            DeviceUiState.Connected -> "Connected"
            DeviceUiState.ValidScan -> "Valid barcode"
        }

    val emptyTitle: String
        get() = when {
            connectionState == ConnectionState.Error -> "Could not connect"
            deviceState == DeviceUiState.WaitingForPairing -> "Ready to pair"
            else -> "Ready to scan"
        }

    val emptyMessage: String
        get() = if (deviceState == DeviceUiState.WaitingForPairing) {
            connectionError ?: "Hold the phone near the scanner NFC pairing point."
        } else {
            "The next barcode will appear here."
        }
}

internal data class DateTimeLabels(val date: String, val time: String)

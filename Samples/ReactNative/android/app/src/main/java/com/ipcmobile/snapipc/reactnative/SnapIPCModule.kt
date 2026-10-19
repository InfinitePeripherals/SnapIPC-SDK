package com.ipcmobile.snapipc.reactnative

import com.facebook.react.bridge.Arguments
import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.bridge.WritableMap
import com.facebook.react.modules.core.DeviceEventManagerModule
import com.ipcmobile.snapipcsdk.events.SnapHaloEvent
import com.ipcmobile.snapipcsdk.models.BarcodeScanMode
import com.ipcmobile.snapipcsdk.models.BatteryTelemetry
import com.ipcmobile.snapipcsdk.models.ConnectionState
import com.ipcmobile.snapipcsdk.models.ScannerSymbology
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.SupervisorJob
import kotlinx.coroutines.cancel
import kotlinx.coroutines.launch

class SnapIPCModule(context: ReactApplicationContext) : ReactContextBaseJavaModule(context) {
  private val halo = SnapIPCSession.halo
  private val scope = CoroutineScope(SupervisorJob() + Dispatchers.Main.immediate)
  private val subscription = halo.observeEvents { event -> handleEvent(event) }
  private var listenerCount = 0

  init {
    SnapIPCSession.errorSink = { message ->
      emit(Arguments.createMap().apply {
        putString("type", "error")
        putString("message", message)
      })
    }
    if (halo.getConnectionState() == ConnectionState.Connected) loadDetails()
  }

  override fun getName() = "SnapIPCModule"

  @ReactMethod
  fun addListener(eventName: String) {
    if (eventName == "SnapIPCEvent") listenerCount++
  }

  @ReactMethod
  fun removeListeners(count: Int) {
    listenerCount = (listenerCount - count).coerceAtLeast(0)
  }

  @ReactMethod
  fun getSnapshot(promise: Promise) {
    val formats = Arguments.createArray()
    ScannerSymbology.Supported.forEach { format ->
      formats.pushMap(Arguments.createMap().apply {
        putInt("id", format.id)
        putString("name", format.displayName)
      })
    }
    promise.resolve(Arguments.createMap().apply {
      putString("connection", halo.getConnectionState().name)
      putArray("symbologies", formats)
      halo.battery.telemetry?.let { putMap("battery", batteryMap(it)) }
    })
    if (halo.getConnectionState() == ConnectionState.Connected) loadDetails()
  }

  @ReactMethod
  fun startPairing(promise: Promise) {
    val activity = reactApplicationContext.currentActivity
    val adapter = SnapIPCSession.adapter
    if (activity == null || adapter == null) {
      promise.reject("NO_ACTIVITY", "Open the app before starting NFC pairing.")
      return
    }
    activity.runOnUiThread {
      try {
        adapter.requestPermissions()
        promise.resolve(null)
      } catch (failure: Exception) {
        promise.reject("PAIRING_FAILED", failure)
      }
    }
  }

  @ReactMethod
  fun disconnect(promise: Promise) = command(promise) {
    SnapIPCSession.adapter?.cancelPendingConnection()
    halo.disconnect()
  }

  @ReactMethod
  fun startScan(promise: Promise) = command(promise) { halo.barcode.startScan() }

  @ReactMethod
  fun stopScan(promise: Promise) = command(promise) { halo.barcode.stopScan() }

  @ReactMethod
  fun setScanMode(mode: String, promise: Promise) = command(promise) {
    halo.barcode.setScanMode(BarcodeScanMode.valueOf(mode))
  }

  @ReactMethod
  fun setSymbology(id: Int, enabled: Boolean, promise: Promise) = command(promise) {
    val format = ScannerSymbology.Supported.firstOrNull { it.id == id }
      ?: throw IllegalArgumentException("Unsupported symbology: $id")
    halo.barcode.setSymbology(format, enabled)
  }

  @ReactMethod
  fun setAllSymbologies(enabled: Boolean, promise: Promise) = command(promise) {
    halo.barcode.setEnableAllSymbologies(enabled)
  }

  private fun command(promise: Promise, action: suspend () -> Unit) {
    scope.launch {
      try {
        action()
        promise.resolve(null)
      } catch (failure: Exception) {
        promise.reject("SNAPIPC_ERROR", failure)
      }
    }
  }

  private fun handleEvent(event: SnapHaloEvent) {
    when (event) {
      is SnapHaloEvent.OnConnectionStatus -> {
        emit(Arguments.createMap().apply {
          putString("type", "connection")
          putString("connection", event.connectionState.name)
          event.errorMessage?.let { putString("message", it) }
        })
        if (event.connectionState == ConnectionState.Connected) loadDetails()
      }
      is SnapHaloEvent.OnBarcodeScanned -> emit(Arguments.createMap().apply {
        putString("type", "barcode")
        putString("value", event.barcode.value)
        putString("symbology", event.barcode.symbology)
      })
      is SnapHaloEvent.OnBatteryTelemetryChanged -> emit(Arguments.createMap().apply {
        putString("type", "battery")
        putMap("battery", batteryMap(event.telemetry))
      })
      is SnapHaloEvent.OnFirmwareVersionChanged -> emit(Arguments.createMap().apply {
        putString("type", "firmware")
        putString("firmware", event.version)
      })
      is SnapHaloEvent.OnSecurityWarning -> emit(Arguments.createMap().apply {
        putString("type", "error")
        putString("message", event.message)
      })
      is SnapHaloEvent.OnTriggerChanged -> Unit
    }
  }

  private fun loadDetails() {
    scope.launch {
      try {
        val details = halo.details()
        if (halo.getConnectionState() != ConnectionState.Connected) return@launch
        emit(Arguments.createMap().apply {
          putString("type", "details")
          putString("mode", (details.scanWorkMode ?: BarcodeScanMode.Single).name)
          putMap("enabled", Arguments.createMap().apply {
            ScannerSymbology.Supported.forEach { format ->
              putBoolean(format.id.toString(), details.isSymbologyEnabled(format))
            }
          })
        })
        emit(Arguments.createMap().apply {
          putString("type", "firmware")
          putString("firmware", halo.getFirmware())
          putString("scannerFirmware", halo.barcode.getFirmware())
        })
      } catch (failure: Exception) {
        emit(Arguments.createMap().apply {
          putString("type", "error")
          putString("message", failure.message)
        })
      }
    }
  }

  private fun batteryMap(battery: BatteryTelemetry): WritableMap = Arguments.createMap().apply {
    putInt("stateOfCharge", battery.stateOfCharge)
    putDouble("voltage", battery.voltage)
    putInt("remainingCapacityMah", battery.remainingCapacityMah)
    putDouble("temperatureCelsius", battery.temperatureCelsius)
    putBoolean("isCharging", battery.isCharging)
  }

  private fun emit(payload: WritableMap) {
    if (listenerCount > 0) {
      reactApplicationContext
        .getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter::class.java)
        .emit("SnapIPCEvent", payload)
    }
  }

  override fun invalidate() {
    subscription.close()
    SnapIPCSession.errorSink = null
    scope.cancel()
    super.invalidate()
  }
}

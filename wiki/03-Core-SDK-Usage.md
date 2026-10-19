# Core SDK usage: commands, data, and state

Use one `SnapHalo` per owned scanner session. The public client groups barcode operations under `barcode`, battery data under `battery`, and light controls under `light`. Device queries such as `details()`, `getModel()`, `getFirmware()`, and `readRssi()` remain on the client. Android calls suspend in coroutines; the generated Swift API is used with `async/await` in the [Swift model](../Samples/Swift/Sources/SnapIPCAppModel.swift).

## Sending commands and reading state

Wait for `ConnectionState.Connected` before a device command. `barcode.startScan()` and `barcode.stopScan()` represent software trigger press and release. `barcode.setScanMode()`, `setSymbology()`, and `setEnableAllSymbologies()` configure scanner behavior; the [Kotlin controller](../Samples/Kotlin/app/src/main/kotlin/com/ipcmobile/snapipc/androidnative/SnapIPCDemoController.kt) shows the UI gating and error paths.

Setters complete after a successful BLE write. They do **not** wait for a firmware acknowledgement, so a successful return does not prove that older firmware applied a setting. Queries wait for a typed reply and use the SDK's fixed three-second timeout. Query results may become stale immediately after a disconnect.

```kotlin
import android.util.Log
import com.ipcmobile.snapipcsdk.SnapHalo
import com.ipcmobile.snapipcsdk.models.BarcodeScanMode
import com.ipcmobile.snapipcsdk.models.DeviceDetails
import com.ipcmobile.snapipcsdk.models.ScannerSymbology
import kotlinx.coroutines.CancellationException
import kotlinx.coroutines.TimeoutCancellationException

// Call from an owned coroutine after observing Connected.
suspend fun configureScanner(halo: SnapHalo): DeviceDetails? {
    return try {
        halo.barcode.setScanMode(BarcodeScanMode.Continuous)
        halo.barcode.setSymbology(ScannerSymbology.SYM_QR, true)
        val details = halo.details() // Read the scanner's reported state after writes.
        val enabled = halo.barcode.getSymobologies() // Published spelling is "Symobologies".
        Log.i("SnapHalo", "QR enabled: ${enabled[ScannerSymbology.SYM_QR]}")
        details
    } catch (timeout: TimeoutCancellationException) {
        Log.e("SnapHalo", "Settings query timed out", timeout)
        null
    } catch (cancelled: CancellationException) {
        throw cancelled // Preserve coroutine cancellation.
    } catch (failure: Exception) {
        Log.e("SnapHalo", "Scanner command failed", failure)
        null
    }
}
```

The method name `getSymobologies()` is spelled that way in SDK 1.0.0. `ScannerSymbology.Supported` holds user-selectable formats; do not pass the `SYM_ALL` control value to `setSymbology()`. `setEnableAllSymbologies()` is the master toggle. The SDK does not persist and replay your desired settings across devices or resets; read `details()` after connection and reapply an app policy when appropriate.

Other public groups include `barcode.symbology` for decoder flags and accepted lengths, `barcode.diagnostics` for engine queries, `barcode.images`, `barcode.imaging`, and `barcode.ocr`. The [generated Android API reference](../Documentation/Android/index.html) defines each signature and its prerequisites. A query of an inactive or older scan engine may fail; handle that as a query failure rather than assuming all devices support every command.

## Subscribing to events and telemetry

`events` is a `SharedFlow<SnapHaloEvent>` with no replay. The Android reference describes a 64-notification shared buffer that drops the oldest events for a slow subscriber. Subscribe before the adapter can connect, keep handlers short, and cancel collection with the owning scope. Each decoded barcode generates one `OnBarcodeScanned` event. Battery polling begins on connection and repeats every minute; `battery.telemetry` is the nullable cached value and `battery.getTelemetry()` requests a fresh value.

```kotlin
import android.util.Log
import com.ipcmobile.snapipcsdk.SnapHalo
import com.ipcmobile.snapipcsdk.events.SnapHaloEvent
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Job
import kotlinx.coroutines.flow.collect
import kotlinx.coroutines.launch

fun CoroutineScope.observeScanner(halo: SnapHalo): Job = launch {
    halo.events.collect { event ->
        when (event) {
            is SnapHaloEvent.OnBarcodeScanned ->
                Log.i("SnapHalo", "${event.barcode.symbology}: ${event.barcode.value}")
            is SnapHaloEvent.OnBatteryTelemetryChanged ->
                Log.i("SnapHalo", "Charge: ${event.telemetry.stateOfCharge}%")
            is SnapHaloEvent.OnFirmwareVersionChanged ->
                Log.i("SnapHalo", "Firmware: ${event.version}")
            is SnapHaloEvent.OnConnectionStatus ->
                Log.i("SnapHalo", "Connection: ${event.connectionState}")
            is SnapHaloEvent.OnSecurityWarning ->
                Log.w("SnapHalo", event.message)
            else -> Unit
        }
    }
}
```

`OnTriggerChanged` carries trigger press state. `OnConnectionStatus` carries the state, captured error message, authorization level, and verified hardware serial when available. Use the event payload for the value at notification time; consult `getConnectionState()` or cached battery telemetry for a current snapshot. Swift's `observeEvents` gives main-thread callbacks and a closeable subscription; the [iOS sample](../Samples/Swift/Sources/SnapIPCAppModel.swift) retains and closes it.

## Data serialization and timeouts

The public API returns typed `Barcode`, `BatteryTelemetry`, `DeviceDetails`, and other models. Nordic UART framing, packet endianness, raw ACKs, and response parsing are internal in this distribution; there is no public raw-frame injection method. `barcode.symbologyCode` is a Honeywell response code and differs from `ScannerSymbology` setting IDs. Preserve the typed distinction when storing scan data.

Catch `TimeoutCancellationException` before `CancellationException` for query timeouts. A setter failure can still be a transport/write exception, and transport loss can occur between a readiness check and a command. Report the failure and reconcile UI from a fresh query when the connection returns. See [troubleshooting](06-Troubleshooting-and-Error-Codes.md).

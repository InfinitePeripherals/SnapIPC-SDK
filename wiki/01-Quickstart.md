# Quickstart: from tap to Connected

## Fastest path: run a sample

Start with the [Android native quickstart](../Samples/Kotlin/README.md) if you have an NFC/BLE Android phone and scanner. The [React Native quickstart](../Samples/ReactNative/README.md) includes a separate Android bridge, and the [iOS native quickstart](../Samples/Swift/README.md) covers iPhone integration. Each sample includes its build, signing, permission, and verification steps.

| Android sample | Connection and UI path | Firmware shown in the sample |
| --- | --- | --- |
| [Kotlin / Compose](../Samples/Kotlin/README.md) | `SnapHaloAndroid` handles NFC and grants; `SnapIPCDemoController` collects SDK events and drives the UI | Displays `OnFirmwareVersionChanged` events; no upload screen |
| [React Native / Android](../Samples/ReactNative/README.md) | Native `SnapHaloAndroid` handles NFC; the bridge forwards events and **Ready to Pair** retries missing grants | Queries device and scan-engine versions after `Connected`; no upload screen |

## Prerequisites and installation

- Android: API **26+** device and the local Android 1.0.0 AAR, POM, and `.module` metadata in [`SDK/Android`](../SDK/Android/). The Kotlin sample uses compile/target SDK **37**, Gradle **9.6.1**, and a JDK **25** daemon. The React Native Android sample uses compile SDK **37**, target SDK **35**, Gradle **9.4.1**, and JDK **17**.
- iOS: iOS **15+** physical iPhone, Xcode, and the shipped [`SnapIPCSDK.xcframework`](../SDK/iOS/SnapIPCSDK.xcframework/Info.plist). 
- An IPCMobile SnapHalo scanner. Please contact sales@ipcmobile.com

For an Android project placed like `Samples/Kotlin`, configure the local Gradle publication in `settings.gradle.kts`:
```kotlin
dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
        ivy {
            url = uri("../../SDK/Android")
            patternLayout { artifact("[artifact]-[revision].[ext]") }
            metadataSources { gradleMetadata() }
            content { includeGroup("com.ipcmobile.snapipc") }
        }
        google()
        mavenCentral()
    }
}
```

Then add `implementation("com.ipcmobile.snapipc:snapipc-sdk-android:1.0.0")` to the app's dependencies. The adjacent Gradle metadata supplies the SDK's runtime dependencies. See the working Kotlin [`settings.gradle.kts`](../Samples/Kotlin/settings.gradle.kts) and [`app/build.gradle.kts`](../Samples/Kotlin/app/build.gradle.kts). The React Native sample resolves the same local publication through its [`android/build.gradle`](../Samples/ReactNative/android/build.gradle) and links it in [`android/app/build.gradle`](../Samples/ReactNative/android/app/build.gradle).

For iOS, add the local XCFramework to the app's Xcode target and select **Embed & Sign**, as the [Swift sample target](../Samples/Swift/project.yml) does. The framework includes scanner and firmware update APIs; no firmware Swift package is needed by the host app. Keep the XCFramework's device and simulator slices intact. See the [OTA guide](04-OTA-Updates.md) for `SnapHaloFirmwareUploader`.

## OS permissions and NFC routing

**Android:** The SDK AAR manifest declares `android.permission.NFC`, `BLUETOOTH_SCAN` and `BLUETOOTH_CONNECT`; legacy `BLUETOOTH`, `BLUETOOTH_ADMIN`, and `ACCESS_FINE_LOCATION` are capped at API 30. `SnapHaloAndroid` requests missing runtime grants and Bluetooth enablement. For cold-launch routing, put the launcher and `ipcstar://nfc` VIEW filters on the main Activity and the NDEF filters on a separate `activity-alias` with `android:permission="@string/snapipc_nfc_dispatch_permission"`, as both the [Kotlin](../Samples/Kotlin/app/src/main/AndroidManifest.xml) and [React Native](../Samples/ReactNative/android/app/src/main/AndroidManifest.xml) samples do. The AAR supplies that string: it is empty below API 37 and names `android.permission.DISPATCH_NFC_MESSAGE` on API 37+. Foreground reader mode works while the Activity is visible. Enable NFC and Bluetooth on the phone.

**iOS:** Set `NFCReaderUsageDescription` and `NSBluetoothAlwaysUsageDescription` in Info.plist; the samples also carry `NSBluetoothPeripheralUsageDescription` for older behavior. Configure the **NFC Tag Reading** capability and TAG/NDEF entitlement. Add `bluetooth-central` to `UIBackgroundModes` only if your host needs the sample's background behavior. See the [Swift target settings](../Samples/Swift/project.yml) and [entitlements](../Samples/Swift/SnapIPCNative.entitlements). Call `startPairing(onError:)` on the main thread from the user flow.

## Hello SnapHalo: Android Sample

This is an illustrative Activity-level integration using the same SDK entry points as the [Kotlin sample](../Samples/Kotlin/README.md). That sample keeps its event and command logic in `SnapIPCDemoController`, and receives firmware version events rather than running the explicit `getFirmware()` query shown below. `SnapHaloAndroid` starts NFC reader mode, handles the tap, discovers the scanner, and connects; the host does not parse the tag or call a public `connect` function.

```kotlin
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.lifecycle.lifecycleScope
import com.ipcmobile.snapipcsdk.SnapHalo
import com.ipcmobile.snapipcsdk.android.SnapHaloAndroid
import com.ipcmobile.snapipcsdk.events.SnapHaloEvent
import com.ipcmobile.snapipcsdk.models.ConnectionState
import kotlinx.coroutines.CancellationException
import kotlinx.coroutines.CoroutineStart
import kotlinx.coroutines.Job
import kotlinx.coroutines.TimeoutCancellationException
import kotlinx.coroutines.flow.collect
import kotlinx.coroutines.launch

class MainActivity : ComponentActivity() {
    private val halo = SnapHalo()
    private lateinit var adapter: SnapHaloAndroid
    private lateinit var eventsJob: Job

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        // The event flow has no replay: subscribe before the adapter can connect.
        eventsJob = lifecycleScope.launch(start = CoroutineStart.UNDISPATCHED) {
            halo.events.collect { event ->
                when (event) {
                    is SnapHaloEvent.OnConnectionStatus -> {
                        Log.i("SnapHalo", "State: ${event.connectionState}")
                        event.errorMessage?.let { Log.e("SnapHalo", it) }
                        if (event.connectionState == ConnectionState.Connected) readSnapshot()
                    }
                    is SnapHaloEvent.OnBarcodeScanned ->
                        Log.i("SnapHalo", "Barcode: ${event.barcode.value}")
                    is SnapHaloEvent.OnBatteryTelemetryChanged ->
                        Log.i("SnapHalo", "Charge: ${event.telemetry.stateOfCharge}%")
                    else -> Unit
                }
            }
        }
        adapter = SnapHaloAndroid(this, halo) { message ->
            Toast.makeText(this, message, Toast.LENGTH_LONG).show()
        }
        // Keep this Activity visible and tap the scanner's NFC pairing point.
    }

    private fun readSnapshot() {
        lifecycleScope.launch {
            try {
                val details = halo.details()
                val model = halo.getModel()
                val firmware = halo.getFirmware()
                val battery = halo.battery.getTelemetry()
                Log.i("SnapHalo", "$model / $firmware / mode=${details.scanWorkMode} / battery=$battery")
            } catch (timeout: TimeoutCancellationException) {
                Log.e("SnapHalo", "Device query timed out", timeout)
            } catch (cancelled: CancellationException) {
                throw cancelled
            } catch (failure: Exception) {
                Log.e("SnapHalo", "Device query failed", failure)
            }
        }
    }

    override fun onDestroy() {
        adapter.close()
        eventsJob.cancel()
        halo.close()
        super.onDestroy()
    }
}
```

The Activity still needs the manifest routing and SDK dependency above. A successful tap produces `OnConnectionStatus(Connected)`, then typed query results and barcode/battery events. The React Native Android sample uses the same adapter; its **Ready to Pair** action calls `requestPermissions()` for an explicit permission retry, while a new NFC tap supplies the scanner identity. Use the [pairing guide](02-Pairing-and-Connection.md) before adding retry logic or a custom UI.

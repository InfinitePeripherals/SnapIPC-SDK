# SnapIPC Android: NFC pairing and barcode scanning

This Jetpack Compose sample uses the SnapHalo client from the **SnapIPC Android SDK 1.0.0**. Tap a scanner's NFC tag to establish its BLE session, then read barcodes, battery telemetry, firmware, scan mode, and enabled symbologies. The SDK handles NFC parsing and BLE connection internally.

## Prerequisites and hardware

- Android Studio with Android SDK **37**, or the included Gradle **9.6.1** wrapper and an Android SDK installation. The project targets API 37 and runs on API **26+**. Its Gradle daemon toolchain is configured for **JDK 25** in `gradle/gradle-daemon-jvm.properties`.
- A physical Android phone with NFC and BLE, an IPCMobile SnapHalo scanner with its pairing tag, and a USB connection or Android wireless debugging. An emulator can display the UI but cannot verify the NFC/BLE hardware flow.
- The SDK distribution at `../../SDK/Android/` with its AAR, POM, and `.module` metadata. This checkout provides no required minimum scanner firmware version; read the reported version after connection and validate against your hardware release plan.

## Configuration and permissions

1. Open this directory in Android Studio, or set `ANDROID_HOME` (or `sdk.dir` in ignored `local.properties`) for CLI builds. Install Android SDK 37. `settings.gradle.kts` resolves `com.ipcmobile.snapipc:snapipc-sdk-android:1.0.0` from `../../SDK/Android`; keep that relative layout.
2. `app/build.gradle.kts` sets application ID `com.ipcmobile.snapipc.androidnative`. Change it there if your deployment requires a different ID. Debug builds use the Android debug signing setup; configure release signing for your own distribution.
3. The SDK AAR contributes `NFC`, `BLUETOOTH_SCAN`, `BLUETOOTH_CONNECT`, legacy Bluetooth permissions, and `ACCESS_FINE_LOCATION` through API 30. [`AndroidManifest.xml`](app/src/main/AndroidManifest.xml) keeps the launcher and `ipcstar://nfc` VIEW filter on `MainActivity`, with NDEF filters on a separate `SnapIPCNfcEntry` alias. The alias uses the AAR's `@string/snapipc_nfc_dispatch_permission` resource, which names `android.permission.DISPATCH_NFC_MESSAGE` on API 37+. Grant Bluetooth and, on older Android, Location when prompted; enable Bluetooth and NFC in device settings. The SDK's `SnapHaloAndroid` adapter requests missing runtime grants.

## Build and run

From this directory on macOS/Linux:

```sh
./gradlew :app:assembleDebug
adb install -r app/build/outputs/apk/debug/app-debug.apk
adb shell am start -n com.ipcmobile.snapipc.androidnative/.MainActivity
```

On Windows, use `gradlew.bat :app:assembleDebug`; install and launch the same APK with `adb`. Android Studio's **Run** action also builds and deploys the `app` target. First dependency resolution can take longer than a normal incremental build.

## Code walkthrough

| Integration point | Source |
| --- | --- |
| Creates one `SnapHaloAndroid` after `super.onCreate`, attaches it to the controller's `SnapHalo`, and closes both on destruction | [`MainActivity.kt`](app/src/main/kotlin/com/ipcmobile/snapipc/androidnative/MainActivity.kt) |
| Initializes `SnapHalo()`, collects `snapHalo.events`, handles connection/barcode/battery/firmware events, calls `details()`, and sends scan/mode/symbology commands | [`SnapIPCDemoController.kt`](app/src/main/kotlin/com/ipcmobile/snapipc/androidnative/SnapIPCDemoController.kt) |
| Renders the state and routes Start/Stop Scan, scan mode, symbology, and Disconnect controls | [`SnapIPCDemoApp.kt`](app/src/main/kotlin/com/ipcmobile/snapipc/androidnative/SnapIPCDemoApp.kt) |
| Separates launcher/VIEW routing from permission-protected NFC dispatch; the AAR supplies the BLE/NFC permissions and alias permission resource | [`AndroidManifest.xml`](app/src/main/AndroidManifest.xml) |

`SnapHaloAndroid` handles the NFC tap and connects automatically after required grants. There is no host call to inject raw OOB credentials or a public `connect` call.

## Expected output and checks

On launch, the screen says **Awaiting NFC pairing**. Tap the scanner tag and grant requested permissions; the status progresses through finding and preparing the scanner to **Connected**. Battery telemetry and firmware version events appear when emitted by the SDK, and a successful scan displays its value, symbology, count, and time. **Start Scan**, mode, and symbology controls become available once connected. This sample does not call `getFirmware()` on connection.

- If a tap does nothing, confirm NFC is enabled and hold the phone at the scanner's pairing point. Foreground reader mode works while this Activity is visible; the manifest filters support dispatch when it is not.
- If pairing stops at a permission or connection error, enable Bluetooth, grant the requested Bluetooth/legacy Location permission in Android settings, and tap again. The adapter reports permission and NFC errors through its `onError` callback; transport errors arrive in `OnConnectionStatus.errorMessage`.

See the [quickstart](../../wiki/01-Quickstart.md) and [pairing lifecycle](../../wiki/02-Pairing-and-Connection.md) for the public SDK integration path.

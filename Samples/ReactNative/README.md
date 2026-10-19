# SnapIPC React Native: shared scanner UI with native SDK bridges

This React Native **0.87** sample uses TypeScript for the scanner UI and native Kotlin/Swift bridges for SnapIPC Android SDK **1.0.0** and iOS SDK **1.0.0**. It covers NFC-led BLE pairing, connection status, battery and firmware, barcode events, scan controls, modes, symbologies, and disconnect on Android and iOS.

## Prerequisites and hardware

- Node.js **22.11+** and npm. For Android: Android SDK **37**, the included Gradle **9.4.1** wrapper, and JDK **17**; the app runs on API **26+**. For iOS: macOS, Xcode, CocoaPods/Bundler, and iOS **15.1+** as set in the Xcode project.
- A physical NFC- and BLE-capable Android phone or iPhone plus an IPCMobile SnapHalo scanner and pairing tag. Simulators/emulators can render the UI but cannot verify the NFC/BLE pairing flow.
- The local artifacts at `../../SDK/Android` and `../../SDK/iOS`. The distribution supplies no minimum scanner firmware version; record the versions shown by the app for your hardware release plan.

## Build compatibility

Android uses minimum SDK 26, target SDK 35, compile SDK 37, NDK 27.0.12077973, Java 17 bytecode, Kotlin 2.4.0, and Gradle 9.4.1. MultiDex is enabled. Release builds use R8 with `android/app/proguard-rules.pro`. iOS targets 15.1 and uses Hermes.

The Android SDK 1.0.0 AAR declares `minCompileSdk=35` and carries Kotlin 2.1 metadata. This React Native 0.87 sample still uses its own Android Gradle plugin 9.2.1, Gradle 9.4.1, Kotlin 2.4.0, and compile SDK 37. Those are host app build choices; the SDK can also be consumed by an Android app using compile SDK 35 and Kotlin 2.1.20.

## Configuration and permissions

1. Keep the relative SDK paths. [`android/build.gradle`](android/build.gradle) resolves the AAR and Gradle metadata from `../../SDK/Android`; the iOS Xcode project links, embeds, and signs `../../SDK/iOS/SnapIPCSDK.xcframework`.
2. For Android CLI use, set `ANDROID_HOME` or `sdk.dir` in ignored `android/local.properties`. The application ID is `com.ipcmobile.snapipc.reactnative` in [`android/app/build.gradle`](android/app/build.gradle). Its debug keystore is configured there; configure your own release signing for distribution.
3. The Android SDK AAR contributes NFC/BLE permissions, including runtime `BLUETOOTH_SCAN` and `BLUETOOTH_CONNECT` and legacy Location through API 30. The host [`AndroidManifest.xml`](android/app/src/main/AndroidManifest.xml) keeps launcher/`ipcstar://nfc` VIEW routing on `MainActivity` and places NDEF filters on a `SnapIPCNfcEntry` alias. The alias uses the AAR's `@string/snapipc_nfc_dispatch_permission`, which names `android.permission.DISPATCH_NFC_MESSAGE` on API 37+. Grant requested Bluetooth/legacy Location access and enable NFC and Bluetooth.
4. On iOS, open `ios/SnapIPCReactNative.xcworkspace`, select a signing team, and provision the bundle ID `com.ipcmobile.snapipc.reactnative` with **NFC Tag Reading**. [`Info.plist`](ios/SnapIPCReactNative/Info.plist) declares Bluetooth/NFC usage descriptions and `bluetooth-central`; [`SnapIPCReactNative.entitlements`](ios/SnapIPCReactNative/SnapIPCReactNative.entitlements) declares NFC TAG/NDEF formats.

## Build and run

From this directory:

```sh
npm ci
npm start
```

In a second terminal in this directory, deploy to a connected Android device:

```sh
npm run android
```

For iOS, install pods once, then open the workspace in Xcode and run the signed app on a physical iPhone:

```sh
cd ios
bundle install
bundle exec pod install
open SnapIPCReactNative.xcworkspace
```

Keep Metro (`npm start`) running for a debug build. Initial dependency and pod installation may take longer than subsequent launches. `npm run ios` is also available for a simulator UI build, but hardware pairing requires a physical iPhone.

## Code walkthrough

| Integration point | Source |
| --- | --- |
| Builds the shared screen and routes **Ready to Pair**, scan, mode, symbology, and disconnect actions | [`src/SnapIPCApp.tsx`](src/SnapIPCApp.tsx) |
| Defines the native Promise/event contract, subscribes to `SnapIPCEvent`, maintains connection/telemetry/scan state, and surfaces errors | [`src/snapipc.ts`](src/snapipc.ts) |
| Creates `SnapHaloAndroid` for NFC/permissions and connects it to the shared `SnapHalo`; **Ready to Pair** calls `requestPermissions()` for an explicit retry | [`MainActivity.kt`](android/app/src/main/java/com/ipcmobile/snapipc/reactnative/MainActivity.kt), [`SnapIPCSession.kt`](android/app/src/main/java/com/ipcmobile/snapipc/reactnative/SnapIPCSession.kt), [`SnapIPCModule.kt`](android/app/src/main/java/com/ipcmobile/snapipc/reactnative/SnapIPCModule.kt) |
| Converts Android SDK events and commands to the JS bridge | [`SnapIPCModule.kt`](android/app/src/main/java/com/ipcmobile/snapipc/reactnative/SnapIPCModule.kt) |
| Creates `SnapHalo()`, calls `startPairing(onError:)`, and maps iOS events/commands to the JS bridge | [`SnapIPCModule.swift`](ios/SnapIPCReactNative/SnapIPCModule.swift) |

The TypeScript event payloads are sample bridge data. They are not the SDK's BLE or NFC wire format.

On Android, **Ready to Pair** requests missing permissions through the adapter; a scanner is selected by the next NFC tap. The bridge queries `details()`, device firmware, and scanner firmware after `Connected`. Its manifest's NFC alias protects cold dispatch while leaving launcher and deep links on the main Activity.

The iOS XCFramework includes `SnapHaloFirmwareUploader`, but this sample's JavaScript bridge does not expose firmware upload. The [native Swift sample](../Swift/README.md) demonstrates the public iOS updater.

## Expected output and checks

The screen begins with **Awaiting NFC pairing**. After a valid tap and system grants, it displays **Connected**, battery, and firmware. **Start Scan** enables scanning; a decoded barcode appears with its value, symbology, count, and time. The menu exposes mode, symbology, and **Disconnect & Unpair**.

- If the screen says the native module is unavailable, rebuild the native app after `npm ci` and, on iOS, `bundle exec pod install`. A Metro reload alone cannot add a native module.
- If pairing does not advance, check NFC/Bluetooth and grants on the device, then tap again. Android permission/NFC failures appear through the adapter; iOS NFC failures and transport errors appear in the app's error text.

See the [quickstart](../../wiki/01-Quickstart.md) and [pairing lifecycle](../../wiki/02-Pairing-and-Connection.md).

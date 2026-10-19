# SnapIPC SDK Wiki state

Phases 1–4 completed on 2026-10-17 after the user approved the proposed defaults. On 2026-10-18, the iOS distribution was updated to an XCFramework that embeds the public firmware uploader, and the wiki's Android sample descriptions were reconciled with the Kotlin and React Native code. This checkout is a distribution snapshot: `SDK/Android/snapipc-sdk-android-1.0.0.aar`, `SDK/iOS/SnapIPCSDK.xcframework`, generated API pages in `Documentation/`, and three samples. It has no SDK source tree or repository-root Gradle wrapper. The published artifacts and docs use **SnapIPC SDK** as the distribution name and `SnapHalo` as the client type.

## Source truth and scope

- Public API: `Documentation/Android/` and `Documentation/iOS/` Dokka references for version 1.0.0; cross-checked against sample calls. The Android AAR manifest and iOS framework are present. The embedded Swift-only firmware API is visible in the XCFramework's public `SnapIPCSDK.swiftinterface`; the Kotlin-generated iOS Dokka reference does not list that Swift declaration.
- Samples: `Samples/Kotlin/`, `Samples/Swift/`, and `Samples/ReactNative/`. Dependency, IDE, vendor, and generated build directories are not separate sample projects.
- No root `src/`, `docs/`, `gradlew`, architecture specification, firmware bundle, GATT schema, or NFC payload specification is present.

## Extracted API Surface

The list below records the public integration surface relevant to the requested guides. The generated Dokka references contain 541 Android and 516 iOS declaration entries, including model properties and enum constants. Consult those references for exhaustive signatures; do not infer wire protocol from them.

### Connection and pairing

- `com.ipcmobile.snapipcsdk.SnapHalo`: constructor; `events: SharedFlow<SnapHaloEvent>` (no replay); `observeEvents`, `getConnectionState`, `connectedPeripheralIdentifier`, `authLevel`, `hardwareSerial`, `cancelPendingConnection`, `disconnect`, `close`, `dispose`. `startPairing(onError)` is the iOS NFC entry point. `connect` is internal.
- Android-only `com.ipcmobile.snapipcsdk.android.SnapHaloAndroid`: Activity-bound constructors; `handleIntent`, `missingPermissions`, `requestPermissions`, `cancelPendingConnection`, `close`. It owns NFC intent/reader-mode and runtime-permission integration; all public calls are main-thread calls.
- `ConnectionState`: `WaitingForNfc`, `RequestingBluetooth`, `Scanning`, `Connecting`, `DiscoveringServices`, `Connected`, `Reconnecting`, `Error`. `AuthLevel`: `Locked`, `Tapped`, `Operational`.
- `SnapHaloEvent.OnConnectionStatus` carries `connectionState`, `errorMessage`, `authLevel`, and `hardwareSerial`; `OnSecurityWarning` carries `message`.
- The Android AAR manifest declares NFC, BLE, `BLUETOOTH_SCAN`, `BLUETOOTH_CONNECT`, and legacy Bluetooth/location permissions capped at API 30. Its resources supply `snapipc_nfc_dispatch_permission`: empty below API 37 and `android.permission.DISPATCH_NFC_MESSAGE` on API 37+. Both Android samples put launcher/VIEW filters on the main Activity and NDEF filters on a permission-protected Activity alias. The iOS sample manifests supply NFC and Bluetooth usage descriptions and `bluetooth-central` background mode.

### Telemetry and commands

- `SnapHalo` exposes `barcode: IBarcodeReader`, `battery: IBattery`, and `light: ILight`; it also implements `IDevice`.
- `IDevice`: `details`, `getFirmware`, `getModel`, `getConnectionState`, `readRssi`, `rssi`, `beepBuzzer`, `playBuzzerTones`, `setIdleTimeout`, `setPowerOffTimeout`, `setChannelSounding`, `powerOff`, `clearBleBonding`, `disconnect`.
- `IBarcodeReader`: `startScan`, `stopScan`, `getScanMode`, `setScanMode`, `getSymobologies` (published spelling), `setSymbology`, `setEnableAllSymbologies`, `setContinuousScanInterval`, `setScanEnginePower`, `setBeepOnScan`, `setVibrateOnScan`, `setCenteringMode`, `setOcrModeTemplate`, `getFirmware`, `isTriggerPressed`; `symbology`, `diagnostics`, `images`, `imaging`, and `ocr` subinterfaces.
- `IBattery`: `telemetry` cached value, `getTelemetry` query. `ILight`: `setColor`, `setDecodeAimer`, `setDecodeLight`.
- Additional public subinterfaces: `ISymbology` (`read`, `update`, `setFlags`, `setLengthRange`, `setRedundancy`, `resetToDefaults`, `lengthLimits`, `redundancy`); `IDiagnostics` (`describeError`, `engineId`, `engineType`, `imagerProperties`, `isHsmAvailable`, `lastDecodeTimeMs`, `maxMessageChars`, `revision`); `IImages` (`lastImage`, `lastImageInfo`); `IImaging` (exposure, lights, centering, decode options and scanning settings); `IOcr` (`settings`, `userTemplate`, `setUserTemplate`).
- Events: `OnBarcodeScanned`, `OnBatteryTelemetryChanged`, `OnFirmwareVersionChanged`, `OnTriggerChanged`, plus the connection and security events above. Core data models include `Barcode`, `BatteryTelemetry`, `DeviceDetails`, `BarcodeScanMode`, `ScannerSymbology`, `ScannerImage`, and `SymbologyConfig`.
- Published Android guide says setters finish on BLE write, not firmware acknowledgement; queries return typed replies and may time out. Raw command injection and framing are internal.

### OTA firmware updates

- Android: `SnapHaloAndroid.uploadFirmware(uri: Uri, onStatus: (FirmwareUploadStatus) -> Unit)` and `cancelFirmwareUpload()`.
- Android `FirmwareUploadStatus`: `Reading`, `Validating`, `Uploading(percent)`, `Applying`, `Rebooting`, `Confirming`, `Completed`, `Canceled`, `Failed(message)`.
- iOS XCFramework: `SnapHaloFirmwareUploader(onStatus:)`, `upload(fileURL:peripheralIdentifier:)`, and `cancel()` in the `SnapIPCSDK` Swift module. `SnapHaloFirmwareUploadStatus` reports the corresponding Swift cases. The host passes a UUID parsed from `SnapHalo.connectedPeripheralIdentifier`.
- Both accept an approved, signed firmware image; neither public surface exposes signing keys or host EAK authorization. The Swift sample now demonstrates the embedded iOS uploader.

### Error handling

- No public SDK error enum or numeric SDK error-code table is present in either generated API package list. Available surfaces are `SnapHaloAndroid.onError(String)`, iOS `startPairing(onError:)`, `OnConnectionStatus.errorMessage`, `OnSecurityWarning.message`, Android `FirmwareUploadStatus.Failed(message)`, iOS `SnapHaloFirmwareUploadStatus.failed(String)` and thrown startup errors, and exceptions from suspending/async commands. `IDiagnostics.describeError(Int)` concerns scan-engine diagnostics; its integer space is not documented as a general SDK error enum.
- React Native bridge rejection strings such as `SNAPIPC_ERROR`, `NO_ACTIVITY`, `PAIRING_FAILED`, and `INVALID_SYMBOLOGY` belong to that sample bridge, not the SDK.

## Discovered Samples Inventory

- [x] Completed — `Samples/Kotlin/README.md`. Android / Kotlin / Jetpack Compose, API 26 minimum, compile and target SDK 37. Demonstrates NFC-led BLE connection through `SnapHaloAndroid`, connection events, barcode commands/events, battery telemetry, firmware version events, modes, symbology and disconnect. It does not call `getFirmware()` on connection. Build: `Samples/Kotlin/gradlew`, `settings.gradle.kts`, `app/build.gradle.kts`; entry `app/src/main/kotlin/com/ipcmobile/snapipc/androidnative/MainActivity.kt`; logic in `SnapIPCDemoController.kt`. Its manifest separates launcher/VIEW and NFC alias filters; BLE/NFC permissions and the alias permission resource come from the AAR.
- [x] Completed — `Samples/Swift/README.md`. iOS 15+ / SwiftUI. Demonstrates iOS `startPairing`, connection and barcode events, battery, firmware query and upload, modes, symbology and disconnect. `build.sh` generates an Xcode project against the shipped XCFramework. `project.yml` embeds the dynamic XCFramework and specifies NFC/Bluetooth keys and `bluetooth-central`; `SnapIPCNative.entitlements` declares NFC TAG/NDEF formats.
- [x] Completed — `Samples/ReactNative/README.md`. React Native 0.87 / TypeScript with Android Kotlin and iOS Swift bridges. Demonstrates the scanner flow on both platforms. Its Android bridge uses `requestPermissions()` for the **Ready to Pair** retry and queries device/scanner firmware after `Connected`; the next NFC tap supplies identity. `package.json`, Android Gradle files, iOS Podfile and Xcode project are present. JS entry `src/SnapIPCApp.tsx`; state/bridge contract `src/snapipc.ts`; native bridge files `android/app/src/main/java/com/ipcmobile/snapipc/reactnative/SnapIPCModule.kt` and `ios/SnapIPCReactNative/SnapIPCModule.swift`. The AAR provides Android BLE/NFC permissions and the NFC alias permission resource; the host manifest separates launcher/VIEW and NFC dispatch filters. iOS Info.plist and entitlements declare NFC/Bluetooth settings.

## Wiki Checklist

- [x] Completed — `wiki/Home.md`
- [x] Completed — `wiki/01-Quickstart.md`
- [x] Completed — `wiki/02-Pairing-and-Connection.md`
- [x] Completed — `wiki/03-Core-SDK-Usage.md`
- [x] Completed — `wiki/04-OTA-Updates.md`
- [x] Completed — `wiki/05-Best-Practices.md`
- [x] Completed — `wiki/06-Troubleshooting-and-Error-Codes.md`
- [x] Completed — `wiki/_Sidebar.md`
- [x] Completed — Phase 4 relative-link and placeholder verification

## 🛑 Blocked / Pending Human Input

None.

## Resolved Decisions

On 2026-10-17, the user approved all five proposed defaults:

1. Document the shipped version 1.0.0 distribution; use SnapHalo for the client/API name and SnapIPC for artifact names.
2. Describe public host integration for NFC/BLE and state where protocol and processor internals are unavailable.
3. Originally cover Android OTA through the published API and status flow only. On 2026-10-18, the updated iOS XCFramework added the public Swift uploader; cover that public API and status flow as well. Do not assert a signing procedure, recovery mechanism, or minimum firmware version.
4. Use XcodeGen with the shipped XCFramework for the standalone Swift quickstart; repair the sample build script accordingly.
5. Provide a table of documented error surfaces/states and recovery actions, with sample bridge codes identified separately.

## Verification

- All 12 required Markdown files exist: nine wiki files (including this state file) and three sample quickstarts. Local Markdown links resolve, with no unfinished placeholder text.
- The Android sample audit compared both manifests, their Activity/bridge entry points, and Gradle settings with the wiki. The shipped AAR contains `snapipc_nfc_dispatch_permission` in its base and API 37 resource values.
- `Samples/Swift/build.sh` passes `sh -n`; its XcodeGen + simulator build succeeded against the updated XCFramework on 2026-10-18 with the embedded uploader used by the sample. An initial sandboxed Xcode invocation could not reach macOS simulator/macro services; the build succeeded when run with those services available.
- `Samples/Kotlin/gradlew :app:assembleDebug --offline` succeeded.
- `Samples/ReactNative/android/gradlew :app:assembleDebug --offline` succeeded.
- `Samples/ReactNative` iOS workspace built for the simulator with `xcodebuild` and code signing disabled, including a 2026-10-18 build against the updated XCFramework.
- NFC/BLE pairing and OTA behavior require physical devices and an approved firmware image; those hardware paths were not exercised here.

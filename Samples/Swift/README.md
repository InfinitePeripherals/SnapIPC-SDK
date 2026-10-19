# SnapIPC iOS: pairing, scanning, and firmware updates

This SwiftUI sample uses `SnapHalo` and `SnapHaloFirmwareUploader` from the shipped **SnapIPC iOS SDK 1.0.0** XCFramework. It opens the SDK's NFC pairing sheet, connects to a scanner over BLE, and presents barcode events, battery telemetry, firmware versions, scan modes, symbology settings, and firmware upload.

## Prerequisites and hardware

- macOS with Xcode, the Xcode command-line tools, and XcodeGen available as `xcodegen` or at `$HOME/.local/bin/xcodegen`. [`project.yml`](project.yml) sets iOS **15.0** and Swift **5.0**.
- A physical NFC- and BLE-capable iPhone and an IPCMobile SnapHalo device. The simulator build checks compilation and UI only; it cannot complete NFC/BLE pairing.
- `../../SDK/iOS/SnapIPCSDK.xcframework` in the supplied layout. This distribution specifies no minimum scanner firmware version; verify the reported firmware for your deployment.
- An approved signed firmware `.bin` image or ZIP containing one to exercise firmware upload on a physical device.

## Configuration and permissions

1. Keep the XCFramework at the path referenced by `project.yml`. Its `SnapIPCNative` target embeds the framework and sets bundle ID `com.ipcmobile.snapipc.native`.
2. For a physical iPhone, generate the project, open it in Xcode, select **SnapIPCNative → Signing & Capabilities**, choose a team, and use an available bundle ID if needed. Provision that App ID with **NFC Tag Reading**.
3. `project.yml` generates `NFCReaderUsageDescription`, `NSBluetoothAlwaysUsageDescription`, `NSBluetoothPeripheralUsageDescription`, and `UIBackgroundModes = bluetooth-central`. [`SnapIPCNative.entitlements`](SnapIPCNative.entitlements) declares NFC `TAG` and `NDEF` formats. Accept the iOS Bluetooth/NFC prompts on the phone.

## Build and run

From this directory, generate the project and compile its simulator target:

```sh
./build.sh
```

The script uses the shipped XCFramework, runs `xcodegen generate --spec project.yml`, then builds `SnapIPCNative` with `xcodebuild`. To exercise pairing or firmware upload, open `SnapIPCNative.xcodeproj` in Xcode, select your signed physical iPhone, and press **Run**. If XcodeGen is elsewhere, set `XCODEGEN` to its executable path before running the script.

## Code walkthrough

| Integration point | Source |
| --- | --- |
| Initializes `SnapHalo()`, retains the `observeEvents` subscription, opens NFC with `startPairing(onError:)`, and closes the subscription/client | [`SnapIPCAppModel.swift`](Sources/SnapIPCAppModel.swift) |
| Handles connection, barcode, battery, and firmware events; queries `details()`, `getFirmware()`, and `barcode.getFirmware()`; sends scan/mode/symbology commands with `async/await` | [`SnapIPCAppModel.swift`](Sources/SnapIPCAppModel.swift) |
| Retains `SnapHaloFirmwareUploader`, passes the connected scanner UUID, handles progress and cancellation | [`SnapIPCAppModel.swift`](Sources/SnapIPCAppModel.swift) |
| Starts pairing after the splash screen or through **Ready to Pair** and displays status, telemetry, scan, and settings views | [`SnapIPCNativeApp.swift`](Sources/SnapIPCNativeApp.swift) |
| Presents the firmware file picker and **Update firmware** action under Menu | [`SnapIPCNativeApp.swift`](Sources/SnapIPCNativeApp.swift) |
| Declares the target, XCFramework link, Info.plist keys, and entitlements path | [`project.yml`](project.yml) |

The SDK owns NFC record parsing and BLE connection. The app invokes its pairing entry point and reacts to typed events.

`SnapHaloFirmwareUploader` is in the same `SnapIPCSDK` module as the scanner client; no firmware package is needed. The sample retains it in the app model and calls `upload(fileURL:peripheralIdentifier:)` on the main thread after a scanner connects. Status callbacks drive the UI and `cancel()` stops an active upload.

## Expected output and checks

After the splash screen, the iOS NFC sheet appears. Tap the scanner's pairing point. The view advances from **Awaiting NFC pairing** to **Connected**, shows battery and firmware, and enables **Start Scan**. A valid barcode appears with its value, symbology, and timestamp.

To update firmware on a physical device, open **Menu → Update firmware…** after connecting and select an approved image from Files. The UI reports upload phases and percentage, with **Cancel upload** during transfer. Keep the app and scanner powered and in range until a terminal result, then reconnect if necessary and query firmware. See [OTA firmware updates](../../wiki/04-OTA-Updates.md) for image limits and the public API.

- If Xcode cannot sign the app, select a valid team and NFC-capable App ID in **Signing & Capabilities**. A simulator build needs no signing but cannot verify pairing.
- If the NFC sheet closes without connecting, retry **Ready to Pair** with the phone held at the tag and inspect the on-screen error from `startPairing(onError:)` or the connection event. Bluetooth must be enabled.

See the [quickstart](../../wiki/01-Quickstart.md) and [pairing lifecycle](../../wiki/02-Pairing-and-Connection.md).

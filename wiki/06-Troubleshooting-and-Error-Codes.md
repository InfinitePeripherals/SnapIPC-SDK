# Troubleshooting and error surfaces

The shipped 1.0.0 Android and iOS references publish **no general SDK error enum or numeric SDK error-code list**. The table below covers documented public failure surfaces used by connection, commands, telemetry, and both firmware uploaders. Match behavior by surface and message; do not parse an undocumented numeric code from an exception string.

| Public surface | Likely cause or meaning | Programmatic recovery |
| --- | --- | --- |
| `SnapHaloAndroid.onError(message)` | Android NFC read, missing/denied permission, disabled Bluetooth, or pairing readiness problem | Show the message; call `missingPermissions()` for permission UI, enable Bluetooth/NFC as appropriate, then allow another tap or explicit `requestPermissions()` retry. |
| iOS `startPairing(onError:)` message | NFC or connection failure reported by the pairing session | Show the message, keep the client alive, and allow the user to invoke `startPairing` again from the main thread. Dismissing the NFC sheet is not reported as an error. |
| `OnConnectionStatus` with `ConnectionState.Error` and `errorMessage` | Discovery/connection timeout, service discovery, authentication, MTU, or link failure | Store/display the captured message. Stop dependent commands and request a new NFC tap after hardware and grants are ready. |
| `OnConnectionStatus` with `Reconnecting` | Unexpected loss of an established BLE link | Pause commands and wait for `Connected` or `Error`; the SDK already retries. |
| `OnSecurityWarning.message` | Optional hardware attestation was unavailable | Present a security diagnostic according to product policy; do not assume it is a transport disconnect. |
| `TimeoutCancellationException` from a suspending query | No typed device reply before the SDK's fixed three-second query timeout | Preserve coroutine cancellation semantics, show a timeout, and retry the query only after checking `Connected`. |
| Other exception from a command or query | BLE write failure, disconnection during the call, unsupported engine/firmware behavior, or invalid response | Log the exception class/message without credentials, reconcile connection state, then retry only the user action or readback that is safe for your workflow. |
| `FirmwareUploadStatus.Failed(message)` (Android) or `SnapHaloFirmwareUploadStatus.failed(String)` (iOS) | Image validation, transfer, reboot, confirmation, or active-image verification failed | Stop update UI, record the message/status sequence, reconnect or retap if necessary, and query firmware before considering a retry with an approved image. |
| `FirmwareUploadStatus.Canceled` (Android) or `SnapHaloFirmwareUploadStatus.canceled` (iOS) | Upload canceled during transfer; closing the Android adapter also cancels its upload | Return to file selection only after the terminal status; confirm the scanner's current firmware before starting another update. |
| Thrown error from iOS `SnapHaloFirmwareUploader.upload` | File, package, image, main-thread, or setup problem before transfer | Show the localized error, check the selected signed image and connected scanner UUID, then allow another selection. |
| `IDiagnostics.describeError(code)` result | Scan-engine diagnostic description for a supplied engine code | Use for scanner diagnostic UI. The SDK reference does not define these codes as general connection or firmware update errors. |

`ConnectionState` includes `WaitingForNfc`, `RequestingBluetooth`, `Scanning`, `Connecting`, `DiscoveringServices`, `Connected`, `Reconnecting`, and `Error`; only `Error` is a terminal failure state in that enum. Android scanning and initial connection each have a documented 20-second timeout. Query timeouts are separate.

## Common integration pitfalls

### Android GATT status 133 or stale cache

GATT 133 is an Android/BLE stack symptom, not a SnapHalo SDK error code. Capture the `OnConnectionStatus.errorMessage` and phone/OS/scanner firmware. Let the SDK's `Reconnecting` phase finish; on `Error`, ask the user to move the scanner nearby and tap again. If a device was recently reset or changed firmware, an explicit disconnect and fresh tap can establish a new session. There is no public SDK GATT-cache-clear API; avoid hidden Android cache methods. Use normal OS Bluetooth settings for a known stale bond, and reserve `clearBleBonding()` for an explicit scanner bond reset procedure.

### NFC tag read timeout or no dispatch

Verify NFC is on, hold the phone at the scanner's pairing point, and retry. Android foreground reader mode works with a visible `SnapHaloAndroid` Activity. For cold launch, check that the launcher/VIEW filters remain on the main Activity and the NDEF filters are on a separate alias with the AAR's `@string/snapipc_nfc_dispatch_permission`; compare the [Kotlin](../Samples/Kotlin/app/src/main/AndroidManifest.xml) and [React Native](../Samples/ReactNative/android/app/src/main/AndroidManifest.xml) manifests. The alias matters when targeting API 37; placing its NFC dispatch permission on the launcher Activity can block ordinary launches. If a legacy tag carries an Android Application Record for another package, that record may route a cold tap elsewhere; foreground reader mode is unaffected. iOS must have NFC usage text and the TAG/NDEF entitlement, then invoke `startPairing(onError:)` from the main-thread user flow. A canceled iOS sheet is not an SDK error.

### Connected but a command appears ignored

Setters report successful BLE writes, not firmware ACKs. Query `details()` or the relevant typed getter to read what the scanner actually applied. Older firmware may not support every scanner-engine command. Do not use barcode `symbologyCode` as a `ScannerSymbology` setting ID, and use the published spelling `getSymobologies()` for enabled-format readback.

### Missing events or stale UI

Subscribe before connecting. `events` has no replay and a 64-notification buffer; slow collectors lose oldest events. Keep the handler short, update UI on the main thread, and cancel only when the owner ends. Read `getConnectionState()` or `battery.telemetry` for a current snapshot after an observer restarts.

### React Native bridge errors

The [React Native sample](../Samples/ReactNative/README.md) defines its own Promise rejection strings: `NO_ACTIVITY`, `PAIRING_FAILED`, `SNAPIPC_ERROR`, and iOS `INVALID_SYMBOLOGY`. These identify bridge-level conditions or wrapped native failures and are **not SDK error codes**. On Android, **Ready to Pair** retries `requestPermissions()`; a subsequent NFC tap still identifies the scanner. Inspect the accompanying message/native error and use the public SDK surface above for recovery. A missing `SnapIPCModule` requires rebuilding the native app, not just reloading JavaScript.
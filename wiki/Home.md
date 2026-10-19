# SnapIPC SDK 1.0.0

The `SnapHalo` client in the SnapIPC SDK connects a host app to an IPCMobile SnapHalo barcode scanner. It owns NFC tap to pair, BLE discovery and connection, device commands, barcode, battery, buzzer, lights, physical trigger, firmware, and connection events. 

Android provides an Activity-bound `SnapHaloAndroid` adapter for NFC and permissions; iOS provides `SnapHalo.startPairing(onError:)`. The shipped artifacts are an Android AAR and iOS XCFramework. The iOS framework includes the public `SnapHaloFirmwareUploader` API.

## System architecture

```mermaid
flowchart LR
    A[Host app UI] --> B[SnapHalo public client]
    A --> C[Android SnapHaloAndroid or iOS startPairing]
    C -->|NFC tap or dispatch| D[Scanner NFC tag]
    C --> B
    B -->|BLE discovery, connection and commands| E[SnapHalo scanner]
    E -->|Barcode, battery, trigger and firmware data| B
    B -->|Typed events and query results| A
```

The SDK sends commands over BLE and an internal proprietary OOB credential handshake. The Snap Halo also can have a company key which is detailed in the Security Document. For reference to the Security document please e-mail support@ipcmobiile.com

```mermaid
sequenceDiagram
    participant User
    participant App as Host app
    participant Pair as Pairing adapter / iOS pairing
    participant SDK as SnapHalo client
    participant Scanner as Snap Halo
    App->>SDK: Subscribe to events
    App->>Pair: Create adapter / startPairing(onError:)
    User->>Scanner: Tap phone at NFC tag
    Scanner-->>Pair: NFC identity / OOB record
    Pair->>SDK: Internal pairing handover
    SDK->>Scanner: BLE discover, connect, authenticate
    Scanner-->>SDK: Ready device session
    SDK-->>App: OnConnectionStatus(Connected)
    App->>SDK: details(), battery.getTelemetry()
    SDK-->>App: Typed query results and telemetry events
```

`Connected` is the SDK's command-ready state after service discovery and any required authentication. See [Pairing and connection](02-Pairing-and-Connection.md) for the actual state names and ownership rules.

## Sample applications

| Sample | Platform / language | Demonstrates |
| --- | --- | --- |
| [Android native](../Samples/Kotlin/README.md) | Android / Kotlin / Compose | NFC dispatch and reader mode, BLE connection, barcode commands/events, battery, firmware events, scan modes and settings |
| [iOS native](../Samples/Swift/README.md) | iOS / Swift / SwiftUI | NFC pairing sheet, BLE connection, event observation, barcode controls, battery, firmware upload |
| [React Native](../Samples/ReactNative/README.md) | Android + iOS / TypeScript with Kotlin and Swift bridges | Shared scanner UI, Android permission retry and NFC tap flow, native events, scan controls and settings |

Hardware pairing requires a physical phone and scanner. No minimum scanner firmware version is supplied with this distribution; validate the reported firmware against the devices you ship.

## Navigation

| Goal | Guide |
| --- | --- |
| Run a sample or integrate the binary SDK | [Quickstart](01-Quickstart.md) |
| Understand NFC tap, BLE readiness, and reconnection | [Pairing and connection](02-Pairing-and-Connection.md) |
| Send commands and consume telemetry | [Core SDK usage](03-Core-SDK-Usage.md) |
| Implement Android or iOS firmware upload | [OTA firmware updates](04-OTA-Updates.md) |
| Design a durable host integration | [Best practices](05-Best-Practices.md) |
| Recover from failures | [Troubleshooting and error surfaces](06-Troubleshooting-and-Error-Codes.md) |
| Browse all guides and samples | [Sidebar](./_Sidebar.md) |

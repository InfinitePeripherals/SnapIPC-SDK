import Foundation
import React
import SnapIPCSDK

@objc(SnapIPCModule)
final class SnapIPCModule: RCTEventEmitter {
  private let client = SnapHalo()
  private var subscription: KotlinAutoCloseable?
  private var listening = false
  private var connection: ConnectionState = .waitingfornfc

  override init() {
    super.init()
    subscription = client.observeEvents { [weak self] event in
      self?.handle(event)
    }
  }

  @objc override static func requiresMainQueueSetup() -> Bool { true }
  override func supportedEvents() -> [String]! { ["SnapIPCEvent"] }
  override func startObserving() { listening = true }
  override func stopObserving() { listening = false }

  private func emit(_ body: [String: Any]) {
    if listening { sendEvent(withName: "SnapIPCEvent", body: body) }
  }

  private func connectionName(_ value: ConnectionState) -> String {
    if value == .waitingfornfc { return "WaitingForNfc" }
    if value == .requestingbluetooth { return "RequestingBluetooth" }
    if value == .scanning { return "Scanning" }
    if value == .connecting { return "Connecting" }
    if value == .discoveringservices { return "DiscoveringServices" }
    if value == .connected { return "Connected" }
    if value == .reconnecting { return "Reconnecting" }
    return "Error"
  }

  private func modeName(_ value: BarcodeScanMode) -> String {
    if value == .continuous { return "Continuous" }
    if value == .continuousunique { return "ContinuousUnique" }
    return "Single"
  }

  private func batteryPayload(_ value: BatteryTelemetry) -> [String: Any] {
    [
      "stateOfCharge": value.stateOfCharge,
      "voltage": value.voltage,
      "remainingCapacityMah": value.remainingCapacityMah,
      "temperatureCelsius": value.temperatureCelsius,
      "isCharging": value.isCharging,
    ]
  }

  private func handle(_ event: SnapHaloEvent) {
    if let status = event as? SnapHaloEvent.OnConnectionStatus {
      let wasConnected = connection == .connected
      connection = status.connectionState
      var body: [String: Any] = ["type": "connection", "connection": connectionName(connection)]
      if let message = status.errorMessage { body["message"] = message }
      emit(body)
      if connection == .connected && !wasConnected { loadDetails() }
    } else if let scan = event as? SnapHaloEvent.OnBarcodeScanned {
      emit(["type": "barcode", "value": scan.barcode.value, "symbology": scan.barcode.symbology])
    } else if let battery = event as? SnapHaloEvent.OnBatteryTelemetryChanged {
      emit(["type": "battery", "battery": batteryPayload(battery.telemetry)])
    } else if let firmware = event as? SnapHaloEvent.OnFirmwareVersionChanged {
      emit(["type": "firmware", "firmware": firmware.version])
    } else if let warning = event as? SnapHaloEvent.OnSecurityWarning {
      emit(["type": "error", "message": warning.message])
    }
  }

  private func loadDetails() {
    Task { @MainActor [weak self] in
      guard let self else { return }
      do {
        let details = try await client.details()
        guard connection == .connected else { return }
        var enabled: [String: Bool] = [:]
        for format in ScannerSymbology.companion.Supported {
          enabled[String(format.id)] = details.isSymbologyEnabled(symbology: format)
        }
        emit(["type": "details", "mode": modeName(details.scanWorkMode ?? .single), "enabled": enabled])
        let firmware = try await client.getFirmware()
        let scannerFirmware = try await client.barcode.getFirmware()
        if connection == .connected {
          emit(["type": "firmware", "firmware": firmware, "scannerFirmware": scannerFirmware])
        }
      } catch {
        emit(["type": "error", "message": error.localizedDescription])
      }
    }
  }

  @objc(getSnapshot:rejecter:)
  func getSnapshot(_ resolve: @escaping RCTPromiseResolveBlock, rejecter: RCTPromiseRejectBlock) {
    DispatchQueue.main.async { [self] in
      let formats = ScannerSymbology.companion.Supported.map { ["id": $0.id, "name": $0.displayName] as [String: Any] }
      var snapshot: [String: Any] = ["connection": connectionName(connection), "symbologies": formats]
      if let battery = client.battery.telemetry { snapshot["battery"] = batteryPayload(battery) }
      resolve(snapshot)
      if connection == .connected { loadDetails() }
    }
  }

  @objc(startPairing:rejecter:)
  func startPairing(_ resolve: @escaping RCTPromiseResolveBlock, rejecter: RCTPromiseRejectBlock) {
    DispatchQueue.main.async { [self] in
      client.startPairing { [weak self] message in
        self?.emit(["type": "error", "message": message])
      }
      resolve(nil)
    }
  }

  private func command(_ resolve: @escaping RCTPromiseResolveBlock,
                       reject: @escaping RCTPromiseRejectBlock,
                       action: @escaping () async throws -> Void) {
    Task { @MainActor in
      do {
        try await action()
        resolve(nil)
      } catch {
        reject("SNAPIPC_ERROR", error.localizedDescription, error as NSError)
      }
    }
  }

  @objc(disconnect:rejecter:)
  func disconnect(_ resolve: @escaping RCTPromiseResolveBlock, rejecter: @escaping RCTPromiseRejectBlock) {
    command(resolve, reject: rejecter) {
      self.client.cancelPendingConnection()
      try await self.client.disconnect()
    }
  }

  @objc(startScan:rejecter:)
  func startScan(_ resolve: @escaping RCTPromiseResolveBlock, rejecter: @escaping RCTPromiseRejectBlock) {
    command(resolve, reject: rejecter) { try await self.client.barcode.startScan() }
  }

  @objc(stopScan:rejecter:)
  func stopScan(_ resolve: @escaping RCTPromiseResolveBlock, rejecter: @escaping RCTPromiseRejectBlock) {
    command(resolve, reject: rejecter) { try await self.client.barcode.stopScan() }
  }

  @objc(setScanMode:resolver:rejecter:)
  func setScanMode(_ name: String, resolver resolve: @escaping RCTPromiseResolveBlock,
                   rejecter: @escaping RCTPromiseRejectBlock) {
    let mode: BarcodeScanMode = name == "Continuous" ? .continuous : name == "ContinuousUnique" ? .continuousunique : .single
    command(resolve, reject: rejecter) { try await self.client.barcode.setScanMode(mode: mode) }
  }

  @objc(setSymbology:enabled:resolver:rejecter:)
  func setSymbology(_ id: NSNumber, enabled: Bool, resolver resolve: @escaping RCTPromiseResolveBlock,
                    rejecter: @escaping RCTPromiseRejectBlock) {
    guard let format = ScannerSymbology.companion.Supported.first(where: { $0.id == id.int32Value }) else {
      rejecter("INVALID_SYMBOLOGY", "Unsupported symbology: \(id)", nil)
      return
    }
    command(resolve, reject: rejecter) { try await self.client.barcode.setSymbology(symbology: format, enabled: enabled) }
  }

  @objc(setAllSymbologies:resolver:rejecter:)
  func setAllSymbologies(_ enabled: Bool, resolver resolve: @escaping RCTPromiseResolveBlock,
                         rejecter: @escaping RCTPromiseRejectBlock) {
    command(resolve, reject: rejecter) { try await self.client.barcode.setEnableAllSymbologies(enabled: enabled) }
  }

  deinit {
    subscription?.close()
    client.close()
  }
}

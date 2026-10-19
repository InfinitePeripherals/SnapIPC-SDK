import Foundation
import SnapIPCSDK
import UIKit

final class SnapIPCAppModel: ObservableObject {
    let client = SnapHalo()
    private var subscription: KotlinAutoCloseable?
    @Published var connection: ConnectionState = .waitingfornfc
    @Published var errorMessage: String?
    @Published var battery: BatteryTelemetry?
    @Published var firmware: String?
    @Published var scannerFirmware: String?
    @Published var lastScan: NativeScan?
    @Published var scanning = false
    @Published var commandPending = false
    @Published var showFirmwarePicker = false
    @Published var firmwareUploadStatus: String?
    @Published var firmwareUploadInProgress = false
    @Published var firmwareCanCancel = false
    @Published var mode: BarcodeScanMode = .single
    @Published var enabled: [ScannerSymbology: Bool] = [:]
    let symbologies = ScannerSymbology.companion.Supported
    private var sequence = 0
    private lazy var firmwareUploader = SnapHaloFirmwareUploader { [weak self] status in
        self?.handleFirmwareUploadStatus(status)
    }

    init() {
        subscription = client.observeEvents { [weak self] event in
            self?.handle(event)
        }
    }

    private func handle(_ event: SnapHaloEvent) {
        if let event = event as? SnapHaloEvent.OnConnectionStatus {
            let wasConnected = connection == .connected
            connection = event.connectionState
            errorMessage = event.errorMessage
            if connection == .connected {
                if !wasConnected {
                    run { [self] in
                        let details = try await client.details()
                        guard connection == .connected else { return }
                        mode = details.scanWorkMode ?? .single
                        for format in symbologies { enabled[format] = details.isSymbologyEnabled(symbology: format) }
                    }
                    loadFirmwareVersions()
                }
            } else {
                scanning = false
                lastScan = nil
                battery = nil
                firmware = nil
                scannerFirmware = nil
                sequence = 0
            }
        } else if let event = event as? SnapHaloEvent.OnBarcodeScanned {
            sequence += 1
            lastScan = NativeScan(sequence: sequence, value: event.barcode.value, symbology: event.barcode.symbology, date: Date())
            if mode == .single && scanning { toggleScan() }
        } else if let event = event as? SnapHaloEvent.OnBatteryTelemetryChanged {
            battery = event.telemetry
        } else if let event = event as? SnapHaloEvent.OnFirmwareVersionChanged {
            firmware = event.version
        }
    }

    private func loadFirmwareVersions() {
        Task { @MainActor [weak self] in
            guard let self else { return }
            if let version = try? await client.getFirmware(), connection == .connected {
                firmware = version
            }
            if let version = try? await client.barcode.getFirmware(), connection == .connected {
                scannerFirmware = version
            }
        }
    }

    private func run(_ operation: @escaping () async throws -> Void) {
        Task { @MainActor [weak self] in
            do { try await operation(); self?.errorMessage = nil }
            catch { self?.errorMessage = error.localizedDescription }
        }
    }

    func toggleScan() {
        guard connection == .connected && !commandPending && !firmwareUploadInProgress else { return }
        commandPending = true
        let start = !scanning
        run { [self] in
            defer { commandPending = false }
            if start { try await client.barcode.startScan() } else { try await client.barcode.stopScan() }
            scanning = start
        }
    }

    func setMode(_ value: BarcodeScanMode) {
        run { [self] in try await client.barcode.setScanMode(mode: value); mode = value }
    }
    func setSymbology(_ value: ScannerSymbology, on: Bool) {
        run { [self] in try await client.barcode.setSymbology(symbology: value, enabled: on); enabled[value] = on }
    }
    func setAll(_ on: Bool) {
        run { [self] in
            try await client.barcode.setEnableAllSymbologies(enabled: on)
            for value in symbologies { enabled[value] = on }
        }
    }
    func disconnect() {
        client.cancelPendingConnection()
        run { [self] in try await client.disconnect(); startNfcPairing() }
    }

    func startNfcPairing() {
        client.startPairing { [weak self] message in
            self?.errorMessage = message
        }
    }

    func requestFirmwareUpload() {
        guard connection == .connected && !firmwareUploadInProgress else { return }
        showFirmwarePicker = true
    }

    func handleFirmwareSelection(_ result: Result<URL, Error>) {
        guard case .success(let url) = result else { return }
        DispatchQueue.main.async { [weak self] in
            guard let self else { return }
            guard self.connection == .connected,
                  let identifier = self.client.connectedPeripheralIdentifier,
                  let uuid = UUID(uuidString: identifier) else {
                self.firmwareUploadStatus = "Reconnect the scanner before updating firmware"
                return
            }
            do {
                try self.firmwareUploader.upload(fileURL: url, peripheralIdentifier: uuid)
            } catch {
                self.firmwareUploadInProgress = false
                self.firmwareCanCancel = false
                self.firmwareUploadStatus = "Firmware update failed: \(error.localizedDescription)"
            }
        }
    }

    func cancelFirmwareUpload() {
        guard firmwareCanCancel else { return }
        firmwareUploader.cancel()
    }

    private func handleFirmwareUploadStatus(_ status: SnapHaloFirmwareUploadStatus) {
        switch status {
        case .reading:
            firmwareUploadStatus = "Reading firmware file…"
        case .validating:
            firmwareUploadStatus = "Checking firmware and scanner…"
        case .uploading(let percent):
            firmwareUploadStatus = "Uploading \(percent)%"
        case .applying:
            firmwareUploadStatus = "Applying firmware…"
        case .rebooting:
            firmwareUploadStatus = "Rebooting scanner…"
        case .confirming:
            firmwareUploadStatus = "Confirming new firmware…"
        case .completed:
            firmwareUploadStatus = "Firmware update complete"
        case .canceled:
            firmwareUploadStatus = "Firmware upload canceled"
        case .failed(let message):
            firmwareUploadStatus = "Firmware update failed: \(message)"
        @unknown default:
            firmwareUploadStatus = "Firmware update state changed"
        }
        switch status {
        case .completed, .canceled, .failed:
            firmwareUploadInProgress = false
        default:
            firmwareUploadInProgress = true
        }
        if case .uploading = status { firmwareCanCancel = true }
        else { firmwareCanCancel = false }
    }

    deinit {
        subscription?.close()
        client.close()
    }
}

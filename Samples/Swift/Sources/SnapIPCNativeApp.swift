import SwiftUI
import SnapIPCSDK
import UniformTypeIdentifiers

struct NativeScan {
    let sequence: Int
    let value: String
    let symbology: String
    let date: Date
}

@main
struct SnapIPCNativeApp: App {
    @StateObject private var model = SnapIPCAppModel()
    var body: some Scene { WindowGroup { NativeContentView(model: model) } }
}

private let purple = Color(red: 0.43, green: 0.20, blue: 0.75)
private let blue = Color(red: 0.0, green: 0.53, blue: 0.85)
private let green = Color(red: 0.58, green: 0.86, blue: 0.18)

struct NativeContentView: View {
    @ObservedObject var model: SnapIPCAppModel
    @State private var splash = true
    @State private var menu = false
    @State private var formats = false
    @State private var scanFeedback = false
    private var connected: Bool { model.connection == .connected }
    private var readyToPair: Bool { model.connection == .waitingfornfc || model.connection == .error }
    private var status: String {
        if connected { return scanFeedback ? "Valid barcode" : "Connected" }
        if readyToPair { return model.connection == .error ? "Connection failed" : "Awaiting NFC pairing" }
        if model.connection == .scanning { return "Finding scanner" }
        if model.connection == .reconnecting { return "Reconnecting" }
        if model.connection == .discoveringservices { return "Preparing scanner" }
        return "Connecting"
    }
    var body: some View {
        ZStack {
            Color(white: 0.07).ignoresSafeArea()
            if splash {
                Image("snapipc_loading_screen").resizable().scaledToFill().ignoresSafeArea()
            } else {
                VStack(spacing: 0) {
                    HStack {
                        Image("snapipc_wordmark").resizable().scaledToFit().frame(height: 44)
                        Spacer()
                        Button { menu = true } label: { Image(systemName: "line.3.horizontal").font(.title2).foregroundColor(.black).padding(12).background(Color(white: 0.95)).cornerRadius(12) }
                    }.padding().background(Color.white)
                    ScrollView {
                        VStack(spacing: 12) {
                            ZStack(alignment: .topLeading) {
                                RoundedRectangle(cornerRadius: 28)
                                    .fill(Color(white: 0.04))
                                Image(scanFeedback ? "snapipc_valid_barcode" : connected ? "snapipc_connected" : "snapipc_no_connection")
                                    .resizable().scaledToFit()
                                    .frame(maxWidth: .infinity)
                                    .frame(height: 210)
                                HStack(spacing: 8) {
                                    Circle().fill(connected ? green : .gray).frame(width: 9, height: 9)
                                    Text(status.uppercased()).font(.caption.bold())
                                }
                                .padding(.horizontal, 12).padding(.vertical, 9)
                                .background(Color(white: 0.09)).clipShape(Capsule())
                                .padding(14)
                            }
                            .frame(height: 210)
                            .clipShape(RoundedRectangle(cornerRadius: 28))
                            if connected {
                                telemetryCard
                            }
                            if let scan = model.lastScan {
                                HStack(alignment: .top, spacing: 16) {
                                    Text("\(scan.sequence)").font(.system(size: 48, weight: .heavy)).foregroundColor(purple)
                                    VStack(alignment: .leading, spacing: 10) {
                                        HStack { Text("BARCODE").font(.caption.bold()); Spacer(); Text("VALID").font(.caption.bold()).foregroundColor(.green) }
                                        Text(scan.value).font(.title3.bold()).textSelection(.enabled)
                                        Divider()
                                        Text(scan.symbology).font(.subheadline.bold())
                                        Text(scan.date, style: .date).font(.caption)
                                        Text(scan.date, style: .time).font(.caption)
                                    }
                                }.padding(20).foregroundColor(.black).frame(maxWidth: .infinity, alignment: .leading).background(Color.white).cornerRadius(24)
                            } else {
                                HStack(spacing: 16) {
                                    Image(systemName: "barcode.viewfinder").font(.largeTitle).foregroundColor(purple)
                                    VStack(alignment: .leading, spacing: 6) {
                                        Text(connected ? "Ready to scan" : "Ready to pair").font(.headline)
                                        Text(connected ? "The next barcode will appear here." : "Hold the phone near the scanner NFC pairing point.").font(.subheadline).foregroundColor(.secondary)
                                    }
                                }.padding(20).frame(maxWidth: .infinity, alignment: .leading).foregroundColor(.black).background(Color.white).cornerRadius(24)
                            }
                            if let error = model.errorMessage { Text(error).font(.subheadline).foregroundColor(.orange).textSelection(.enabled) }
                            if let firmwareStatus = model.firmwareUploadStatus {
                                HStack(spacing: 10) {
                                    Image(systemName: "arrow.triangle.2.circlepath.circle")
                                    Text(firmwareStatus).font(.subheadline).textSelection(.enabled)
                                }
                                .frame(maxWidth: .infinity, alignment: .leading)
                                .padding(16)
                                .background(Color(white: 0.14))
                                .clipShape(RoundedRectangle(cornerRadius: 16))
                            }
                        }.padding(.horizontal, 16).padding(.vertical, 10)
                    }
                    Button {
                        if readyToPair { model.startNfcPairing() } else { model.toggleScan() }
                    } label: {
                        Text(readyToPair ? "Ready to Pair" : connected ? (model.scanning ? "Stop Scan" : "Start Scan") : "Connecting…")
                            .font(.headline).frame(maxWidth: .infinity).padding(.vertical, 14)
                            .background(LinearGradient(colors: model.scanning ? [.red, .orange] : [blue, purple], startPoint: .leading, endPoint: .trailing)).cornerRadius(17)
                    }.disabled((!readyToPair && !connected) || model.commandPending || model.firmwareUploadInProgress).opacity((readyToPair || connected) && !model.firmwareUploadInProgress ? 1 : 0.5)
                        .padding(.horizontal, 16).padding(.top, 8).padding(.bottom, 8)
                }.foregroundColor(.white)
            }
        }
        .task {
            try? await Task.sleep(nanoseconds: 1_800_000_000)
            guard !Task.isCancelled else { return }
            splash = false
            model.startNfcPairing()
        }
        .task(id: model.lastScan?.sequence) {
            guard model.lastScan != nil else { scanFeedback = false; return }
            scanFeedback = true
            try? await Task.sleep(nanoseconds: 1_600_000_000)
            guard !Task.isCancelled else { return }
            scanFeedback = false
        }
        .sheet(isPresented: $menu) { settings }
        .sheet(isPresented: $formats) { symbologies }
        .fileImporter(isPresented: $model.showFirmwarePicker, allowedContentTypes: [.data, .zip]) {
            model.handleFirmwareSelection($0)
        }
    }
    private var telemetryCard: some View {
        HStack(alignment: .center, spacing: 16) {
            VStack(alignment: .leading, spacing: 6) {
                Text("BATTERY")
                    .font(.system(size: 10, weight: .heavy))
                    .tracking(0.7)
                    .foregroundColor(Color(red: 0.72, green: 0.72, blue: 0.75))
                HStack(spacing: 8) {
                    BatteryGauge(percent: model.battery?.stateOfCharge ?? 0)
                    Text(model.battery.map { "\($0.stateOfCharge)%" } ?? "—")
                        .font(.system(size: 21, weight: .bold))
                }
                if model.battery?.isCharging == true {
                    Text("CHARGING")
                        .font(.system(size: 10, weight: .heavy))
                        .foregroundColor(green)
                }
            }
            .frame(maxWidth: .infinity, alignment: .leading)

            VStack(spacing: 8) {
                telemetryLine("Firmware", model.firmware ?? "—")
                telemetryLine("Scanner firmware", model.scannerFirmware ?? "—")
                telemetryLine("Temperature", model.battery.map {
                    String(format: "%.1f °C", $0.temperatureCelsius)
                } ?? "—")
            }
            .frame(maxWidth: .infinity)
        }
        .padding(.horizontal, 16).padding(.vertical, 14)
        .frame(maxWidth: .infinity)
        .background(Color(white: 0.14))
        .clipShape(RoundedRectangle(cornerRadius: 22))
    }

    private func telemetryLine(_ title: String, _ value: String) -> some View {
        HStack(spacing: 4) {
            Text(title)
                .foregroundColor(Color(red: 0.72, green: 0.72, blue: 0.75))
                .lineLimit(1).minimumScaleFactor(0.8)
            Spacer(minLength: 4)
            Text(value).fontWeight(.semibold).lineLimit(1)
        }
        .font(.system(size: 10))
    }

    private var settings: some View {
        NavigationView {
            Form {
                if connected || model.connection == .reconnecting {
                    Section(header: Text("Connection")) {
                        Button("Disconnect & Unpair", role: .destructive) { menu = false; model.disconnect() }
                            .disabled(model.firmwareUploadInProgress)
                    }
                }
                Section(header: Text("Firmware update")) {
                    Button("Update firmware…") {
                        menu = false
                        DispatchQueue.main.asyncAfter(deadline: .now() + 0.35) {
                            model.requestFirmwareUpload()
                        }
                    }
                    .disabled(!connected || model.firmwareUploadInProgress)
                    if model.firmwareCanCancel {
                        Button("Cancel upload", role: .destructive) { model.cancelFirmwareUpload() }
                    }
                    if let firmwareStatus = model.firmwareUploadStatus {
                        Text(firmwareStatus).font(.footnote)
                    }
                }
                Section(header: Text("Scan mode")) {
                    Picker("Mode", selection: Binding(get: { model.mode }, set: { model.setMode($0) })) {
                        Text("Single").tag(BarcodeScanMode.single)
                        Text("Continuous").tag(BarcodeScanMode.continuous)
                        Text("Unique").tag(BarcodeScanMode.continuousunique)
                    }.pickerStyle(.segmented).disabled(!connected || model.firmwareUploadInProgress)
                }
                Section(header: Text("Barcode types")) {
                    Button("Symbology · \(model.enabled.values.filter { $0 }.count) enabled") {
                        menu = false
                        DispatchQueue.main.asyncAfter(deadline: .now() + 0.35) { formats = true }
                    }.disabled(!connected || model.firmwareUploadInProgress)
                }
            }.navigationTitle("Menu").toolbar { ToolbarItem(placement: .confirmationAction) { Button("Done") { menu = false } } }
        }
    }
    private var symbologies: some View {
        NavigationView {
            Form {
                Toggle("All Symbologies", isOn: Binding(get: { !model.enabled.isEmpty && model.enabled.values.allSatisfy { $0 } }, set: { model.setAll($0) }))
                ForEach(model.symbologies, id: \.self) { format in
                    Toggle(format.displayName, isOn: Binding(get: { model.enabled[format] ?? true }, set: { model.setSymbology(format, on: $0) }))
                }
            }.disabled(!connected || model.firmwareUploadInProgress).navigationTitle("Symbology").toolbar { ToolbarItem(placement: .confirmationAction) { Button("Done") { formats = false } } }
        }
    }
}

private struct BatteryGauge: View {
    let percent: Int32

    var body: some View {
        ZStack(alignment: .leading) {
            RoundedRectangle(cornerRadius: 4)
                .stroke(Color.white, lineWidth: 2)
                .frame(width: 27, height: 16)
            RoundedRectangle(cornerRadius: 1)
                .fill(green)
                .frame(width: 21 * CGFloat(min(max(percent, 0), 100)) / 100, height: 10)
                .offset(x: 3)
            RoundedRectangle(cornerRadius: 1)
                .fill(Color.white)
                .frame(width: 3, height: 8)
                .offset(x: 28)
        }
        .frame(width: 31, height: 16)
    }
}

package com.ipcmobile.snapipc.androidnative

import androidx.compose.animation.AnimatedVisibility
import androidx.compose.animation.fadeIn
import androidx.compose.animation.fadeOut
import androidx.compose.animation.slideInHorizontally
import androidx.compose.animation.slideOutHorizontally
import androidx.compose.foundation.Canvas
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.interaction.MutableInteractionSource
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.heightIn
import androidx.compose.foundation.layout.navigationBarsPadding
import androidx.compose.foundation.layout.offset
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.statusBarsPadding
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.layout.widthIn
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.foundation.verticalScroll
import androidx.compose.material3.HorizontalDivider
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.ModalBottomSheet
import androidx.compose.material3.Switch
import androidx.compose.material3.SwitchDefaults
import androidx.compose.material3.Text
import androidx.compose.material3.rememberModalBottomSheetState
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.draw.shadow
import androidx.compose.ui.geometry.CornerRadius
import androidx.compose.ui.geometry.Offset
import androidx.compose.ui.geometry.Size
import androidx.compose.ui.graphics.Brush
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.StrokeCap
import androidx.compose.ui.graphics.drawscope.Stroke
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.ipcmobile.snapipcsdk.models.BatteryTelemetry
import com.ipcmobile.snapipcsdk.models.ConnectionState
import com.ipcmobile.snapipcsdk.models.BarcodeScanMode
import com.ipcmobile.snapipcsdk.models.ScannerSymbology
import kotlinx.coroutines.delay
import androidx.compose.ui.res.painterResource
import kotlin.math.absoluteValue
import kotlin.math.roundToInt

@Composable
fun SnapIPCDemoApp(
    controller: SnapIPCDemoController,
    onRequestNfcPairing: () -> Unit = {},
) {
    val state by controller.state.collectAsState()
    var showSplash by remember { mutableStateOf(true) }
    var menuOpen by remember { mutableStateOf(false) }
    var symbologyOpen by remember { mutableStateOf(false) }

    LaunchedEffect(controller) {
        delay(1_800)
        showSplash = false
        onRequestNfcPairing()
    }

    SnapIPCTheme {
        if (showSplash) {
            Image(
                painter = painterResource(R.drawable.snapipc_loading_screen),
                contentDescription = "IPCMobile SnapIPC",
                modifier = Modifier.fillMaxSize().background(Color(0xFFEFEFEF)),
                contentScale = ContentScale.Crop,
            )
        } else {
            Box(Modifier.fillMaxSize().background(Surface)) {
                MainContent(
                    state = state,
                    onOpenMenu = { menuOpen = true },
                    onToggleScan = controller::toggleScan,
                    onRequestNfcPairing = onRequestNfcPairing,
                )
                SettingsDrawer(
                    visible = menuOpen,
                    state = state,
                    onDismiss = { menuOpen = false },
                    onDisconnect = {
                        menuOpen = false
                        controller.disconnect()
                        onRequestNfcPairing()
                    },
                    onScanMode = controller::setScanMode,
                    onOpenSymbologies = {
                        menuOpen = false
                        symbologyOpen = true
                    },
                )
                if (symbologyOpen) {
                    SymbologySheet(
                        state = state,
                        onDismiss = { symbologyOpen = false },
                        onAllChanged = controller::setAllSymbologies,
                        onChanged = controller::setSymbology,
                    )
                }
            }
        }
    }
}

@Composable
private fun MainContent(
    state: SnapIPCDemoUiState,
    onOpenMenu: () -> Unit,
    onToggleScan: () -> Unit,
    onRequestNfcPairing: () -> Unit,
) {
    Column(Modifier.fillMaxSize().background(Surface).statusBarsPadding()) {
        Header(onOpenMenu)
        Column(
            modifier = Modifier
                .fillMaxWidth()
                .weight(1f)
                .verticalScroll(rememberScrollState())
                .padding(horizontal = 16.dp, vertical = 14.dp),
            verticalArrangement = Arrangement.spacedBy(14.dp),
        ) {
            DeviceStage(state)
            state.lastScan?.let { ScanCard(it) } ?: EmptyScanCard(state.emptyTitle, state.emptyMessage)
        }
        ScanButton(state, onToggleScan, onRequestNfcPairing)
    }
}

@Composable
private fun ScanButton(
    state: SnapIPCDemoUiState,
    onToggleScan: () -> Unit,
    onRequestNfcPairing: () -> Unit,
) {
    val readyToPair = state.connectionState == ConnectionState.WaitingForNfc ||
        state.connectionState == ConnectionState.Error
    val enabled = readyToPair || state.canToggleScan
    val colors = when {
        !enabled -> listOf(Color(0xFF444449), Color(0xFF36363A))
        state.isSoftScanActive -> listOf(Color(0xFF9D302B), InvalidRed)
        else -> listOf(IpcBlue, IpcPurple)
    }
    Box(
        modifier = Modifier
            .fillMaxWidth()
            .navigationBarsPadding()
            .padding(horizontal = 16.dp, vertical = 14.dp)
            .height(58.dp)
            .shadow(10.dp, RoundedCornerShape(17.dp))
            .clip(RoundedCornerShape(17.dp))
            .background(Brush.linearGradient(colors))
            .clickable(enabled = enabled, onClick = if (readyToPair) onRequestNfcPairing else onToggleScan),
        contentAlignment = Alignment.Center,
    ) {
        Text(
            when {
                readyToPair -> "Ready to Pair"
                state.connectionState != ConnectionState.Connected -> "Connecting…"
                state.isSoftScanActive -> "Stop Scan"
                else -> "Start Scan"
            },
            color = if (enabled) Color.White else Color(0xFFB5B5B8),
            fontSize = 16.sp,
            fontWeight = FontWeight.Bold,
        )
    }
}

@Composable
private fun Header(onOpenMenu: () -> Unit) {
    Row(
        modifier = Modifier
            .fillMaxWidth()
            .height(68.dp)
            .shadow(12.dp)
            .background(Color.White)
            .padding(horizontal = 18.dp, vertical = 8.dp),
        verticalAlignment = Alignment.CenterVertically,
        horizontalArrangement = Arrangement.SpaceBetween,
    ) {
        Image(
            painter = painterResource(R.drawable.snapipc_wordmark),
            contentDescription = "SnapIPC",
            modifier = Modifier.widthIn(max = 250.dp).fillMaxWidth(0.72f).height(50.dp),
            contentScale = ContentScale.Fit,
            alignment = Alignment.CenterStart,
        )
        Box(
            modifier = Modifier
                .size(48.dp)
                .clip(RoundedCornerShape(14.dp))
                .background(Color(0xFFF2F2F2))
                .clickable(onClick = onOpenMenu),
            contentAlignment = Alignment.Center,
        ) {
            Canvas(Modifier.size(24.dp, 20.dp)) {
                listOf(2f, size.height / 2f, size.height - 2f).forEach { y ->
                    drawLine(Color(0xFF151515), Offset(1f, y), Offset(size.width - 1f, y), 3.dp.toPx(), StrokeCap.Round)
                }
            }
        }
    }
}

@Composable
private fun DeviceStage(state: SnapIPCDemoUiState) {
    Box(
        modifier = Modifier
            .fillMaxWidth()
            .height(390.dp)
            .clip(RoundedCornerShape(30.dp))
            .background(Brush.radialGradient(listOf(Color(0xFF25272C), Color(0xFF0B0B0C)))),
    ) {
        Image(
            painter = painterResource(state.deviceState.imageResource),
            contentDescription = state.stateLabel,
            modifier = Modifier.fillMaxSize(),
            contentScale = ContentScale.Crop,
        )
        StatePill(state, Modifier.align(Alignment.TopStart).padding(15.dp))
        state.batteryTelemetry?.let {
            BatteryOverlay(
                battery = it,
                firmware = state.firmwareVersion,
                modifier = Modifier.align(Alignment.TopEnd).padding(15.dp),
            )
        }
    }
}

private val DeviceUiState.imageResource: Int
    get() = when (this) {
        DeviceUiState.WaitingForPairing -> R.drawable.snapipc_no_connection
        DeviceUiState.Connected -> R.drawable.snapipc_connected
        DeviceUiState.ValidScan -> R.drawable.snapipc_valid_barcode
    }

@Composable
private fun StatePill(state: SnapIPCDemoUiState, modifier: Modifier = Modifier) {
    val color = when (state.deviceState) {
        DeviceUiState.WaitingForPairing -> Color(0xFF888888)
        DeviceUiState.Connected, DeviceUiState.ValidScan -> IpcGreen
    }
    Row(
        modifier = modifier
            .clip(RoundedCornerShape(100.dp))
            .background(Color(0xD0121214))
            .padding(horizontal = 12.dp, vertical = 9.dp),
        verticalAlignment = Alignment.CenterVertically,
        horizontalArrangement = Arrangement.spacedBy(8.dp),
    ) {
        Box(Modifier.size(9.dp).clip(CircleShape).background(color))
        Text(state.stateLabel.uppercase(), color = Color.White, fontSize = 11.sp, fontWeight = FontWeight.Bold)
    }
}

@Composable
private fun BatteryOverlay(
    battery: BatteryTelemetry,
    firmware: String?,
    modifier: Modifier = Modifier,
) {
    Column(
        modifier = modifier
            .widthIn(min = 154.dp)
            .clip(RoundedCornerShape(15.dp))
            .background(Color(0xE0121214))
            .padding(horizontal = 11.dp, vertical = 9.dp),
    ) {
        Row(verticalAlignment = Alignment.CenterVertically, horizontalArrangement = Arrangement.spacedBy(7.dp)) {
            BatteryIcon(battery.stateOfCharge)
            Text("${battery.stateOfCharge}%", fontSize = 14.sp, fontWeight = FontWeight.Bold)
            if (battery.isCharging) Text("CHARGING", color = IpcGreen, fontSize = 8.sp, fontWeight = FontWeight.ExtraBold)
        }
        Row(
            modifier = Modifier.padding(top = 7.dp),
            horizontalArrangement = Arrangement.spacedBy(8.dp),
        ) {
            Text("${battery.voltage.fixed(2)} V", color = Color(0xFFC7C7CA), fontSize = 9.sp)
            Text("${battery.remainingCapacityMah} mAh", color = Color(0xFFC7C7CA), fontSize = 9.sp)
            Text("${battery.temperatureCelsius.fixed(1)} °C", color = Color(0xFFC7C7CA), fontSize = 9.sp)
        }
        HorizontalDivider(Modifier.padding(top = 7.dp, bottom = 5.dp), color = Color.White.copy(alpha = 0.12f))
        Text("FIRMWARE ${firmware ?: "—"}", color = Color(0xFF9D9DA3), fontSize = 8.sp, fontWeight = FontWeight.Bold)
    }
}

@Composable
private fun BatteryIcon(percent: Int) {
    Canvas(Modifier.width(31.dp).height(16.dp)) {
        drawRoundRect(Color.White, size = Size(size.width - 4.dp.toPx(), size.height), cornerRadius = CornerRadius(4.dp.toPx()), style = Stroke(2.dp.toPx()))
        drawRoundRect(Color.White, topLeft = Offset(size.width - 3.dp.toPx(), 4.dp.toPx()), size = Size(3.dp.toPx(), 8.dp.toPx()), cornerRadius = CornerRadius(1.dp.toPx()))
        val innerWidth = (size.width - 9.dp.toPx()) * (percent.coerceIn(0, 100) / 100f)
        drawRoundRect(IpcGreen, topLeft = Offset(3.dp.toPx(), 3.dp.toPx()), size = Size(innerWidth, size.height - 6.dp.toPx()), cornerRadius = CornerRadius(1.dp.toPx()))
    }
}

@Composable
private fun ScanCard(scan: ScanRecord) {
    val sideBrush = Brush.linearGradient(listOf(IpcBlue, IpcPurple))
    Row(
        modifier = Modifier
            .fillMaxWidth()
            .heightIn(min = 150.dp)
            .shadow(14.dp, RoundedCornerShape(25.dp))
            .clip(RoundedCornerShape(25.dp))
            .background(Color.White),
    ) {
        Box(
            modifier = Modifier.width(112.dp).fillMaxHeight().background(sideBrush),
            contentAlignment = Alignment.Center,
        ) {
            Text(scan.sequence.toString(), color = Color.White, fontSize = 50.sp, fontWeight = FontWeight.ExtraBold, maxLines = 1)
            Box(Modifier.align(Alignment.CenterEnd).fillMaxHeight().width(6.dp).background(IpcGreen))
        }
        Column(Modifier.weight(1f).padding(horizontal = 16.dp, vertical = 15.dp)) {
            Row(Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.SpaceBetween, verticalAlignment = Alignment.Top) {
                Column(Modifier.weight(1f)) {
                    FieldLabel("Barcode")
                    Text(
                        scan.barcode,
                        color = Color(0xFF171717),
                        fontSize = 21.sp,
                        fontWeight = FontWeight.Bold,
                        maxLines = 1,
                        overflow = TextOverflow.Ellipsis,
                    )
                }
                ResultPill()
            }
            HorizontalDivider(Modifier.padding(vertical = 10.dp), color = Color(0xFFDDDDDD))
            Row(Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.spacedBy(14.dp)) {
                Column(Modifier.weight(0.9f)) {
                    FieldLabel("Symbology")
                    Text(scan.symbology, color = Color(0xFF171717), fontSize = 13.sp, fontWeight = FontWeight.SemiBold)
                }
                Column(Modifier.weight(1.35f), verticalArrangement = Arrangement.spacedBy(6.dp)) {
                    Column { FieldLabel("Date"); Text(scan.date, color = Color(0xFF171717), fontSize = 12.sp, fontWeight = FontWeight.SemiBold) }
                    Column { FieldLabel("Time"); Text(scan.time, color = Color(0xFF171717), fontSize = 12.sp, fontWeight = FontWeight.SemiBold) }
                }
            }
        }
    }
}

@Composable
private fun FieldLabel(value: String) = Text(
    value.uppercase(),
    color = Color(0xFF737373),
    fontSize = 9.sp,
    fontWeight = FontWeight.ExtraBold,
    letterSpacing = 0.7.sp,
)

@Composable
private fun ResultPill() {
    Text(
        "VALID",
        color = Color(0xFF3F8D00),
        fontSize = 9.sp,
        fontWeight = FontWeight.ExtraBold,
        modifier = Modifier
            .padding(start = 8.dp, top = 3.dp)
            .clip(RoundedCornerShape(100.dp))
            .background(Color(0xFFEAF9DF))
            .padding(horizontal = 8.dp, vertical = 5.dp),
    )
}

@Composable
private fun EmptyScanCard(title: String, message: String) {
    Row(
        modifier = Modifier
            .fillMaxWidth()
            .heightIn(min = 116.dp)
            .shadow(14.dp, RoundedCornerShape(25.dp))
            .clip(RoundedCornerShape(25.dp))
            .background(Brush.linearGradient(listOf(Color.White, Color(0xFFEDEDED))))
            .padding(20.dp),
        verticalAlignment = Alignment.CenterVertically,
        horizontalArrangement = Arrangement.spacedBy(15.dp),
    ) {
        BarcodeGlyph()
        Column {
            Text(title, color = Color(0xFF171717), fontSize = 16.sp, fontWeight = FontWeight.Bold)
            Text(message, color = Color(0xFF666666), fontSize = 13.sp, lineHeight = 18.sp, modifier = Modifier.padding(top = 4.dp))
        }
    }
}

@Composable
private fun BarcodeGlyph(modifier: Modifier = Modifier.size(50.dp)) {
    Canvas(modifier) {
        drawRoundRect(IpcPurple, style = Stroke(3.dp.toPx()), cornerRadius = CornerRadius(16.dp.toPx()))
        val start = size.width * 0.28f
        val end = size.width * 0.72f
        drawLine(IpcBlue, Offset(start, size.height * 0.36f), Offset(end, size.height * 0.36f), 3.dp.toPx(), StrokeCap.Round)
        drawLine(IpcGreen, Offset(start, size.height * 0.50f), Offset(end, size.height * 0.50f), 3.dp.toPx(), StrokeCap.Round)
        drawLine(IpcPurple, Offset(start, size.height * 0.64f), Offset(end, size.height * 0.64f), 3.dp.toPx(), StrokeCap.Round)
    }
}

@Composable
private fun SettingsDrawer(
    visible: Boolean,
    state: SnapIPCDemoUiState,
    onDismiss: () -> Unit,
    onDisconnect: () -> Unit,
    onScanMode: (BarcodeScanMode) -> Unit,
    onOpenSymbologies: () -> Unit,
) {
    AnimatedVisibility(visible, enter = fadeIn(), exit = fadeOut()) {
        Box(
            Modifier.fillMaxSize().background(Color.Black.copy(alpha = 0.58f)).noRippleClick(onDismiss),
        )
    }
    AnimatedVisibility(
        visible = visible,
        modifier = Modifier.fillMaxSize(),
        enter = slideInHorizontally { it },
        exit = slideOutHorizontally { it },
    ) {
        Box(Modifier.fillMaxSize(), contentAlignment = Alignment.CenterEnd) {
            Column(
                modifier = Modifier
                    .fillMaxHeight()
                    .fillMaxWidth(0.88f)
                    .widthIn(max = 390.dp)
                    .background(Color(0xFF19191B))
                    .statusBarsPadding()
                    .navigationBarsPadding()
                    .verticalScroll(rememberScrollState())
                    .padding(horizontal = 20.dp, vertical = 22.dp),
            ) {
                DrawerHeader(onDismiss)
                if (state.canDisconnect) {
                    DrawerSection("Connection", "Disconnect this scanner and require another NFC tap to pair again.") {
                        DrawerButton("Disconnect & Unpair", onDisconnect, danger = true)
                    }
                }
                DrawerSection("Scan mode", "Choose whether the scanner stops after one barcode or keeps scanning.") {
                    ModeSelector(state.scanMode, onScanMode)
                }
                DrawerSection("Barcode types", null) {
                    SymbologyEntry(state.enabledSymbologyCount, state.symbologies.size, onOpenSymbologies)
                }
            }
        }
    }
}

@Composable
private fun DrawerHeader(onDismiss: () -> Unit) {
    Row(Modifier.fillMaxWidth().padding(bottom = 24.dp), horizontalArrangement = Arrangement.SpaceBetween, verticalAlignment = Alignment.Top) {
        Column {
            Text("SNAPIPC", color = IpcGreen, fontSize = 10.sp, fontWeight = FontWeight.ExtraBold, letterSpacing = 1.4.sp)
            Text("Menu", color = Color.White, fontSize = 30.sp, fontWeight = FontWeight.Bold)
        }
        CloseButton(onDismiss)
    }
}

@Composable
private fun CloseButton(onClick: () -> Unit) {
    Box(
        Modifier.size(44.dp).clip(RoundedCornerShape(13.dp)).background(Color(0xFF2C2C30)).clickable(onClick = onClick),
        contentAlignment = Alignment.Center,
    ) {
        Text("×", color = Color.White, fontSize = 30.sp, fontWeight = FontWeight.Light, modifier = Modifier.offset(y = (-1).dp))
    }
}

@Composable
private fun DrawerSection(title: String, description: String?, content: @Composable () -> Unit) {
    HorizontalDivider(color = Color(0xFF333338))
    Column(Modifier.padding(vertical = 19.dp)) {
        Text(title.uppercase(), color = Color.White, fontSize = 13.sp, fontWeight = FontWeight.ExtraBold, letterSpacing = 0.7.sp)
        description?.let { Text(it, color = Color(0xFFAAAAAA), fontSize = 12.sp, lineHeight = 17.sp, modifier = Modifier.padding(top = 5.dp, bottom = 14.dp)) }
        content()
    }
}

@Composable
private fun DrawerButton(label: String, onClick: () -> Unit, danger: Boolean = false) {
    Box(
        Modifier.fillMaxWidth().clip(RoundedCornerShape(13.dp))
            .background(if (danger) Brush.linearGradient(listOf(Color(0xFF8D2626), Color(0xFFB93932))) else Brush.linearGradient(listOf(RaisedSurface, RaisedSurface)))
            .clickable(onClick = onClick).padding(14.dp),
        contentAlignment = Alignment.Center,
    ) {
        Text(label, color = Color.White, fontSize = 13.sp, fontWeight = FontWeight.Bold)
    }
}

@Composable
private fun ModeSelector(mode: BarcodeScanMode, onMode: (BarcodeScanMode) -> Unit) {
    Row(
        Modifier.fillMaxWidth().clip(RoundedCornerShape(15.dp)).background(Color(0xFF111113)).padding(4.dp),
        horizontalArrangement = Arrangement.spacedBy(4.dp),
    ) {
        ModeButton("Single", mode == BarcodeScanMode.Single, Modifier.weight(1f)) { onMode(BarcodeScanMode.Single) }
        ModeButton("Continuous", mode == BarcodeScanMode.Continuous, Modifier.weight(1f)) { onMode(BarcodeScanMode.Continuous) }
        ModeButton("Unique", mode == BarcodeScanMode.ContinuousUnique, Modifier.weight(1f)) { onMode(BarcodeScanMode.ContinuousUnique) }
    }
}

@Composable
private fun ModeButton(label: String, selected: Boolean, modifier: Modifier, onClick: () -> Unit) {
    Box(
        modifier.height(46.dp).clip(RoundedCornerShape(11.dp))
            .background(if (selected) Brush.linearGradient(listOf(IpcBlue, IpcPurple)) else Brush.linearGradient(listOf(Color.Transparent, Color.Transparent)))
            .clickable(onClick = onClick),
        contentAlignment = Alignment.Center,
    ) {
        Text(label, color = if (selected) Color.White else Color(0xFFAAAAAA), fontSize = 12.sp, fontWeight = FontWeight.ExtraBold)
    }
}

@Composable
private fun SymbologyEntry(enabled: Int, total: Int, onClick: () -> Unit) {
    Row(
        Modifier.fillMaxWidth().height(76.dp).clip(RoundedCornerShape(17.dp))
            .background(Brush.linearGradient(listOf(Color(0xFF27272D), Color(0xFF202024))))
            .clickable(onClick = onClick).padding(12.dp),
        verticalAlignment = Alignment.CenterVertically,
        horizontalArrangement = Arrangement.spacedBy(12.dp),
    ) {
        BarcodeGlyph(Modifier.size(46.dp))
        Column(Modifier.weight(1f)) {
            Text("Symbology", color = Color.White, fontSize = 14.sp, fontWeight = FontWeight.Bold)
            Text("$enabled of $total enabled", color = Color(0xFF999999), fontSize = 10.sp, modifier = Modifier.padding(top = 4.dp))
        }
        Text("›", color = IpcGreen, fontSize = 30.sp)
    }
}

@Composable
@OptIn(ExperimentalMaterial3Api::class)
private fun SymbologySheet(
    state: SnapIPCDemoUiState,
    onDismiss: () -> Unit,
    onAllChanged: (Boolean) -> Unit,
    onChanged: (ScannerSymbology, Boolean) -> Unit,
) {
    val sheetState = rememberModalBottomSheetState(skipPartiallyExpanded = true)
    ModalBottomSheet(
        onDismissRequest = onDismiss,
        sheetState = sheetState,
        containerColor = Color(0xFF19191D),
        contentColor = Color.White,
        dragHandle = { Box(Modifier.padding(vertical = 9.dp).size(52.dp, 5.dp).clip(CircleShape).background(Color(0xFF4B4B52))) },
    ) {
        Column(Modifier.fillMaxWidth().heightIn(max = 720.dp).navigationBarsPadding().padding(horizontal = 16.dp)) {
            Row(Modifier.fillMaxWidth().padding(bottom = 17.dp), horizontalArrangement = Arrangement.SpaceBetween, verticalAlignment = Alignment.Top) {
                Column {
                    Text("SCANNER SETTINGS", color = IpcGreen, fontSize = 10.sp, fontWeight = FontWeight.ExtraBold, letterSpacing = 1.2.sp)
                    Text("Symbology", fontSize = 25.sp, fontWeight = FontWeight.Bold)
                    Text("Enable or disable barcode types.", color = Color(0xFF999999), fontSize = 12.sp)
                }
                CloseButton(onDismiss)
            }
            HorizontalDivider(color = Color(0xFF34343A))
            SymbologyRow(
                name = "All Symbologies",
                subtitle = "Toggle every supported barcode type",
                checked = state.allSymbologiesEnabled,
                onChecked = onAllChanged,
                highlighted = true,
            )
            LazyColumn(Modifier.fillMaxWidth().weight(1f), contentPadding = PaddingValues(bottom = 16.dp)) {
                items(state.symbologies, key = { it.id }) { symbology ->
                    SymbologyRow(
                        name = symbology.displayName,
                        checked = state.symbologyEnabled[symbology] ?: true,
                        onChecked = { onChanged(symbology, it) },
                    )
                }
            }
        }
    }
}

@Composable
private fun SymbologyRow(
    name: String,
    checked: Boolean,
    onChecked: (Boolean) -> Unit,
    subtitle: String? = null,
    highlighted: Boolean = false,
) {
    Row(
        modifier = Modifier.fillMaxWidth().heightIn(min = 62.dp)
            .then(if (highlighted) Modifier.padding(top = 10.dp).clip(RoundedCornerShape(15.dp)).background(Color(0xFF24232B)).padding(horizontal = 10.dp) else Modifier)
            .clickable { onChecked(!checked) }
            .padding(vertical = 10.dp, horizontal = 4.dp),
        verticalAlignment = Alignment.CenterVertically,
        horizontalArrangement = Arrangement.spacedBy(18.dp),
    ) {
        Column(Modifier.weight(1f)) {
            Text(name, fontSize = 13.sp, fontWeight = FontWeight.Bold)
            subtitle?.let { Text(it, color = Color(0xFF8F8F96), fontSize = 10.sp, modifier = Modifier.padding(top = 3.dp)) }
        }
        Switch(
            checked = checked,
            onCheckedChange = onChecked,
            colors = SwitchDefaults.colors(
                checkedThumbColor = IpcGreen,
                checkedTrackColor = IpcPurple,
                uncheckedThumbColor = Color(0xFF8B8B92),
                uncheckedTrackColor = Color(0xFF303037),
            ),
        )
    }
    if (!highlighted) HorizontalDivider(color = Color(0xFF2E2E34))
}

private fun Modifier.noRippleClick(onClick: () -> Unit): Modifier = clickable(
    interactionSource = MutableInteractionSource(),
    indication = null,
    onClick = onClick,
)

private fun Double.fixed(decimals: Int): String {
    val scale = if (decimals == 1) 10 else 100
    val scaled = (this * scale).roundToInt()
    val whole = scaled / scale
    val fraction = (scaled % scale).absoluteValue.toString().padStart(decimals, '0')
    return "$whole.$fraction"
}

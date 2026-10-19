import React, {useEffect, useState} from 'react';
import {Image, Modal, Pressable, ScrollView, StatusBar, StyleSheet, Switch, Text, View} from 'react-native';
import {SafeAreaProvider, SafeAreaView} from 'react-native-safe-area-context';
import {ScanMode, SnapIPCState, useSnapIPC} from './snapipc';

const green = '#65D007';
const purple = '#6F24FC';
const blue = '#357AFE';
const dark = '#151515';
const images = {
  waiting: require('./assets/snapipc_no_connection.png'),
  connected: require('./assets/snapipc_connected.png'),
  valid: require('./assets/snapipc_valid_barcode.png'),
};

function status(state: SnapIPCState): string {
  if (state.connection === 'Connected') return state.scanFeedback ? 'Valid barcode' : 'Connected';
  return ({WaitingForNfc: 'Awaiting NFC pairing', RequestingBluetooth: 'Requesting Bluetooth',
    Scanning: 'Finding scanner', Connecting: 'Connecting', DiscoveringServices: 'Preparing scanner',
    Reconnecting: 'Reconnecting', Error: 'Connection failed'} as Record<string, string>)[state.connection] ?? 'Connecting';
}

function Stage({state}: {state: SnapIPCState}) {
  const image = state.connection === 'Connected' ? (state.scanFeedback ? images.valid : images.connected) : images.waiting;
  const battery = state.battery;
  return <View style={s.stage}>
    <Image source={image} resizeMode="cover" style={s.stageImage} />
    <View style={s.statusPill}>
      <View style={[s.dot, state.connection === 'Connected' && s.dotConnected]} />
      <Text style={s.statusText}>{status(state).toUpperCase()}</Text>
    </View>
    {battery && <View style={s.battery}>
      <Text style={s.batteryTitle}>{battery.stateOfCharge}% {battery.isCharging ? ' · CHARGING' : ''}</Text>
      <Text style={s.batteryText}>{battery.voltage.toFixed(2)} V  ·  {battery.remainingCapacityMah} mAh  ·  {battery.temperatureCelsius.toFixed(1)} °C</Text>
      <Text style={s.batteryText}>FIRMWARE {state.firmware ?? '—'}{state.scannerFirmware ? `  ·  SCANNER ${state.scannerFirmware}` : ''}</Text>
    </View>}
  </View>;
}

function Result({state}: {state: SnapIPCState}) {
  const scan = state.lastScan;
  if (!scan) {
    const waiting = state.connection !== 'Connected';
    return <View style={s.emptyCard}>
      <Text style={s.barcodeGlyph}>▥</Text>
      <View style={s.flex}>
        <Text style={s.emptyTitle}>{state.connection === 'Error' ? 'Could not connect' : waiting ? 'Ready to pair' : 'Ready to scan'}</Text>
        <Text style={s.emptyMessage}>{waiting ? state.error ?? 'Hold the phone near the scanner NFC pairing point.' : 'The next barcode will appear here.'}</Text>
      </View>
    </View>;
  }
  return <View style={s.resultCard}>
    <View style={s.resultNumber}><Text style={s.resultNumberText}>{scan.sequence}</Text></View>
    <View style={s.resultBody}>
      <View style={s.row}><View style={s.flex}><Text style={s.label}>BARCODE</Text><Text style={s.resultValue} selectable numberOfLines={2}>{scan.value}</Text></View><Text style={s.valid}>VALID</Text></View>
      <View style={s.rule} />
      <View style={s.row}><View style={s.flex}><Text style={s.label}>SYMBOLOGY</Text><Text style={s.meta}>{scan.symbology}</Text></View>
        <View style={s.flex}><Text style={s.label}>DATE</Text><Text style={s.meta}>{scan.date}</Text><Text style={s.label}>TIME</Text><Text style={s.meta}>{scan.time}</Text></View></View>
    </View>
  </View>;
}

function Section({title, hint, children}: {title: string; hint?: string; children: React.ReactNode}) {
  return <View style={s.section}><Text style={s.sectionTitle}>{title.toUpperCase()}</Text>{hint && <Text style={s.hint}>{hint}</Text>}{children}</View>;
}

function Close({onPress}: {onPress: () => void}) {
  return <Pressable onPress={onPress} style={s.close} accessibilityRole="button" accessibilityLabel="Close"><Text style={s.closeText}>×</Text></Pressable>;
}

function Settings({visible, state, onClose, onDisconnect, onMode, onFormats}: {
  visible: boolean; state: SnapIPCState; onClose: () => void; onDisconnect: () => void;
  onMode: (mode: ScanMode) => void; onFormats: () => void;
}) {
  const modes: {label: string; mode: ScanMode}[] = [
    {label: 'Single', mode: 'Single'}, {label: 'Continuous', mode: 'Continuous'}, {label: 'Unique', mode: 'ContinuousUnique'},
  ];
  const enabledCount = state.symbologies.filter(format => state.enabled[String(format.id)] ?? true).length;
  return <Modal visible={visible} transparent animationType="fade" onRequestClose={onClose}>
    <View style={s.drawerRoot}>
      <Pressable style={s.backdrop} onPress={onClose} accessibilityLabel="Close menu" />
      <SafeAreaView edges={['top', 'bottom']} style={s.drawer}>
        <ScrollView contentContainerStyle={s.drawerInner}>
          <View style={s.heading}><View><Text style={s.eyebrow}>SNAPIPC</Text><Text style={s.drawerTitle}>Menu</Text></View><Close onPress={onClose} /></View>
          {(state.connection === 'Connected' || state.connection === 'Reconnecting') && <Section title="Connection" hint="Disconnect this scanner and require another NFC tap to pair again.">
            <Pressable style={s.dangerButton} onPress={onDisconnect} accessibilityRole="button"><Text style={s.whiteBold}>Disconnect & Unpair</Text></Pressable>
          </Section>}
          <Section title="Scan mode" hint="Choose whether the scanner stops after one barcode or keeps scanning.">
            <View style={s.modeGroup}>{modes.map(item => <Pressable key={item.mode} style={[s.mode, state.mode === item.mode && s.modeSelected]} disabled={state.connection !== 'Connected'} onPress={() => onMode(item.mode)} accessibilityRole="button" accessibilityState={{selected: state.mode === item.mode}}><Text style={s.whiteBold}>{item.label}</Text></Pressable>)}</View>
          </Section>
          <Section title="Barcode types"><Pressable style={s.formatsEntry} onPress={onFormats} disabled={state.connection !== 'Connected'} accessibilityRole="button"><Text style={s.formatsIcon}>▥</Text><View style={s.flex}><Text style={s.whiteBold}>Symbology</Text><Text style={s.muted}>{enabledCount} of {state.symbologies.length} enabled</Text></View><Text style={s.chevron}>›</Text></Pressable></Section>
        </ScrollView>
      </SafeAreaView>
    </View>
  </Modal>;
}

function Formats({visible, state, onClose, onAll, onOne}: {
  visible: boolean; state: SnapIPCState; onClose: () => void;
  onAll: (enabled: boolean) => void; onOne: (id: number, enabled: boolean) => void;
}) {
  const all = state.symbologies.length > 0 && state.symbologies.every(format => state.enabled[String(format.id)] ?? true);
  return <Modal visible={visible} transparent animationType="slide" onRequestClose={onClose}>
    <View style={s.sheetRoot}><Pressable style={s.backdrop} onPress={onClose} accessibilityLabel="Close symbologies" />
      <SafeAreaView edges={['bottom']} style={s.sheet}>
        <View style={s.handle} />
        <View style={s.heading}><View><Text style={s.eyebrow}>SCANNER SETTINGS</Text><Text style={s.sheetTitle}>Symbology</Text><Text style={s.muted}>Enable or disable barcode types.</Text></View><Close onPress={onClose} /></View>
        <View style={[s.formatRow, s.allRow]}><View style={s.flex}><Text style={s.whiteBold}>All Symbologies</Text><Text style={s.muted}>Toggle every supported barcode type</Text></View><Switch value={all} onValueChange={onAll} disabled={state.connection !== 'Connected'} trackColor={{true: purple}} thumbColor={green} /></View>
        <ScrollView>{state.symbologies.map(format => <View key={format.id} style={s.formatRow}><Text style={[s.whiteBold, s.flex]}>{format.name}</Text><Switch value={state.enabled[String(format.id)] ?? true} onValueChange={value => onOne(format.id, value)} disabled={state.connection !== 'Connected'} trackColor={{true: purple}} thumbColor={green} /></View>)}</ScrollView>
      </SafeAreaView>
    </View>
  </Modal>;
}

function Content() {
  const {state, startPairing, toggleScan, disconnect, setMode, setSymbology, setAllSymbologies} = useSnapIPC();
  const [splash, setSplash] = useState(true);
  const [menu, setMenu] = useState(false);
  const [formats, setFormats] = useState(false);
  useEffect(() => {
    const timer = setTimeout(() => { setSplash(false); startPairing(); }, 1800);
    return () => clearTimeout(timer);
  }, [startPairing]);
  if (splash) return <Image source={require('./assets/snapipc_loading_screen.png')} resizeMode="cover" style={s.splash} accessibilityLabel="SnapIPC loading" />;
  const readyToPair = state.connection === 'WaitingForNfc' || state.connection === 'Error';
  const enabled = readyToPair || (state.connection === 'Connected' && !state.commandPending);
  const button = readyToPair ? 'Ready to Pair' : state.connection !== 'Connected' ? 'Connecting…' : state.softScanning ? 'Stop Scan' : 'Start Scan';
  return <SafeAreaView style={s.root} edges={['top', 'bottom']}>
    <View style={s.header}><Image source={require('./assets/snapipc_wordmark.png')} resizeMode="contain" style={s.wordmark} accessibilityLabel="SnapIPC" /><Pressable style={s.menuButton} onPress={() => setMenu(true)} accessibilityRole="button" accessibilityLabel="Open menu"><Text style={s.menuGlyph}>☰</Text></Pressable></View>
    <ScrollView style={s.flex} contentContainerStyle={s.content}><Stage state={state} /><Result state={state} />{state.error && state.connection === 'Connected' && <Text style={s.error}>{state.error}</Text>}</ScrollView>
    <Pressable onPress={readyToPair ? startPairing : toggleScan} disabled={!enabled} style={[s.scanButton, state.softScanning && s.stopButton, !enabled && s.disabledButton]} accessibilityRole="button" accessibilityState={{disabled: !enabled}}><Text style={s.scanButtonText}>{button}</Text></Pressable>
    <Settings visible={menu} state={state} onClose={() => setMenu(false)} onDisconnect={() => {setMenu(false); disconnect();}} onMode={setMode} onFormats={() => {setMenu(false); setFormats(true);}} />
    <Formats visible={formats} state={state} onClose={() => setFormats(false)} onAll={setAllSymbologies} onOne={setSymbology} />
  </SafeAreaView>;
}

export default function SnapIPCApp() {
  return <SafeAreaProvider><StatusBar barStyle="light-content" /><Content /></SafeAreaProvider>;
}

const s = StyleSheet.create({
  flex: {flex: 1}, root: {flex: 1, backgroundColor: dark}, splash: {width: '100%', height: '100%'},
  header: {height: 68, backgroundColor: '#FFF', flexDirection: 'row', alignItems: 'center', justifyContent: 'space-between', paddingHorizontal: 18},
  wordmark: {width: '72%', height: 50}, menuButton: {width: 48, height: 48, backgroundColor: '#F2F2F2', borderRadius: 14, alignItems: 'center', justifyContent: 'center'}, menuGlyph: {color: '#151515', fontSize: 22},
  content: {paddingHorizontal: 16, paddingVertical: 14, gap: 14}, stage: {height: 390, borderRadius: 30, overflow: 'hidden', backgroundColor: '#0B0B0C'}, stageImage: {position: 'absolute', width: '100%', height: '100%', borderRadius: 30},
  statusPill: {position: 'absolute', top: 15, left: 15, backgroundColor: '#121214E0', borderRadius: 50, paddingHorizontal: 12, paddingVertical: 9, flexDirection: 'row', alignItems: 'center', gap: 8}, dot: {width: 9, height: 9, borderRadius: 5, backgroundColor: '#888'}, dotConnected: {backgroundColor: green}, statusText: {color: '#FFF', fontSize: 11, fontWeight: '800'},
  battery: {position: 'absolute', left: 15, right: 15, top: 55, padding: 10, borderRadius: 15, backgroundColor: '#121214E8'}, batteryTitle: {color: '#FFF', fontSize: 14, fontWeight: '700'}, batteryText: {color: '#C7C7CA', fontSize: 9, marginTop: 5},
  emptyCard: {minHeight: 116, borderRadius: 25, backgroundColor: '#FFF', padding: 20, flexDirection: 'row', alignItems: 'center', gap: 15}, barcodeGlyph: {color: purple, fontSize: 42}, emptyTitle: {color: '#171717', fontSize: 16, fontWeight: '700'}, emptyMessage: {color: '#666', fontSize: 13, lineHeight: 18, marginTop: 4},
  resultCard: {minHeight: 150, borderRadius: 25, overflow: 'hidden', backgroundColor: '#FFF', flexDirection: 'row'}, resultNumber: {width: 108, backgroundColor: purple, alignItems: 'center', justifyContent: 'center', borderRightWidth: 6, borderRightColor: green}, resultNumberText: {color: '#FFF', fontSize: 50, fontWeight: '900'}, resultBody: {flex: 1, paddingHorizontal: 16, paddingVertical: 15}, row: {flexDirection: 'row', gap: 10}, label: {fontSize: 9, fontWeight: '900', color: '#737373', letterSpacing: 0.7}, resultValue: {fontSize: 21, fontWeight: '700', color: '#171717'}, valid: {color: '#3F8D00', backgroundColor: '#EAF9DF', borderRadius: 50, paddingHorizontal: 8, paddingVertical: 5, fontSize: 9, fontWeight: '900'}, rule: {height: 1, backgroundColor: '#DDD', marginVertical: 10}, meta: {color: '#171717', fontSize: 12, fontWeight: '600'}, error: {color: '#FFB25E', fontSize: 13},
  scanButton: {height: 58, marginHorizontal: 16, marginVertical: 14, borderRadius: 17, alignItems: 'center', justifyContent: 'center', backgroundColor: blue}, stopButton: {backgroundColor: '#B93932'}, disabledButton: {backgroundColor: '#444449'}, scanButtonText: {color: '#FFF', fontSize: 16, fontWeight: '700'},
  drawerRoot: {flex: 1, flexDirection: 'row', justifyContent: 'flex-end'}, backdrop: {position: 'absolute', top: 0, right: 0, bottom: 0, left: 0, backgroundColor: '#0009'}, drawer: {height: '100%', width: '88%', maxWidth: 390, backgroundColor: '#19191B'}, drawerInner: {paddingHorizontal: 20, paddingVertical: 22}, heading: {flexDirection: 'row', justifyContent: 'space-between', alignItems: 'flex-start', marginBottom: 24}, eyebrow: {color: green, fontSize: 10, fontWeight: '900', letterSpacing: 1.4}, drawerTitle: {color: '#FFF', fontSize: 30, fontWeight: '700'}, close: {width: 44, height: 44, borderRadius: 13, backgroundColor: '#2C2C30', alignItems: 'center', justifyContent: 'center'}, closeText: {color: '#FFF', fontSize: 30},
  section: {borderTopWidth: 1, borderTopColor: '#333338', paddingVertical: 19}, sectionTitle: {color: '#FFF', fontSize: 13, fontWeight: '900', letterSpacing: 0.7}, hint: {color: '#AAA', fontSize: 12, lineHeight: 17, marginTop: 5, marginBottom: 14}, dangerButton: {height: 48, borderRadius: 13, backgroundColor: '#B93932', alignItems: 'center', justifyContent: 'center'}, whiteBold: {color: '#FFF', fontSize: 13, fontWeight: '700'}, muted: {color: '#999', fontSize: 10, marginTop: 4}, modeGroup: {flexDirection: 'row', gap: 4, backgroundColor: '#111113', borderRadius: 15, padding: 4}, mode: {flex: 1, height: 46, borderRadius: 11, alignItems: 'center', justifyContent: 'center'}, modeSelected: {backgroundColor: purple}, formatsEntry: {height: 76, borderRadius: 17, backgroundColor: '#27272D', padding: 12, flexDirection: 'row', alignItems: 'center', gap: 12}, formatsIcon: {fontSize: 36, color: purple}, chevron: {color: green, fontSize: 30},
  sheetRoot: {flex: 1, justifyContent: 'flex-end'}, sheet: {height: '78%', backgroundColor: '#19191D', borderTopLeftRadius: 24, borderTopRightRadius: 24, paddingHorizontal: 16}, handle: {width: 52, height: 5, borderRadius: 5, backgroundColor: '#4B4B52', alignSelf: 'center', marginVertical: 9}, sheetTitle: {fontSize: 25, fontWeight: '700', color: '#FFF'}, formatRow: {minHeight: 62, borderBottomWidth: 1, borderBottomColor: '#2E2E34', paddingHorizontal: 4, paddingVertical: 10, flexDirection: 'row', alignItems: 'center', gap: 18}, allRow: {backgroundColor: '#24232B', borderRadius: 15, marginBottom: 10, paddingHorizontal: 14},
});

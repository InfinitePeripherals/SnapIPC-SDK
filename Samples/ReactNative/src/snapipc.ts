import {NativeEventEmitter, NativeModules} from 'react-native';
import {useCallback, useEffect, useRef, useState} from 'react';

export type Connection =
  | 'WaitingForNfc'
  | 'RequestingBluetooth'
  | 'Scanning'
  | 'Connecting'
  | 'DiscoveringServices'
  | 'Connected'
  | 'Reconnecting'
  | 'Error';

export type ScanMode = 'Single' | 'Continuous' | 'ContinuousUnique';

export type Symbology = {id: number; name: string};
export type Battery = {
  stateOfCharge: number;
  voltage: number;
  remainingCapacityMah: number;
  temperatureCelsius: number;
  isCharging: boolean;
};
export type Scan = {
  sequence: number;
  value: string;
  symbology: string;
  date: string;
  time: string;
};

type Snapshot = {
  connection: Connection;
  symbologies: Symbology[];
  battery?: Battery;
};

type Event =
  | {type: 'connection'; connection: Connection; message?: string}
  | {type: 'barcode'; value: string; symbology: string}
  | {type: 'battery'; battery: Battery}
  | {type: 'firmware'; firmware?: string; scannerFirmware?: string}
  | {type: 'details'; mode: ScanMode; enabled: Record<string, boolean>}
  | {type: 'error'; message: string};

type NativeSnapIPC = {
  getSnapshot(): Promise<Snapshot>;
  startPairing(): Promise<void>;
  disconnect(): Promise<void>;
  startScan(): Promise<void>;
  stopScan(): Promise<void>;
  setScanMode(mode: ScanMode): Promise<void>;
  setSymbology(id: number, enabled: boolean): Promise<void>;
  setAllSymbologies(enabled: boolean): Promise<void>;
  addListener(eventName: string): void;
  removeListeners(count: number): void;
};

const native = NativeModules.SnapIPCModule as NativeSnapIPC | undefined;

export type SnapIPCState = {
  connection: Connection;
  error: string | null;
  battery: Battery | null;
  firmware: string | null;
  scannerFirmware: string | null;
  mode: ScanMode;
  symbologies: Symbology[];
  enabled: Record<string, boolean>;
  lastScan: Scan | null;
  softScanning: boolean;
  commandPending: boolean;
  scanFeedback: boolean;
};

const initialState: SnapIPCState = {
  connection: 'WaitingForNfc',
  error: null,
  battery: null,
  firmware: null,
  scannerFirmware: null,
  mode: 'Single',
  symbologies: [],
  enabled: {},
  lastScan: null,
  softScanning: false,
  commandPending: false,
  scanFeedback: false,
};

function errorMessage(error: unknown): string {
  return error instanceof Error ? error.message : String(error);
}

export function useSnapIPC() {
  const [state, setState] = useState<SnapIPCState>(initialState);
  const stateRef = useRef(state);
  const sawConnectionEvent = useRef(false);
  const feedbackTimer = useRef<ReturnType<typeof setTimeout> | null>(null);
  stateRef.current = state;

  const setError = useCallback((error: unknown) => {
    setState(previous => ({...previous, error: errorMessage(error)}));
  }, []);

  useEffect(() => {
    if (!native) {
      setError('SnapIPC native module is unavailable. Rebuild the app after installing native dependencies.');
      return;
    }
    const emitter = new NativeEventEmitter(native);
    const subscription = emitter.addListener('SnapIPCEvent', payload => {
      const event = payload as Event;
      if (event.type === 'connection') {
        sawConnectionEvent.current = true;
        setState(previous => event.connection === 'Connected'
          ? {...previous, connection: event.connection, error: event.message ?? null}
          : {
              ...previous,
              connection: event.connection,
              error: event.message ?? null,
              battery: null,
              firmware: null,
              scannerFirmware: null,
              lastScan: null,
              softScanning: false,
              commandPending: false,
              scanFeedback: false,
            });
      } else if (event.type === 'barcode') {
        const now = new Date();
        setState(previous => ({
          ...previous,
          lastScan: {
            sequence: (previous.lastScan?.sequence ?? 0) + 1,
            value: event.value,
            symbology: event.symbology,
            date: now.toLocaleDateString(undefined, {month: 'short', day: 'numeric', year: 'numeric'}),
            time: now.toLocaleTimeString(),
          },
          scanFeedback: true,
        }));
        if (feedbackTimer.current) clearTimeout(feedbackTimer.current);
        feedbackTimer.current = setTimeout(() => {
          setState(previous => ({...previous, scanFeedback: false}));
        }, 1600);
        if (stateRef.current.mode === 'Single' && stateRef.current.softScanning) {
          native.stopScan().then(() => {
            setState(previous => ({...previous, softScanning: false}));
          }).catch(setError);
        }
      } else if (event.type === 'battery') {
        setState(previous => ({...previous, battery: event.battery}));
      } else if (event.type === 'firmware') {
        setState(previous => ({
          ...previous,
          firmware: event.firmware ?? previous.firmware,
          scannerFirmware: event.scannerFirmware ?? previous.scannerFirmware,
        }));
      } else if (event.type === 'details') {
        setState(previous => ({...previous, mode: event.mode, enabled: event.enabled}));
      } else if (event.type === 'error') {
        setState(previous => ({...previous, error: event.message}));
      }
    });

    native.getSnapshot().then(snapshot => {
      setState(previous => ({
        ...previous,
        connection: sawConnectionEvent.current ? previous.connection : snapshot.connection,
        symbologies: snapshot.symbologies,
        enabled: Object.keys(previous.enabled).length > 0
          ? previous.enabled
          : Object.fromEntries(snapshot.symbologies.map(format => [String(format.id), true])),
        battery: snapshot.battery ?? previous.battery,
      }));
    }).catch(setError);

    return () => {
      subscription.remove();
      if (feedbackTimer.current) clearTimeout(feedbackTimer.current);
    };
  }, [setError]);

  const startPairing = useCallback(async () => {
    if (!native) return;
    try {
      await native.startPairing();
      setState(previous => ({...previous, error: null}));
    } catch (error) {
      setError(error);
    }
  }, [setError]);

  const toggleScan = useCallback(async () => {
    if (!native || stateRef.current.connection !== 'Connected' || stateRef.current.commandPending) return;
    const start = !stateRef.current.softScanning;
    setState(previous => ({...previous, commandPending: true}));
    try {
      if (start) await native.startScan();
      else await native.stopScan();
      setState(previous => ({
        ...previous,
        softScanning: previous.connection === 'Connected' ? start : false,
        commandPending: false,
        error: null,
      }));
    } catch (error) {
      setState(previous => ({...previous, commandPending: false}));
      setError(error);
    }
  }, [setError]);

  const disconnect = useCallback(async () => {
    if (!native) return;
    try {
      await native.disconnect();
      setState(previous => ({...previous, connection: 'WaitingForNfc', lastScan: null, softScanning: false}));
      await startPairing();
    } catch (error) {
      setError(error);
    }
  }, [setError, startPairing]);

  const setMode = useCallback(async (mode: ScanMode) => {
    if (!native || stateRef.current.connection !== 'Connected') return;
    try {
      await native.setScanMode(mode);
      setState(previous => ({...previous, mode, error: null}));
    } catch (error) {
      setError(error);
    }
  }, [setError]);

  const setSymbology = useCallback(async (id: number, enabled: boolean) => {
    if (!native || stateRef.current.connection !== 'Connected') return;
    try {
      await native.setSymbology(id, enabled);
      setState(previous => ({...previous, enabled: {...previous.enabled, [String(id)]: enabled}, error: null}));
    } catch (error) {
      setError(error);
    }
  }, [setError]);

  const setAllSymbologies = useCallback(async (enabled: boolean) => {
    if (!native || stateRef.current.connection !== 'Connected') return;
    try {
      await native.setAllSymbologies(enabled);
      setState(previous => ({
        ...previous,
        enabled: Object.fromEntries(previous.symbologies.map(format => [String(format.id), enabled])),
        error: null,
      }));
    } catch (error) {
      setError(error);
    }
  }, [setError]);

  return {state, startPairing, toggleScan, disconnect, setMode, setSymbology, setAllSymbologies};
}

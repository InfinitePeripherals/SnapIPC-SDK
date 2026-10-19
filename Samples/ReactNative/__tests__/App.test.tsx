import React from 'react';
import ReactTestRenderer from 'react-test-renderer';
import {DeviceEventEmitter, NativeModules} from 'react-native';

jest.mock('react-native-safe-area-context', () => {
  const {View} = require('react-native');
  return {SafeAreaProvider: View, SafeAreaView: View};
});

const startPairing = jest.fn(() => Promise.resolve());
NativeModules.SnapIPCModule = {
  addListener: jest.fn(),
  removeListeners: jest.fn(),
  getSnapshot: jest.fn(() => Promise.resolve({connection: 'WaitingForNfc', symbologies: []})),
  startPairing,
  disconnect: jest.fn(() => Promise.resolve()),
  startScan: jest.fn(() => Promise.resolve()),
  stopScan: jest.fn(() => Promise.resolve()),
  setScanMode: jest.fn(() => Promise.resolve()),
  setSymbology: jest.fn(() => Promise.resolve()),
  setAllSymbologies: jest.fn(() => Promise.resolve()),
};

const App = require('../App').default;

test('pairs after the splash and shows the scan action after connection', async () => {
  let tree!: ReactTestRenderer.ReactTestRenderer;
  await ReactTestRenderer.act(async () => {
    tree = ReactTestRenderer.create(<App />);
  });

  await ReactTestRenderer.act(async () => {
    await new Promise<void>(resolve => setTimeout(resolve, 1850));
  });
  expect(tree.root.findAllByProps({children: 'Ready to Pair'}).length).toBeGreaterThan(0);
  expect(startPairing).toHaveBeenCalledTimes(1);

  await ReactTestRenderer.act(async () => {
    DeviceEventEmitter.emit('SnapIPCEvent', {type: 'connection', connection: 'Connected'});
  });
  expect(tree.root.findAllByProps({children: 'Start Scan'}).length).toBeGreaterThan(0);

  await ReactTestRenderer.act(async () => tree.unmount());
});

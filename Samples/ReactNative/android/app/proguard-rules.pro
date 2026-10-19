# React Native invokes bridge methods by their @ReactMethod annotations.
-keepclassmembers class com.ipcmobile.snapipc.reactnative.SnapIPCModule {
    @com.facebook.react.bridge.ReactMethod <methods>;
}

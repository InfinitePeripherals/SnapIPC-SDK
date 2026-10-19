package com.ipcmobile.snapipc.reactnative

import android.os.Bundle
import com.facebook.react.ReactActivity
import com.facebook.react.ReactActivityDelegate
import com.facebook.react.defaults.DefaultNewArchitectureEntryPoint.fabricEnabled
import com.facebook.react.defaults.DefaultReactActivityDelegate
import com.ipcmobile.snapipcsdk.android.SnapHaloAndroid

class MainActivity : ReactActivity() {
  private var snapHaloAndroid: SnapHaloAndroid? = null

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    snapHaloAndroid = SnapHaloAndroid(this, SnapIPCSession.halo) { message ->
      SnapIPCSession.reportError(message)
    }
    SnapIPCSession.adapter = snapHaloAndroid
  }

  override fun onDestroy() {
    SnapIPCSession.adapter = null
    snapHaloAndroid?.close()
    snapHaloAndroid = null
    super.onDestroy()
  }

  /**
   * Returns the name of the main component registered from JavaScript. This is used to schedule
   * rendering of the component.
   */
  override fun getMainComponentName(): String = "SnapIPCReactNative"

  /**
   * Returns the instance of the [ReactActivityDelegate]. We use [DefaultReactActivityDelegate]
   * which allows you to enable New Architecture with a single boolean flags [fabricEnabled]
   */
  override fun createReactActivityDelegate(): ReactActivityDelegate =
      DefaultReactActivityDelegate(this, mainComponentName, fabricEnabled)
}

package com.ipcmobile.snapipc.reactnative

import com.ipcmobile.snapipcsdk.SnapHalo
import com.ipcmobile.snapipcsdk.android.SnapHaloAndroid

internal object SnapIPCSession {
  val halo = SnapHalo()
  var adapter: SnapHaloAndroid? = null
  var errorSink: ((String) -> Unit)? = null

  fun reportError(message: String) {
    errorSink?.invoke(message)
  }
}

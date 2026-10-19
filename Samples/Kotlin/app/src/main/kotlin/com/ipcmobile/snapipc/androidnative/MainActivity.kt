package com.ipcmobile.snapipc.androidnative

import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.core.view.WindowCompat


import com.ipcmobile.snapipcsdk.android.SnapHaloAndroid

class MainActivity : ComponentActivity() {
    private val controller by lazy {
        SnapIPCDemoController(cancelPendingPairing = { snapHaloAndroid.cancelPendingConnection() })
    }
    private lateinit var snapHaloAndroid: SnapHaloAndroid

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        WindowCompat.setDecorFitsSystemWindows(window, false)
        snapHaloAndroid = SnapHaloAndroid(
            activity = this,
            snapHalo = controller.snapHalo,
            onError = { message -> Toast.makeText(this, message, Toast.LENGTH_LONG).show() },
        )
        setContent {
            SnapIPCDemoApp(controller = controller)
        }
    }

    override fun onDestroy() {
        snapHaloAndroid.close()
        controller.close()
        super.onDestroy()
    }
}

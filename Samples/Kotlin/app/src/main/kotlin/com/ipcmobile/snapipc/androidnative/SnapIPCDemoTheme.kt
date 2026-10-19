package com.ipcmobile.snapipc.androidnative

import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.darkColorScheme
import androidx.compose.runtime.Composable
import androidx.compose.ui.graphics.Color

internal val IpcGreen = Color(0xFF65D007)
internal val IpcBlue = Color(0xFF357AFE)
internal val IpcPurple = Color(0xFF6F24FC)
internal val Surface = Color(0xFF151515)
internal val RaisedSurface = Color(0xFF242424)
internal val InvalidRed = Color(0xFFFF321C)

@Composable
internal fun SnapIPCTheme(content: @Composable () -> Unit) {
    MaterialTheme(
        colorScheme = darkColorScheme(
            primary = IpcPurple,
            secondary = IpcGreen,
            background = Surface,
            surface = RaisedSurface,
            onPrimary = Color.White,
            onBackground = Color.White,
            onSurface = Color.White,
        ),
        content = content,
    )
}

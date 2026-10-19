package com.ipcmobile.snapipc.androidnative

import java.text.SimpleDateFormat
import java.util.Date
import java.util.Locale

internal fun currentDateTimeLabels(): DateTimeLabels {
    val now = Date()
    val locale = Locale.getDefault()
    return DateTimeLabels(
        date = SimpleDateFormat("MMM d, yyyy", locale).format(now),
        time = SimpleDateFormat("h:mm:ss a", locale).format(now),
    )
}

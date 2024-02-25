#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define SPLIT_USB_DETECT

#define SPLIT_USB_TIMEOUT 1500
#define SPLIT_USB_TIMEOUT_POLL 10

#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 2000

#define DEBOUNCE 10

#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
#endif
#define ENCODER_RESOLUTION 4
#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define EE_HANDS

#define MASTER_RIGHT
#define SPLIT_USB_DETECT

#define SPLIT_MAX_CONNECTION_ERRORS 10

#define SPLIT_CONNECTION_CHECK_TIMEOUT 5000

// #define SPLIT_USB_TIMEOUT 1500
// #define SPLIT_USB_TIMEOUT_POLL 10

// #define SPLIT_WATCHDOG_ENABLE
// #define SPLIT_WATCHDOG_TIMEOUT 2000

// #define DEBOUNCE 10
#define DEBOUNCE 5

#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
#endif
#define ENCODER_RESOLUTION 4

// in order to sync OLED display of the currently active layer
// #define SPLIT_LAYER_STATE_ENABLE
// sync caps lock state
// #define SPLIT_MODS_ENABLE
// #define SPLIT_HAPTIC_ENABLE


// #define EXTRA_SHORT_COMBOS
// #define COMBO_TERM 40
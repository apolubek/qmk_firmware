// #include "ds1307.h"
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// enum custom_keycodes {
//     // KC_QWERTY = SAFE_RANGE,
//     // KC_PRVWD,
//     // KC_NXTWD,
//     // KC_LSTRT,
//     // KC_LEND,
//     // KC_DLINE
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_NO,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_MISSION_CONTROL,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL, MO(_LOWER), KC_SPC,      KC_ENT,  MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
//   _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_BSPC,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, _______,   KC_UP, _______,_______, KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
//   _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, _______, XXXXXXX, _______,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|    |QWERTY|      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT  , XXXXXXX,XXXXXXX,XXXXXXX,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   QK_BOOT  , XXXXXXX,KC_QWERTY,XXXXXXX,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE


    // static bool i2c_delayed = false;
    // static uint32_t last_update = 0;
    // static uint8_t hours, minutes, seconds;
    // static i2c_status_t status = I2C_STATUS_TIMEOUT;
    // static uint32_t start_time = timer_read32();

    // void matrix_scan_user(void) {
    //     // if (is_keyboard_master()) {
    //     //     return;
    //     // }
    //     uint32_t now = timer_read32();

    //     if (!i2c_delayed && now > timer_elapsed32(start_time) > SPLIT_CONNECTION_CHECK_TIMEOUT) {
    //         i2c_delayed = true;
    //     }
    //     else if (i2c_delayed && now - last_update > 500) {
    //         status = ds1307_get_time(&hours, &minutes, &seconds);
    //         last_update = now;
    //     }
    // }

    static void render_slave(void) {
        oled_write_P(PSTR("\n\n"), false);
        oled_write_ln_P(PSTR("Left"), false);
        // oled_write_ln_P(status == I2C_STATUS_ERROR ? PSTR("err") : status == I2C_STATUS_TIMEOUT ? PSTR("timeout") : PSTR("succs"), false);

        // if (status == I2C_STATUS_SUCCESS) {
        //     oled_write_ln_P(PSTR("TIME"), false);

        //     char buf[16];
        //     sprintf(
        //             buf,
        //             "%02d:%02d:%02d", hours, minutes, seconds
        //     );
        //     oled_write(buf, false);
        // }
    }

    // #else
    // static void render_slave(void) {
    //     static const char PROGMEM qmk_logo[] = {
    //         0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    //         0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    //         0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    //     };

    //     oled_write_P(qmk_logo, false);
    // }

    // #endif


static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    // if (status == I2C_STATUS_SUCCESS) {
    //     char buf[16];
    //     sprintf(
    //             buf,
    //             "%02d:%02d:%02d", hours, minutes, seconds
    //     );
    //     oled_write(buf, false);
    // }
    // oled_write_ln_P(status == I2C_STATUS_ERROR ? PSTR("err") : status == I2C_STATUS_TIMEOUT ? PSTR("timeout") : PSTR("succs"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_slave();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case KC_QWERTY:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_QWERTY);
        //     }
        //     return false;
        // case KC_PRVWD:
        //     if (record->event.pressed) {
        //         if (keymap_config.swap_lctl_lgui) {
        //             register_mods(mod_config(MOD_LALT));
        //             register_code(KC_LEFT);
        //         } else {
        //             register_mods(mod_config(MOD_LCTL));
        //             register_code(KC_LEFT);
        //         }
        //     } else {
        //         if (keymap_config.swap_lctl_lgui) {
        //             unregister_mods(mod_config(MOD_LALT));
        //             unregister_code(KC_LEFT);
        //         } else {
        //             unregister_mods(mod_config(MOD_LCTL));
        //             unregister_code(KC_LEFT);
        //         }
        //     }
        //     break;
        // case KC_NXTWD:
        //      if (record->event.pressed) {
        //         if (keymap_config.swap_lctl_lgui) {
        //             register_mods(mod_config(MOD_LALT));
        //             register_code(KC_RIGHT);
        //         } else {
        //             register_mods(mod_config(MOD_LCTL));
        //             register_code(KC_RIGHT);
        //         }
        //     } else {
        //         if (keymap_config.swap_lctl_lgui) {
        //             unregister_mods(mod_config(MOD_LALT));
        //             unregister_code(KC_RIGHT);
        //         } else {
        //             unregister_mods(mod_config(MOD_LCTL));
        //             unregister_code(KC_RIGHT);
        //         }
        //     }
        //     break;
        // case KC_LSTRT:
        //     if (record->event.pressed) {
        //         if (keymap_config.swap_lctl_lgui) {
        //              //CMD-arrow on Mac, but we have CTL and GUI swapped
        //             register_mods(mod_config(MOD_LCTL));
        //             register_code(KC_LEFT);
        //         } else {
        //             register_code(KC_HOME);
        //         }
        //     } else {
        //         if (keymap_config.swap_lctl_lgui) {
        //             unregister_mods(mod_config(MOD_LCTL));
        //             unregister_code(KC_LEFT);
        //         } else {
        //             unregister_code(KC_HOME);
        //         }
        //     }
        //     break;
        // case KC_LEND:
        //     if (record->event.pressed) {
        //         if (keymap_config.swap_lctl_lgui) {
        //             //CMD-arrow on Mac, but we have CTL and GUI swapped
        //             register_mods(mod_config(MOD_LCTL));
        //             register_code(KC_RIGHT);
        //         } else {
        //             register_code(KC_END);
        //         }
        //     } else {
        //         if (keymap_config.swap_lctl_lgui) {
        //             unregister_mods(mod_config(MOD_LCTL));
        //             unregister_code(KC_RIGHT);
        //         } else {
        //             unregister_code(KC_END);
        //         }
        //     }
        //     break;
        // case KC_DLINE:
        //     if (record->event.pressed) {
        //         register_mods(mod_config(MOD_LCTL));
        //         register_code(KC_BSPC);
        //     } else {
        //         unregister_mods(mod_config(MOD_LCTL));
        //         unregister_code(KC_BSPC);
        //     }
        //     break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code(clockwise ? KC_VOLD : KC_VOLU);
    } else if (index == 1) {
        bool isFirstLayer = layer_state_is(0);
        if (clockwise) {
            tap_code(isFirstLayer ? KC_PGDN : KC_SCRL);
        } else {
            tap_code(isFirstLayer ? KC_PGUP : KC_PAUS);
        }
    }
    return false;
}

#endif

#ifdef KEY_OVERRIDE_ENABLE

// Shift + Backspace = Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	NULL // Null terminate the array of overrides!
};
#endif

#ifdef COMBO_ENABLE

const uint16_t PROGMEM backtick_tab_combo[] = {KC_GRV, KC_TAB, COMBO_END};
combo_t key_combos[] = {
    // `~ + TAB = ESC
    COMBO(backtick_tab_combo, KC_ESC),
};

#endif

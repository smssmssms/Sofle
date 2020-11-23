#include QMK_KEYBOARD_H
#include "keymap_uk.h"

enum sofle_layers {
    _QWERTY,
    _EXTRA,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_EXTRA,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| PGUP  |    | PGDN  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LALT | LAYER| /Space  /       \Enter \  |      |      | HOME | END  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  UK_ESC,   UK_1,   UK_2,    UK_3,    UK_4,    UK_5,                     UK_6,    UK_7,    UK_8,    UK_9,    UK_0,   UK_BSPC, \
  UK_TAB,   UK_Q,   UK_W,    UK_E,    UK_R,    UK_T,                     UK_Y,    UK_U,    UK_I,    UK_O,    UK_P,   UK_DEL, \
  KC_CLCK,  UK_A,   UK_S,    UK_D,    UK_F,    UK_G,                     UK_H,    UK_J,    UK_K,    UK_L,    UK_SCLN,UK_QUOT, \
  UK_LSFT,  UK_Z,   UK_X,    UK_C,    UK_V,    UK_B, KC_PGUP,    KC_PGDN,UK_N,    UK_M,    UK_COMM, UK_DOT,  UK_SLSH,UK_RSFT, \
                 KC_LCTRL,UK_LGUI,UK_LALT, KC_EXTRA, UK_SPC,      UK_ENT,  KC_APP, KC_RCTRL, UK_HOME, UK_END \
),
/*
 * EXTRA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   7  |   8  |   9  |   /  |   -  |                    | INS  | PSCR |   =  |   [  |   ]  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   0  |   4  |   5  |   6  |   *  |      |-------.    ,-------|  DEL |  UP  |   -  |   #  | PGUP | PGDN |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   1  |   2  |   3  |   +  |      |-------|    |-------| LEFT | DOWN | RIGHT|   `  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LALT |LAYER | /Space  /       \Enter \  |      | RCTR | HOME | END  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_EXTRA] = LAYOUT( \
  UK_ESC,   UK_F1,  UK_F2,   UK_F3,   UK_F4,   UK_F5,                     UK_F6,   UK_F7,   UK_F8,   UK_F9,   UK_F10,   UK_F11, \
  UK_TAB,   UK_P7,  UK_P8,   UK_P9,   UK_PSLS, UK_PMNS,                   UK_INS,  UK_PSCR, UK_EQL,  UK_LBRC, UK_RBRC,  UK_F12, \
  KC_P0,    UK_P4,  UK_P5,   UK_P6,   UK_PAST, KC_EXSEL,                   UK_DEL,  UK_UP,   UK_MINS, UK_HASH, UK_PGUP,  UK_PGDN, \
  UK_LSFT,  UK_P1,  UK_P2,   UK_P3,   UK_PPLS, KC_CALC, KC_MUTE,  XXXXXXX,UK_LEFT, UK_DOWN, UK_RGHT, UK_GRV,  UK_BSLS,  UK_RSFT, \
                KC_LCTRL,UK_LGUI,UK_LALT,KC_QWERTY, KC_SPC,         KC_ENT,  KC_APP, KC_RCTRL, UK_HOME, UK_END \
  )
};

// OLED:
#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
oled_write_P(PSTR("Hello"), false);
oled_write_P(PSTR("World"), false);
}

static void print_status_narrow(void) {
    // oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("Layer"), false);
    // oled_write_ln_P(PSTR("World"), false);
     // oled_write_P(PSTR("\n"), false);
// Print current layer:
    switch (get_hig hest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("_DEF_"), true);
            oled_write_ln_P(PSTR("_ALT_"), false);
            break;
        case _EXTRA:
            oled_write_ln_P(PSTR("_DEF_"), false);
            oled_write_ln_P(PSTR("_ALT_"), true);
            break;
        default:
            oled_write_P(PSTR("XXXX\nXXXX"), false);
    }
// Show Caps Lock:
    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("_CAP_"), led_usb_state.caps_lock);
}
// Rotate master half OLED:
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation; 
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif

// Switch between layers:
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_EXTRA:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_EXTRA);
            }
            return false;
   }
    return true;
}


#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
}

#endif

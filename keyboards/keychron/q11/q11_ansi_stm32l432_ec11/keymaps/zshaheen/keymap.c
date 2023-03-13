/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    MOUSE_KEYS
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// LED indices number of keys.
uint8_t other_keys[] = {0, 7, 9, 10, 11, 15, 16, 17, 18, 19, 22, 23, 24, 25, 26, 29, 30, 36, 37, 38, 39, 40, 41, 49, 56, 57, 59, 60, 61, 66, 68, 69, 70, 73, 74, 80, 81, 82, 83, 84, 85, 86, 87, 88};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_91(
        KC_MUTE,  KC_ESC,   KC_BRID,  KC_BRIU,  XXXXXXX,    XXXXXXX,    RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        TO(MAC_BASE),  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        TO(MAC_FN),  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        TO(WIN_BASE),  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        TO(WIN_FN),  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        TO(MOUSE_KEYS),  KC_LCTL,  KC_LOPT,  KC_LCMD,  MO(MAC_FN),         KC_SPC,                        KC_SPC,             KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_91(
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_TOG,
        TO(MAC_BASE),  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        TO(MAC_FN),  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        TO(WIN_BASE),  _______,  _______, _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        TO(WIN_FN),  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        TO(MOUSE_KEYS),  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_91(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        TO(MAC_BASE),  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        TO(MAC_FN),  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        TO(WIN_BASE),  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        TO(WIN_FN),  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        TO(MOUSE_KEYS),  KC_LCTL,  KC_LWIN,  KC_LALT,  MO(WIN_FN),         KC_SPC,                        KC_SPC,             KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_91(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        TO(MAC_BASE),  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        TO(MAC_FN),  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        TO(WIN_BASE),  _______,  _______, _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        TO(WIN_FN),  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        TO(MOUSE_KEYS),  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
    [MOUSE_KEYS] = LAYOUT_ansi_91(
        RGB_TOG,  KC_ESC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  KC_DEL,  RGB_TOG,
        TO(MAC_BASE),  XXXXXXX, KC_ACL0,  KC_ACL1,  KC_ACL2,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  KC_BSPC,            KC_PGUP,
        TO(MAC_FN),  KC_TAB,  KC_BTN1,  KC_MS_U,  KC_BTN2,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_BTN1,  KC_WH_U,  KC_BTN2,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,            KC_PGDN,
        TO(WIN_BASE),  KC_CAPS,  KC_MS_L, KC_MS_D, KC_MS_R,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_WH_L,  KC_WH_D,  KC_WH_R,  XXXXXXX,  XXXXXXX, KC_ENT,             KC_HOME,
        TO(WIN_FN),  KC_LSFT, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              KC_RSFT,  KC_UP,
        TO(MOUSE_KEYS),  KC_LCTL,  KC_LOPT,  KC_LCMD,  MO(WIN_FN),            KC_SPC,                       KC_SPC,            KC_RCMD,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [MOUSE_KEYS]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE

// This is a function I defined to be able to modify the brightness of the keys.
void rgb_matrix_set_color_helper(uint8_t led_i, uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_min, uint8_t led_max) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_get_val()) {
      hsv.v = rgb_matrix_get_val();
    }

    RGB rgb = hsv_to_rgb(hsv);
    RGB_MATRIX_INDICATOR_SET_COLOR(led_i, rgb.r, rgb.g, rgb.b);
    //rgb_matrix_set_color(led_i, rgb.r, rgb.g, rgb.b);
}

bool linear_search(uint8_t key, uint8_t array[], int size) {
    for(int i = 0; i < size; i++) {
      if (array[i] == key) {
        return true;
      }
    }
    return false;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
      layer_state_t highest_layer = get_highest_layer(layer_state|default_layer_state);
        switch(highest_layer) {
            case MAC_BASE:
                rgb_matrix_set_color_helper(i, HSV_WHITE, led_min, led_max);
                break;
            case MAC_FN:
                rgb_matrix_set_color_helper(i, HSV_RED, led_min, led_max);
                break;
            case WIN_BASE:
                rgb_matrix_set_color_helper(i, HSV_CYAN, led_min, led_max);
                break;
            case WIN_FN:
                rgb_matrix_set_color_helper(i, HSV_GREEN, led_min, led_max);
                break;
            case MOUSE_KEYS:
                if (linear_search(i, other_keys, sizeof(other_keys)/sizeof(other_keys[0]))) {
                  rgb_matrix_set_color_helper(i, HSV_PURPLE, led_min, led_max);
                } else {
                    rgb_matrix_set_color_helper(i, HSV_OFF, led_min, led_max);
                }
                break;
            default:
                break;
        }
    }
    return false;
}

/*
void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}
*/
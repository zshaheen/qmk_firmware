/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
  L0,
  L1,
  L2,
  L3,
  L4,
  L5
};

// LED indices number of keys.
uint8_t mouse_directions[] = {33, 47, 48, 49};
uint8_t mouse_speed[] = {53, 54, 55};
uint8_t mouse_btns[] = {32, 34, 38, 39};
uint8_t directional_keys[] = {72, 81, 82, 83};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L0] = LAYOUT_ansi_84(
     KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TO(L0),  KC_NO,   RGB_TOG,
     KC_NO,   TO(L1),     TO(L2),     TO(L3),     TO(L4),     TO(L5),     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,   KC_NO, RGB_VAI,
     KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,  KC_NO,            RGB_VAD,
     KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,            KC_NO,             KC_NO,
     KC_NO,            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,   KC_NO,            KC_NO,  KC_NO,    KC_NO,
     KC_NO,  KC_NO, KC_NO,                               KC_NO,                                 TG(L5),KC_NO,KC_NO,  KC_NO,  KC_NO,  KC_NO),

[L1] = LAYOUT_ansi_84(
     KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LNPD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  TO(L0),  KC_DEL,   RGB_TOG,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 TG(L5),MO(L2),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[L2] = LAYOUT_ansi_84(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   TO(L0),  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                TG(L5),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[L3] = LAYOUT_ansi_84(
     KC_ESC,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  TO(L0),  KC_TRNS,  RGB_TOG,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 TG(L5), MO(L4),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[L4] = LAYOUT_ansi_84(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   TO(L0),  KC_DEL,   RGB_TOG,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 TG(L5), MO(L4),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[L5] = LAYOUT_ansi_84(
     KC_ESC,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   RGB_TOG,
     KC_NO,   TO(L1),     TO(L2),     TO(L3),     TO(L4),     TO(L5),     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,   KC_NO, RGB_VAI,
     KC_NO,   KC_BTN1,     KC_MS_U,     KC_BTN2,     KC_NO,     KC_NO,     KC_NO,     KC_BTN1,     KC_BTN2,     KC_NO,     KC_NO,     KC_NO,  KC_NO,  KC_NO,            RGB_VAD,
     KC_NO,  KC_MS_L,     KC_MS_D,     KC_MS_R,     KC_NO,     KC_NO,     KC_NO,     KC_ACL0,     KC_ACL1,     KC_ACL2,     KC_NO,  KC_NO,            KC_NO,             KC_NO,
     KC_NO,            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,   KC_NO,            KC_NO,  KC_UP,    KC_NO,
     KC_NO,  KC_NO, KC_NO,                               KC_NO,                                 TG(L5),KC_NO,KC_NO,  KC_LEFT,  KC_DOWN,  KC_RGHT),
};

// This is a function I defined to be able to modify the brightness of the keys.
void rgb_matrix_set_color_helper(uint8_t led_i, uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_min, uint8_t led_max) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_get_val()) {
      hsv.v = rgb_matrix_get_val();
    }

    RGB rgb = hsv_to_rgb(hsv);
    RGB_MATRIX_INDICATOR_SET_COLOR(led_i, rgb.r, rgb.g, rgb.b);
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
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case L5:
                if (i == 0) {
                  rgb_matrix_set_color_helper(i, HSV_WHITE, led_min, led_max);
                } else if (i == 13 || i == 78) {
                  rgb_matrix_set_color_helper(i, HSV_RED, led_min, led_max);
                }
                else if (linear_search(i, mouse_directions, 4)) {
                  rgb_matrix_set_color_helper(i, HSV_GREEN, led_min, led_max);
                } else if (linear_search(i, mouse_speed, 3)) {
                  rgb_matrix_set_color_helper(i, HSV_BLUE, led_min, led_max);
                } else if (linear_search(i, mouse_btns, 4)) {
                  rgb_matrix_set_color_helper(i, HSV_WHITE, led_min, led_max);
                } else if (17 <= i && i <= 21) {
                    rgb_matrix_set_color_helper(17, HSV_WHITE, led_min, led_max);
                    rgb_matrix_set_color_helper(18, HSV_GOLD, led_min, led_max);
                    rgb_matrix_set_color_helper(19, HSV_CYAN, led_min, led_max);
                    rgb_matrix_set_color_helper(20, HSV_PURPLE, led_min, led_max);
                    rgb_matrix_set_color_helper(21, HSV_GREEN, led_min, led_max);
                 } else if (linear_search(i, directional_keys, 4)) {
                  rgb_matrix_set_color_helper(i, HSV_SPRINGGREEN, led_min, led_max);
                 } else {
                  rgb_matrix_set_color_helper(i, HSV_OFF, led_min, led_max);
                }
                break;
            case L4:
                if (i == 13 || i == 78) {
                  rgb_matrix_set_color_helper(i, HSV_RED, led_min, led_max);
                } else {
                  rgb_matrix_set_color_helper(i, HSV_PURPLE, led_min, led_max);
                }
                break;
            case L3:
                if (i == 13 || i == 78) {
                  rgb_matrix_set_color_helper(i, HSV_RED, led_min, led_max);
                } else {
                  rgb_matrix_set_color_helper(i, HSV_CYAN, led_min, led_max);
                }
                break;
            case L2:
                if (i == 13 || i == 78) {
                  rgb_matrix_set_color_helper(i, HSV_RED, led_min, led_max);
                } else {
                  rgb_matrix_set_color_helper(i, HSV_GOLD, led_min, led_max);
                }
                break;
            case L1:
                if (i == 13 || i == 78) {
                  rgb_matrix_set_color_helper(i, HSV_RED, led_min, led_max);
                } else {
                  rgb_matrix_set_color_helper(i, HSV_WHITE, led_min, led_max);
                }
                break;
            case L0:
                 if (i == 15 || i == 30 || i == 45) {
                    rgb_matrix_set_color_helper(i, HSV_WHITE, led_min, led_max);
                 } else if (i == 13 || i == 78) {
                    rgb_matrix_set_color_helper(i, HSV_RED, led_min, led_max);
                 }
                 else if (17 <= i && i <= 21) {
                    rgb_matrix_set_color_helper(17, HSV_WHITE, led_min, led_max);
                    rgb_matrix_set_color_helper(18, HSV_GOLD, led_min, led_max);
                    rgb_matrix_set_color_helper(19, HSV_CYAN, led_min, led_max);
                    rgb_matrix_set_color_helper(20, HSV_PURPLE, led_min, led_max);
                    rgb_matrix_set_color_helper(21, HSV_GREEN, led_min, led_max);
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

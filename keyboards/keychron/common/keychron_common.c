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
#include "keychron_common.h"
#include "keychron_factory_test_common.h"

#ifdef LED_MATRIX_ENABLE
__attribute__((weak)) bool led_matrix_indicators_advanced_ft(uint8_t led_min, uint8_t led_max) {
    return true;
};
#endif // LED_MATRIX_ENABLE

#ifdef RGB_MATRIX_ENABLE
__attribute__((weak)) bool rgb_matrix_indicators_advanced_ft(uint8_t led_min, uint8_t led_max) {
    return true;
};
#endif // RGB_MATRIX_ENABLE

#ifdef DIP_SWITCH_ENABLE
__attribute__((weak)) bool dip_switch_update_ft(uint8_t index, bool active) {
    return true;
};
#endif // DIP_SWITCH_ENABLE

__attribute__((weak)) bool process_record_ft(uint16_t keycode, keyrecord_t *record) {
    return true;
};

__attribute__((weak)) void housekeeping_task_ft(void) {};

bool is_siri_active = false;
uint32_t siri_timer = 0;

key_combination_t key_comb_list[4] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}},
    {3, {KC_LSFT, KC_LCMD, KC_4}},
    {2, {KC_LWIN, KC_C}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

void housekeeping_task_keychron(void) {
    housekeeping_task_ft();
    if (is_siri_active) {
        if (sync_timer_elapsed32(siri_timer) >= 500) {
            unregister_code(KC_LCMD);
            unregister_code(KC_SPACE);
            is_siri_active = false;
        }
    }
}

bool process_record_keychron(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_ft(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        // case KC_DND:
        //     if (record->event.pressed) {
        //         host_system_send(0x9B);
        //     } else {
        //         host_system_send(0);
        //     }
        //     return false; // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_SIRI:
            if (record->event.pressed) {
                if (!is_siri_active) {
                    is_siri_active = true;
                    register_code(KC_LCMD);
                    register_code(KC_SPACE);
                }
                siri_timer = sync_timer_read32();
            } else {
                // Do something else when release
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
        case KC_SNAP:
        case KC_CRTA:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_keychron(uint8_t index, bool active) {
    if (!dip_switch_update_ft(index, active)) {
        return false;
    }
    return true;
}
#endif // DIP_SWITCH_ENABLE

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_keychron(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_ft(led_min, led_max)) {
        return false;
    }
    return true;
}
#endif // RGB_MATRIX_ENABLE

#ifdef LED_MATRIX_ENABLE
bool led_matrix_indicators_advanced_keychron(uint8_t led_min, uint8_t led_max) {
    if (!led_matrix_indicators_advanced_ft(led_min, led_max)) {
        return false;
    }
    return true;
}
#endif // LED_MATRIX_ENABLE

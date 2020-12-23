/* Copyright 2020 Cameron Buss camrbuss@vt.edu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include "grabert.h"

static uint32_t oled_timer    = 0;
static bool     write_outline = true;

void suspend_power_down_user(void) { oled_off(); }

void suspend_wakeup_init_user(void) {
    oled_timer    = timer_read32();
    write_outline = true;
}

void oled_task_user(void) {
    if (timer_read32() < (oled_timer + LOGO_TIMEOUT_MS)) {
        /* Display a logo for a short period of time after  */
        /* turning the keyboard on */
        oled_write_raw(kobuss_logo, OLED_MATRIX_SIZE);
    } else {
        if (write_outline) {
            oled_write_raw(screen_outline, OLED_MATRIX_SIZE);
            write_outline = false;
        } else {
            /* Set WPM rate */
            uint8_t wpm  = get_current_wpm();
            uint8_t bars = 0;
            if (wpm > SPEED_MAX_BARS_WPM) {
                bars = SPEED_NUM_BARS;
            } else {
                bars = wpm / SPEED_WPM_TO_BARS;
            }

            for (size_t i = 0; i < SPEED_NUM_BARS; i++) {
                if (bars) {
                    oled_write_raw_byte(0xFF, 264 + i);
                    bars--;
                } else {
                    oled_write_raw_byte(0x00, 264 + i);
                }
            }

            /* Set Caps Lock */
            led_t       leds = host_keyboard_led_state();
            const char* caps_glyph;
            if (leds.caps_lock) {
                caps_glyph = caps_lock_on;
            } else {
                caps_glyph = caps_lock_off;
            }

            for (size_t i = 0; i < CAPS_LOCK_ROWS_BYTES; i++) {
                for (size_t j = 0; j < CAPS_LOCK_COLS_BITS; j++) {
                    oled_write_raw_byte(caps_glyph[i * CAPS_LOCK_COLS_BITS + j], (OLED_DISPLAY_WIDTH + 50) + OLED_DISPLAY_WIDTH * i + j);
                }
            }

            /* Set Layer (Currently only supports 0-3 layers) */
            uint8_t lay = 0;
            lay         = lay | layer_state_is(0) << 0;
            lay         = lay | layer_state_is(1) << 1;
            lay         = lay | layer_state_is(2) << 2;
            lay         = lay | layer_state_is(3) << 3;

            const char* layer_glyph;

            switch (lay) {
                case 0b0001:
                    layer_glyph = layer_num_0;
                    break;
                case 0b0010:
                    layer_glyph = layer_num_1;
                    break;
                case 0b0100:
                    layer_glyph = layer_num_2;
                    break;
                case 0b1000:
                    layer_glyph = layer_num_3;
                    break;

                default:
                    layer_glyph = layer_num_0;
                    break;
            }

            for (size_t i = 0; i < LAYER_ROWS_BYTES; i++) {
                for (size_t j = 0; j < LAYER_COLS_BITS; j++) {
                    oled_write_raw_byte(layer_glyph[i * LAYER_COLS_BITS + j], (OLED_DISPLAY_WIDTH + 98) + OLED_DISPLAY_WIDTH * i + j);
                }
            }
        }
    }
}

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

#pragma once

#include "quantum.h"

// clang-format off
#define LAYOUT_default( \
	K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, K12, K13, K14, \
	K15, K16, K17, K18, K19, K20, K21, K22, K23, K24, K25, K26, K27, K28, \
	K29, K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K40, K41, \
	K42, K43, K44, K45, K46, K47, K48, K49, K50, K51, K52, K53, K54, K55, \
    K56, K57, K58, K59, K60, K61, K62, K63, K64, K65 \
) {\
	{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, K12, K13, K14 },\
	{ K15, K16, K17, K18, K19, K20, K21, K22, K23, K24, K25, K26, K27, K28, KC_NO },\
	{ K29, K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K40, K41, KC_NO, KC_NO },\
	{ K42, K43, K44, K45, K46, K47, K48, K49, K50, K51, K52, K53, K54, K55, KC_NO },\
    { K56, K57, K58, K59, K60, K61, K62, K63, K64, K65, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }\
}
// clang-format on

#ifdef OLED_DRIVER_ENABLE
#    define LOGO_TIMEOUT_MS 3000
#    define GOL_MAX_ITERATIONS 140
#    define GOL_EVOLVE_PERIOD_MS 120

#    define SPEED_MAX_BARS_WPM 144
#    define SPEED_NUM_BARS 24
#    define SPEED_WPM_TO_BARS (SPEED_MAX_BARS_WPM / SPEED_NUM_BARS)

#    define CAPS_LOCK_COLS_BITS (32 / 1)
#    define CAPS_LOCK_ROWS_BYTES (24 / 8)

#    define LAYER_COLS_BITS (24 / 1)
#    define LAYER_ROWS_BYTES (24 / 8)

#    define GOL_SQUARE_SIZE 2
#    define GOL_WIDTH (OLED_DISPLAY_WIDTH / GOL_SQUARE_SIZE)
#    define GOL_HEIGHT (OLED_DISPLAY_HEIGHT / GOL_SQUARE_SIZE)
#    define GOL_EVOLVE_PERIOD_MOD (GOL_EVOLVE_PERIOD_MS / OLED_UPDATE_INTERVAL)
#    define GOL_UPDATE_MAX_COUNT (GOL_MAX_ITERATIONS * GOL_EVOLVE_PERIOD_MOD)

void gol_play_game(void);
void gol_initialize(void);

// clang-format off
static const char kobuss_logo [OLED_MATRIX_SIZE] = {
    0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xfc, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x03,
	0x01, 0x01, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0x60, 0x30, 0x30, 0x38, 0x18, 0x1c, 0x0c, 0x0e, 0x0e,
	0x06, 0x07, 0x03, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x60, 0x60, 0x60, 0x60, 0x60, 0xe0, 0xc0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0xff, 0xff, 0xff, 0xe3, 0xe3, 0x63, 0x73, 0x33,
	0x3b, 0x1b, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x80, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x60, 0x60, 0x60, 0x60, 0x60,
	0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x60, 0x60, 0x60, 0x60, 0x60, 0xc0, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0,
	0xc0, 0xc0, 0x80, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xff, 0x03, 0x03, 0x07, 0x06, 0x06, 0x0e, 0x0c, 0x1c, 0x18, 0x38, 0x30,
	0x70, 0x60, 0x60, 0x00, 0x00, 0x0f, 0x3f, 0x70, 0x60, 0xe0, 0xc0, 0xe0, 0x60, 0x70, 0x3f, 0x1f,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x60, 0xff, 0xff, 0xff, 0x63, 0x63, 0x63, 0x66, 0x66,
	0x6e, 0x6c, 0x7c, 0x78, 0x78, 0x70, 0x70, 0x70, 0x60, 0x00, 0x00, 0x00, 0x3f, 0x71, 0x60, 0x60,
	0x60, 0x60, 0x60, 0x60, 0x3f, 0x1f, 0x00, 0x00, 0x00, 0x33, 0x63, 0x66, 0x66, 0x66, 0x66, 0x64,
	0x6c, 0x7c, 0x38, 0x00, 0x00, 0x33, 0x63, 0x66, 0x66, 0x66, 0x66, 0x64, 0x6c, 0x7c, 0x38, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x3f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char screen_outline [OLED_MATRIX_SIZE] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb3, 0xb5, 0xad, 0x8f, 0xff,
	0x81, 0xed, 0xe1, 0xf3, 0xff, 0x81, 0xa5, 0xb5, 0xbf, 0xff, 0x81, 0xb5, 0xb5, 0xff, 0x83, 0x81,
	0xbd, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc3, 0xb9, 0xbd,
	0xbf, 0xbf, 0x83, 0xd9, 0xc3, 0xbf, 0xff, 0x81, 0xed, 0xe1, 0xff, 0xb3, 0xb1, 0xa5, 0x8d, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0xbf, 0xbf, 0xbf, 0xff, 0x81, 0xbd, 0x81, 0xe7, 0xff, 0x83,
	0xbd, 0xbd, 0xff, 0x81, 0xe7, 0xe3, 0x9d, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0x81, 0xbf, 0xbf, 0xbf, 0xbf, 0xc3, 0xd9, 0x83, 0xbf, 0xfd, 0xf3, 0x87, 0xf9, 0xff,
	0x81, 0x81, 0xb5, 0xbd, 0xff, 0x81, 0xed, 0xc1, 0x93, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'caps_lock_on', 32x24px
static const char caps_lock_on [] = {
	0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x70, 0x38, 0x18, 0x18, 0x30, 0x70, 0xe0, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x00,
	0x00, 0x00, 0xff, 0xff, 0x00, 0x03, 0x1f, 0x7c, 0xe0, 0x80, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x1c, 0x0f, 0x07, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x1e, 0x1f, 0x1f, 0x00, 0x00, 0x00
};

// 'caps_lock_off', 32x24px
static const char caps_lock_off [] = {
	0x00, 0x80, 0xe0, 0x30, 0x18, 0x18, 0x30, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x30, 0x30,
	0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00,
	0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7c, 0x00, 0x00, 0x00, 0xff, 0x1c, 0x18,
	0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x08, 0x00,
	0x00, 0x03, 0x0f, 0x1c, 0x18, 0x18, 0x18, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'layer_num_0', 24x24px
static const char layer_num_0 [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x38, 0x18, 0x18, 0x18, 0x30, 0xf0,
	0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
	0xff, 0x00, 0x00, 0x18, 0x38, 0x18, 0x00, 0xe7, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0e, 0x18, 0x18, 0x18, 0x18, 0x1c, 0x0f,
	0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'layer_num_1', 24x24px
static const char layer_num_1 [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x38, 0xf8, 0xf8, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x18, 0x18,
	0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'layer_num_2', 24x24px
static const char layer_num_2 [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x18, 0x18, 0x18, 0x18, 0x38, 0x70, 0xf0,
	0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x1c, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1e, 0x1f, 0x1b, 0x19, 0x18, 0x18, 0x18, 0x18,
	0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'layer_num_3', 24x24px
static const char layer_num_3 [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0xf0,
	0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x08, 0x08, 0x1c, 0x1c, 0x3e, 0xf7, 0xe3, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1c, 0x0f,
	0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char layer_nan [] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
// clang-format on
#endif

/* Copyright 2023 Ben Gruver <jesusfreke@jesusfreke.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include QMK_KEYBOARD_H

#include <stdbool.h>
#include <stdint.h>

enum layer { NORMAL };

/* Declared weak so that it can easily be overridden. */
__attribute__((weak))
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ KC_A, KC_Q, QK_CAPS_WORD_TOGGLE, KC_V, KC_ESC,
        /*L2*/ KC_R, KC_W, KC_Z, KC_X, XXXXXXX,
        /*L3*/ KC_S, KC_F, XXXXXXX, KC_C, XXXXXXX,
        /*L4*/ KC_T, KC_D, KC_G, KC_B, KC_SCLN,

        /*R1*/ KC_N, KC_J, XXXXXXX, KC_K, KC_H,
        /*R2*/ KC_E, KC_L, KC_PAGE_UP, KC_M, KC_U,
        /*R3*/ KC_I, KC_Y, KC_PAGE_DOWN, KC_COMMA, KC_SLASH,
        /*R4*/ KC_O, KC_P, XXXXXXX, KC_DOT, XXXXXXX,

        /*Down          Inner     Upper      Outer Upper      Outer Lower*/
        /*LT*/ MO(2), KC_ENTER, KC_BSPACE, KC_TAB, MO(1),
        /*RT*/ KC_SPACE, MO(1), KC_SPACE, KC_DEL, KC_INS),

};

#include "sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_smtd(keycode, record))
    return false;

  return true;
}

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action,
                               uint8_t tap_count) {
  switch (keycode) {

    SMTD_MT(KC_V, KC_LEFT_GUI)
    SMTD_MT(KC_X, KC_LEFT_ALT)
    SMTD_MT(KC_C, KC_LEFT_CTRL)
    SMTD_MT(KC_B, KC_LSFT)
    SMTD_MT(KC_DOT, KC_LEFT_GUI)
    SMTD_MT(KC_COMMA, KC_LEFT_ALT)
    SMTD_MT(KC_M, KC_LEFT_CTRL)
    SMTD_MT(KC_K, KC_LSFT)
  }
  return SMTD_RESOLUTION_UNHANDLED;
}

void keyboard_post_init_user(void) {
  // debug_enable = true;
  //  debug_matrix=true;
  //  debug_keyboard=true;
  //  debug_mouse=true;
}

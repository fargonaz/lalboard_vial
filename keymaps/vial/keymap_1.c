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

enum my_keycodes {
  KC_NORMAL_HOLD = SAFE_RANGE,
  KC_GAME_HOLD,
};

enum custom_keycodes {
  SMTD_KEYCODES_BEGIN = SAFE_RANGE,
  CKC_V, // reads as C(ustom) + KC_A, but you may give any name here
  CKC_X,
  CKC_C,
  CKC_B,
  CKC_K,
  CKC_M,
  CKC_COMMA,
  CKC_DOT,
  SMTD_KEYCODES_END,
};

#include "sm_td.h"

enum layer { NORMAL, FUNC };

/* Declared weak so that it can easily be overridden. */
__attribute__((weak))
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ KC_A, KC_Q, QK_CAPS_WORD_TOGGLE, CKC_V, KC_ESC,
        /*L2*/ KC_R, KC_W, KC_Z, CKC_X, XXXXXXX,
        /*L3*/ KC_S, KC_F, XXXXXXX, CKC_C, XXXXXXX,
        /*L4*/ KC_T, KC_D, KC_G, CKC_B, KC_SCLN,

        /*R1*/ KC_N, KC_J, XXXXXXX, CKC_K, KC_H,
        /*R2*/ KC_E, KC_L, KC_PAGE_UP, CKC_M, KC_U,
        /*R3*/ KC_I, KC_Y, KC_PAGE_DOWN, CKC_COMMA, KC_SLASH,
        /*R4*/ KC_O, KC_P, XXXXXXX, CKC_DOT, XXXXXXX,

        /*Down          Inner     Upper      Outer Upper      Outer Lower*/
        /*LT*/ KC_ESC, KC_ENTER, KC_BSPACE, KC_TAB, KC_ESC,
        /*RT*/ KC_SPACE, MO(2), MO(FUNC), KC_DEL, KC_INS),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  default:
    if (!process_smtd(keycode, record)) {
      return false;
    }
    // your code here
    else
      return true;
  }
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
  switch (keycode) {
    SMTD_MT(CKC_V, KC_V, KC_LEFT_GUI)
    SMTD_MT(CKC_X, KC_X, KC_LEFT_ALT)
    SMTD_MT(CKC_C, KC_C, KC_LEFT_CTRL)
    SMTD_MT(CKC_B, KC_B, KC_LSFT)
    SMTD_MT(CKC_DOT, KC_DOT, KC_LEFT_GUI)
    SMTD_MT(CKC_COMMA, KC_COMMA, KC_LEFT_ALT)
    SMTD_MT(CKC_M, KC_M, KC_LEFT_CTRL)
    SMTD_MT(CKC_K, KC_K, KC_LSFT)
  }
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
  switch (keycode) {
  case CKC_M:
    if (timeout == SMTD_TIMEOUT_TAP)
      return 300;
  case CKC_V:
    if (timeout == SMTD_TIMEOUT_TAP)
      return 300;
  }
  return get_smtd_timeout_default(timeout);
}

//.const uint16_t PROGMEM left_parenthesis[] = {KC_T, KC_D, COMBO_END};
// const uint16_t PROGMEM right_parenthesis[] = {KC_N, KC_J, COMBO_END};
// combo_t key_combos[] = {
//    COMBO(left_parenthesis, LSFT(KC_9)),
//    COMBO(right_parenthesis, LSFT(KC_0)),
// i;

void keyboard_post_init_user(void) {
  // debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;
}

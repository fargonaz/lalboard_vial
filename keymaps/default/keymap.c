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
  KC_NORMAL = SAFE_RANGE,
};

enum layer {
  NORMAL,
  FUNC,
  NAS,
};

enum tapdance {
  TD_1,
  TD_2,
  TD_3,
  TD_4,
  TD_5,
  TD_6,
  TD_7,
  TD_8,
  TD_9,
  TD_10,
  TD_PAREN,
  TD_BRACKET,
  TD_BRACE
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [TD_10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
    [TD_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [TD_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_BRACKET, KC_RIGHT_BRACKET),
    [TD_BRACE] =
        ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
};

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
        /*R4*/ KC_O, KC_P, XXXXXXX, KC_DOT, QK_COMBO_TOGGLE,

        /*Down          Inner     Upper      Outer Upper      Outer Lower*/
        /*LT*/ MO(2), KC_ENTER, KC_BSPACE, KC_TAB, MO(1),
        /*RT*/ KC_SPACE, MO(1), KC_SPACE, KC_DEL, KC_INS),

    [NAS] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ KC_CAPS, KC_DOLLAR, XXXXXXX, KC_MINUS, QK_BOOT,
        /*L2*/ XXXXXXX, TD(TD_BRACE), XXXXXXX, RCS(KC_C), XXXXXXX,
        /*L3*/ KC_QUOTE, KC_AT, KC_TILDE, RCS(KC_V), XXXXXXX,
        /*L4*/ KC_UNDS, KC_MINUS, KC_PIPE, KC_PLUS, KC_EQUAL,

        /*R1*/ TD(TD_2), TD(TD_PAREN), TD(TD_3), KC_LEFT, TD(TD_1),
        /*R2*/ TD(TD_5), KC_UP, TD(TD_6), KC_DOWN, TD(TD_4),
        /*R3*/ TD(TD_8), TD(TD_BRACKET), TD(TD_9), KC_RIGHT, TD(TD_7),
        /*R4*/ TD(TD_10), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        /*Down             Inner           Upper           Outer Upper     Outer
           Lower*/
        /*LT*/ TO(NORMAL), KC_ENTER, XXXXXXX, KC_TAB, KC_LCTRL,
        /*RT*/ MO(NAS), KC_SPACE, TO(FUNC), KC_BSPACE, KC_LALT),

    [FUNC] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        /*L2*/ KC_MS_BTN3, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_MS_WH_DOWN,
        KC_MS_WH_LEFT,

        /*L3*/ KC_MS_BTN1, KC_MS_UP, KC_MS_RIGHT, KC_MS_DOWN, KC_MS_LEFT,
        /*L4*/ KC_MS_BTN2, KC_HOME, XXXXXXX, KC_END, XXXXXXX,

        /*R1*/ KC_MS_BTN2, KC_HOME, XXXXXXX, KC_END, XXXXXXX,
        /*R2*/ KC_MS_BTN1, KC_MS_UP, KC_MS_RIGHT, KC_MS_DOWN, KC_MS_LEFT,
        /*R3*/ KC_MS_BTN3, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_MS_WH_DOWN,
        KC_MS_WH_LEFT,
        /*R4*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,

        /*Down             Inner           Upper           Outer Upper     Outer
           Lower*/
        /*LT*/ KC_LSHIFT, KC_ENTER, XXXXXXX, KC_TAB, KC_LCTRL,
        /*RT*/ MO(NAS), KC_SPACE, TO(FUNC), KC_BSPACE, KC_LALT),
};

#include "sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_smtd(keycode, record)) {
    return false;
  }
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

enum combos { LP, RP };

const uint16_t PROGMEM left_parenthesis[] = {KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM right_parenthesis[] = {KC_N, KC_E, COMBO_END};
combo_t key_combos[2] = {COMBO(left_parenthesis, LSFT(KC_9)),
                         COMBO(right_parenthesis, LSFT(KC_0))};

void keyboard_post_init_user(void) {
  debug_enable = true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;
}

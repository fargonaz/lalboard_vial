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

#define HOME_A LGUI_T(KC_A) // A acts as GUI (Cmd/Win) when held
#define HOME_R LALT_T(KC_R) // S acts as Alt when held
#define HOME_S LCTL_T(KC_S) // D acts as Shift when held
#define HOME_T LSFT_T(KC_T) // F acts as Ctrl when held

#define HOME_N RSFT_T(KC_N) // J acts as Ctrl when held
#define HOME_E RCTL_T(KC_E) // K acts as Shift when held
#define HOME_I RALT_T(KC_I) // L acts as Alt when held
#define HOME_O RGUI_T(KC_O) // ; acts as GUI (Cmd/Win) when held

enum my_keycodes {
  KC_NORMAL_HOLD = SAFE_RANGE,
  KC_GAME_HOLD,
};

enum layer {
  NORMAL,
  NORMAL_HOLD,
  FUNC,
  NAS,
  GAME,
  GAME_HOLD,
  GAME_MOD_1,
  GAME_MOD_2,
  NUM_LAYERS
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
const uint16_t PROGMEM keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ HOME_A, KC_Q, XXXXXXX, KC_V, KC_ESC,
        /*L2*/ HOME_R, KC_W, KC_Z, KC_X, XXXXXXX,
        /*L3*/ HOME_S, KC_F, XXXXXXX, KC_C, XXXXXXX,
        /*L4*/ HOME_T, KC_D, KC_G, KC_B, KC_SCLN,

        /*R1*/ HOME_N, KC_J, XXXXXXX, KC_K, KC_H,
        /*R2*/ HOME_E, KC_L, KC_PAGE_UP, KC_M, KC_U,
        /*R3*/ HOME_I, KC_Y, KC_PAGE_DOWN, KC_COMMA, KC_SLASH,
        /*R4*/ HOME_O, KC_P, XXXXXXX, KC_DOT, XXXXXXX,

        /*Down          Inner     Upper      Outer Upper      Outer Lower*/
        /*LT*/ MO(NAS), KC_ENTER, KC_BSPACE, KC_TAB, TG(NAS),
        /*RT*/ KC_SPACE, KC_SPACE, MO(FUNC), KC_DEL, KC_INS),

    [NORMAL_HOLD] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ _______, _______, _______, LCTL(KC_V), _______,
        /*L2*/ _______, _______, _______, LCTL(KC_C), _______,
        /*L3*/ _______, _______, _______, LCTL(KC_X), _______,
        /*L4*/ DF(NORMAL), _______, _______, DF(GAME), _______,

        /*R1*/ _______, _______, _______, _______, _______,
        /*R2*/ _______, _______, _______, _______, _______,
        /*R3*/ _______, _______, _______, _______, _______,
        /*R4*/ _______, _______, _______, _______, _______,

        /*Down             Inner           Upper           Outer Upper     Outer
           Lower*/
        /*LT*/ _______, _______, _______, _______, _______,
        /*RT*/ _______, _______, _______, _______, _______),

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
        /*LT*/ TO(NORMAL), KC_ENTER, KC_NORMAL_HOLD, KC_TAB, KC_LCTRL,
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
        /*LT*/ KC_LSHIFT, KC_ENTER, KC_NORMAL_HOLD, KC_TAB, KC_LCTRL,
        /*RT*/ MO(NAS), KC_SPACE, TO(FUNC), KC_BSPACE, KC_LALT),

    [GAME] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ KC_W, KC_G, KC_I, KC_E, KC_F,
        /*L2*/ KC_D, KC_T, KC_Y, KC_J, KC_GRAVE,
        /*L3*/ KC_A, KC_COMMA, KC_X, KC_K, KC_ESC,
        /*L4*/ KC_S, KC_Z, KC_V, KC_R, KC_DEL,

        /*R1*/ KC_H, KC_G, KC_QUOTE, KC_M, KC_D,
        /*R2*/ KC_T, KC_W, KC_GRAVE, KC_C, KC_F,
        /*R3*/ KC_N, KC_V, XXXXXXX, KC_R, KC_B,
        /*R4*/ KC_S, KC_Z, KC_BSLASH, KC_L, KC_RIGHT_PAREN,

        /*Down             Inner           Upper           Outer Upper     Outer
           Lower*/
        /*LT*/ KC_LSHIFT, KC_SPACE, KC_GAME_HOLD, MO(GAME_MOD_1), KC_LALT,
        /*RT*/ MO(NAS), KC_SPACE, TO(FUNC), KC_BSPACE, KC_LALT),

    [GAME_HOLD] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ _______, _______, _______, LCTL(KC_V), _______,
        /*L2*/ _______, _______, _______, LCTL(KC_C), _______,
        /*L3*/ _______, _______, _______, LCTL(KC_X), _______,
        /*L4*/ DF(NORMAL), _______, _______, DF(GAME), _______,

        /*R1*/ _______, _______, _______, _______, _______,
        /*R2*/ _______, _______, _______, _______, _______,
        /*R3*/ _______, _______, _______, _______, _______,
        /*R4*/ _______, _______, _______, _______, _______,

        /*Down             Inner           Upper           Outer Upper     Outer
           Lower*/
        /*LT*/ _______, _______, _______, _______, _______,
        /*RT*/ _______, _______, _______, _______, _______),

    [GAME_MOD_1] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ KC_4, KC_F4, KC_5, KC_M, KC_0,
        /*L2*/ KC_3, KC_F3, KC_F11, KC_8, KC_F7,
        /*L3*/ KC_2, KC_F2, KC_F10, KC_7, KC_F6,
        /*L4*/ KC_1, KC_F1, KC_F9, KC_6, KC_F5,

        /*R1*/ KC_H, KC_G, KC_QUOTE, KC_M, KC_D,
        /*R2*/ KC_T, KC_W, KC_GRAVE, KC_C, KC_F,
        /*R3*/ KC_N, KC_V, XXXXXXX, KC_R, KC_B,
        /*R4*/ KC_S, KC_Z, KC_BSLASH, KC_L, KC_RIGHT_PAREN,

        /*Down             Inner           Upper           Outer Upper     Outer
           Lower*/
        /*LT*/ KC_LSHIFT, KC_ENTER, KC_GAME_HOLD, MO(GAME_MOD_1), KC_LCTRL,
        /*RT*/ MO(NAS), KC_SPACE, TO(FUNC), KC_BSPACE, KC_LALT),

    [GAME_MOD_2] = LAYOUT(
        /*Center           North           East            South West*/
        /*L1*/ KC_F8, KC_F4, KC_5, KC_9, KC_F8,
        /*L2*/ KC_F7, KC_F3, KC_F11, KC_8, KC_F7,
        /*L3*/ KC_F6, KC_F2, KC_F10, KC_7, KC_F6,
        /*L4*/ KC_F5, KC_F1, KC_F9, KC_6, KC_F5,

        /*R1*/ KC_H, KC_G, KC_QUOTE, KC_M, KC_D,
        /*R2*/ KC_T, KC_W, KC_GRAVE, KC_C, KC_F,
        /*R3*/ KC_N, KC_V, XXXXXXX, KC_R, KC_B,
        /*R4*/ KC_S, KC_Z, KC_BSLASH, KC_L, KC_RIGHT_PAREN,

        /*Down             Inner           Upper           Outer Upper     Outer
           Lower*/
        /*LT*/ KC_LSHIFT, KC_ENTER, KC_GAME_HOLD, MO(GAME_MOD_1), KC_LCTRL,
        /*RT*/ MO(NAS), KC_SPACE, TO(FUNC), KC_BSPACE, KC_LALT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_NORMAL_HOLD:
    if (record->event.pressed) {
      layer_clear();
      default_layer_set(1 << NORMAL);
      layer_on(NORMAL_HOLD);
    } else {
      layer_off(NORMAL_HOLD);
    }
    return false;
  case KC_GAME_HOLD:
    if (record->event.pressed) {
      layer_clear();
      default_layer_set(1 << GAME);
      layer_on(GAME_HOLD);
    } else {
      layer_off(GAME_HOLD);
    }
    return false;
  default:
    return true;
  }
}

void keyboard_post_init_user(void) {
  debug_enable = true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;
}

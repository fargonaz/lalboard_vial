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

#pragma once

#define MATRIX_ROWS 10
#define MATRIX_COLS 5

// The column with the "down" keys on both the normal and thumb clusters
// is inverted.
#define MATRIX_COL_PUSHED_STATES                                               \
  { 0, 0, 1, 0, 0 }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is
 * not needed */
#define DEBOUNCE 0
// #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define MAX_DEFERRED_EXECUTORS 10
#define EE_HANDS
#define MASTER_RIGHT

// #define DEBUG_MATRIX_SCAN_RATE

#define SERIAL_DEBUG
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP24
#define SERIAL_USART_RX_PIN GP23
#define SERIAL_USART_PIN_SWAP

#define TAPPING_TERM 249
#define MOUSEKEY_INTERVAL 23
#define MOUSEKEY_TIME_TO_MAX 12
#define MOUSEKEY_MAX_SPEED 6
#define MOUSEKEY_MOVE_DELTA 3
#define MOUSEKEY_WHEEL_MAX_SPEED 3
#define MOUSEKEY_WHEEL_TIME_TO_MAX 45

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PICO_TIME_H_
#define PICO_TIME_H_

#include <cstdint>

struct repeating_timer {
  void* user_data;
};

typedef struct repeating_timer repeating_timer_t;

typedef bool (* repeating_timer_callback_t)(repeating_timer_t* rt);

extern bool add_repeating_timer_ms(
    std::int32_t delay_ms,
    repeating_timer_callback_t
    callback, void* user_data,
    repeating_timer_t* out
);

bool cancel_repeating_timer(repeating_timer_t* timer);

#endif  // PICO_TIME_H_

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/time.h"

#include <cstdint>

#include "CppUTestExt/MockSupport.h"

// TODO(jisbert): https://cpputest.github.io/mocking_manual.html#output_parameters_using_objects
bool add_repeating_timer_ms(
    std::int32_t delay_ms,
    repeating_timer_callback_t callback,
    void* user_data,
    repeating_timer_t* out) {
  mock("repeating_timer").actualCall("add_repeating_timer_ms").withParameter("delay_ms", delay_ms);
  repeating_timer_t repeating_timer{user_data};
  callback(&repeating_timer);

  return true;
}

bool cancel_repeating_timer(repeating_timer_t* timer) {
  mock("repeating_timer").actualCall("cancel_repeating_timer");

  return true;
}

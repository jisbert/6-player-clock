/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "6_player_clock.h"  // NOLINT(build/include_subdir)

#include "pico/stdlib.h"

#include "button/button_setup.h"

ButtonController button_controller;

int main() {
  stdio_init_all();
  button_controller = SetupButtons({ PLAYER_1_BUTTON_PIN });

  return 0;
}

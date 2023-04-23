/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "6_player_clock.h"  // NOLINT(build/include_subdir)

#include "pico/stdlib.h"

#include "button/button.h"
#include "button/button_controller.h"

int main() {
  stdio_init_all();
  ButtonController button_controller;
  button::SetupButtons(button_controller);

  return 0;
}

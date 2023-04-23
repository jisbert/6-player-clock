/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

#include "button/button.h"
#include "button/button_controller.h"
#include "led/led.h"

int main() {
  stdio_init_all();
  led::SetupLeds();
  ButtonController button_controller;
  button::SetupButtons(button_controller);

  return 0;
}

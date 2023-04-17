/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

#include "button/button_setup.h"

ButtonController button_controller;

int main() {
  stdio_init_all();
  SetupButtons({ 10 }, button_controller);

  return 0;
}

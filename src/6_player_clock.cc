/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

#include "button/button.h"
#include "button/button_controller.h"
#include "buzzer/buzzer.h"
#include "clock/clock.h"
#include "display/display.h"
#include "led/led.h"
#include "player/context_switcher.h"

int main() {
  stdio_init_all();
  led::SetupLeds();
  ButtonController button_controller;
  button::SetupButtons(button_controller);
  Buzzer buzzer{18};
  Display display;
  Clock clock{display, buzzer};
  ContextSwitcher context_switcher{clock, 1000};

  while (true) {
    tight_loop_contents();
  }

}

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "led/led.h"

#include <initializer_list>

#include "hardware/gpio.h"

void led::SetupLeds() {
  for (auto player_led_pin : {  kPlayer1LedPin,
                                kPlayer2LedPin,
                                kPlayer3LedPin,
                                kPlayer4LedPin,
                                kPlayer5LedPin,
                                kPlayer6LedPin, }) {
    gpio_init(player_led_pin);
    gpio_set_dir(player_led_pin, true);
  }
}

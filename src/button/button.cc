/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button.h"

#include <initializer_list>

#include "hardware/gpio.h"
#include "hardware/irq.h"

#include "button/button_controller.h"

void button::SetupButtons(ButtonController& button_controller) {
  for (auto player_button_pin : { kPlayer1ButtonPin,
                                  kPlayer2ButtonPin,
                                  kPlayer3ButtonPin,
                                  kPlayer4ButtonPin,
                                  kPlayer5ButtonPin,
                                  kPlayer6ButtonPin }) {
    gpio_init(player_button_pin);
    gpio_pull_up(player_button_pin);
    gpio_set_irq_enabled(player_button_pin, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
  }

  button_controller.SetupAsIrqHandler();
  irq_set_enabled(IO_IRQ_BANK0, true);
}

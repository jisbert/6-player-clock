/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_setup.h"

#include "hardware/gpio.h"

ButtonController *button_controller_ = nullptr;

void Callback(unsigned int gpio, unsigned long event_mask) {  // NOLINT(runtime/int)
  button_controller_->HandleEvent(gpio, event_mask);
}

void SetupButton(std::uint32_t gpio) {
  gpio_init(gpio);
  gpio_pull_up(gpio);
  gpio_set_irq_enabled(gpio, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
}

void SetupButtons(const std::vector<std::uint32_t> gpios, ButtonController button_controller) {
  button_controller_ = &button_controller;

  for (auto gpio : gpios) {
    SetupButton(gpio);
  }

  gpio_set_irq_callback(Callback);
  irq_set_enabled(IO_IRQ_BANK0, true);
}

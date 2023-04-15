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

void SetupPullUpAndEnableIrq(const std::uint32_t gpio_mask) {
  std::uint32_t remaining_gpio_mask = gpio_mask;

  for (std::uint16_t index = 0; index < GPIO_COUNT; index++) {
    std::uint32_t current_index_mask = (1 << index);

    if (gpio_mask & current_index_mask) {
      gpio_pull_up(index);
      gpio_set_irq_enabled(index, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
    }

    remaining_gpio_mask &= ~current_index_mask;

    if (!remaining_gpio_mask) {
      break;
    }
  }
}

void SetupButtonController(std::uint32_t gpio_mask, ButtonController button_controller) {
  button_controller_ = &button_controller;
  gpio_init_mask(gpio_mask);
  SetupPullUpAndEnableIrq(gpio_mask);
  gpio_set_irq_callback(Callback);
  irq_set_enabled(IO_IRQ_BANK0, true);
}

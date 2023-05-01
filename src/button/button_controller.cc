/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_controller.h"

#include "hardware/gpio.h"

void ButtonController::SetupAsIrqHandler() {
  irq_handler_ = this;
  gpio_set_irq_callback(ButtonController::HandleIrqEvent);
}

void ButtonController::button_event_handler(ButtonEventHandler *button_event_handler) {
  this->button_event_handler_ = button_event_handler;
}

ButtonController* ButtonController::irq_handler_ = nullptr;

void ButtonController::HandleIrqEvent(unsigned int gpio, unsigned long event_mask) {  // NOLINT(runtime/int)
  irq_handler_->HandleEvent(gpio, event_mask);
}

void ButtonController::HandleEvent(std::uint16_t gpio, std::uint32_t event_mask) {
  if (event_mask & GPIO_IRQ_EDGE_FALL) {
    button_event_handler_->HandlePressed(gpio);
  }
}

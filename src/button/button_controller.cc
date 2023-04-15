/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_controller.h"

#include "hardware/gpio.h"

void ButtonController::button_event_handler(ButtonEventHandler *button_event_handler) {
  this->button_event_handler_ = button_event_handler;
}

void ButtonController::HandleEvent(std::uint16_t gpio, std::uint32_t event_mask) {}

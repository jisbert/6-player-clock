/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_controller.h"

#include "button/button_handler.h"

ButtonController::ButtonController(unsigned int gpio): gpio_(gpio) {}

void ButtonController::handler(ButtonHandler *handler) {
  this->handler_ = handler;
}

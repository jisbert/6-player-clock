/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUTTON_BUTTON_CONTROLLER_H_
#define BUTTON_BUTTON_CONTROLLER_H_

#include <cstdint>

#include "hardware/gpio.h"

#include "button/button_event_handler.h"

class ButtonController {
  // list of active events
  ButtonEventHandler *button_event_handler_;
 public:  // editorconfig-checker-disable-line
  void button_event_handler(ButtonEventHandler *button_event_handler);
  void HandleEvent(std::uint16_t gpio, std::uint32_t event_mask);
};

#endif  // BUTTON_BUTTON_CONTROLLER_H_

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUTTON_BUTTON_CONTROLLER_H_
#define BUTTON_BUTTON_CONTROLLER_H_

#include <cstdint>

#include "button/button_event_handler.h"

class ButtonController {
 public:  // editorconfig-checker-disable-line
  virtual void SetupAsIrqHandler();
  void button_event_handler(ButtonEventHandler *button_event_handler);
 private:  // editorconfig-checker-disable-line
  static ButtonController* irq_handler_;
  static void HandleIrqEvent(unsigned int gpio, unsigned long event_mask);  // NOLINT(runtime/int)
  int held_button_mask_ = 0;
  ButtonEventHandler *button_event_handler_ = nullptr;
  void HandleEvent(std::uint16_t gpio, std::uint32_t event_mask);
};

#endif  // BUTTON_BUTTON_CONTROLLER_H_

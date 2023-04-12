/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUTTON_BUTTON_CONTROLLER_H_
#define BUTTON_BUTTON_CONTROLLER_H_

#include "button/button_handler.h"

class ButtonController {
  const unsigned int gpio_;
  ButtonHandler *handler_;
 public:  // editorconfig-checker-disable-line
  explicit ButtonController(unsigned int gpio);
  void handler(ButtonHandler *handler);
};

#endif  // BUTTON_BUTTON_CONTROLLER_H_

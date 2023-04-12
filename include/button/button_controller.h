/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIX_PLAYER_CLOCK_BUTTON_BUTTON_CONTROLLER_H_
#define SIX_PLAYER_CLOCK_BUTTON_BUTTON_CONTROLLER_H_

#include "button/button_handler.h"

class ButtonController {
  const unsigned int gpio_;
  ButtonHandler *handler_;
public:
  ButtonController(unsigned int gpio);
  void handler(ButtonHandler *handler);
};

#endif

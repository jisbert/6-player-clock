/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIX_PLAYER_CLOCK_BUTTON_BUTTON_HANDLER_H_
#define SIX_PLAYER_CLOCK_BUTTON_BUTTON_HANDLER_H_
#include "button_event.h"

class ButtonHandler {
  public:
    virtual void HandlePressed(ButtonEvent event);
};

#endif

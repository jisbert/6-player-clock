/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUTTON_BUTTON_EVENT_HANDLER_H_
#define BUTTON_BUTTON_EVENT_HANDLER_H_

#include "button/button_event.h"

class ButtonEventHandler {
 public:  // editorconfig-checker-disable-line
  virtual void HandlePressed(ButtonEvent event);
};

#endif  // BUTTON_BUTTON_EVENT_HANDLER_H_

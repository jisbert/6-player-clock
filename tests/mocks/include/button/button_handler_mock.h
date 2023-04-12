/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MOCKS_BUTTON_BUTTON_HANDLER_MOCK_H_
#define MOCKS_BUTTON_BUTTON_HANDLER_MOCK_H_

#include "button/button_handler.h"

#include "CppUTestExt/MockSupport.h"

class ButtonHandlerMock: public ButtonHandler {
  void HandlePressed(ButtonEvent event) final;
};

#endif // MOCKS_BUTTON_BUTTON_HANDLER_MOCK_H_

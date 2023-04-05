/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIX_PLAYER_CLOCK_TESTS_MOCKS_BUTTON_BUTTON_HANDLER_MOCK_H_
#define SIX_PLAYER_CLOCK_TESTS_MOCKS_BUTTON_BUTTON_HANDLER_MOCK_H_
#include "CppUTestExt/MockSupport.h"
#include "button_handler.h"

class ButtonHandlerMock: public ButtonHandler {
  void HandlePressed(ButtonEvent event) final;
};

#endif

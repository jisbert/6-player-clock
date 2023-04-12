/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_controller.h"

#include "CppUTest/TestHarness.h"

#include "button/button_handler.h"
#include "button/button_handler_mock.h"

const unsigned int kGpio = 1;

TEST_GROUP(ButtonController) {
  ButtonController* controller;
  ButtonHandler* handler;

  void setup() {
    handler = new ButtonHandlerMock();
    controller = new ButtonController(kGpio);
    controller->handler(handler);
  }

  void teardown() {
    delete controller;
    delete handler;
  }
};

TEST(ButtonController, General) {
}

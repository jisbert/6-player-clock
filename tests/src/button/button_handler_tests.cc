/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_handler.h"

#include "CppUTest/TestHarness.h"

#include "button/button_event.h"
#include "button/button_handler_mock.h"

TEST_GROUP(ButtonHandler) {
  ButtonHandler* button;

  void setup() {
    button = new ButtonHandlerMock();
  }

  void teardown() {
    delete button;
  }
};

TEST(ButtonHandler, General) {
  mock().expectOneCall("HandlePressed");
  ButtonEvent event(1u);
  button->HandlePressed(event);
}

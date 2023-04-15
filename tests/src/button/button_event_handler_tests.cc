/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "button/button_event.h"
#include "button/button_event_handler_mock.h"

TEST_GROUP(ButtonEventHandler) {
  ButtonEventHandler* button;

  void setup() {
    button = new ButtonEventHandlerMock();
  }

  void teardown() {
    delete button;
  }
};

TEST(ButtonEventHandler, General) {
  mock().expectOneCall("HandlePressed");
  ButtonEvent event(1u);
  button->HandlePressed(event);
}

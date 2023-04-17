/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "6_player_clock.h"  // NOLINT(build/include_subdir)
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
  std::uint32_t gpio = PLAYER_1_BUTTON_PIN;
  mock().expectOneCall("HandlePressed").withParameter("gpio", gpio);
  button->HandlePressed(gpio);
}

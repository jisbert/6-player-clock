/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "player/context_switcher.h"

#include <cstdint>

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "clock/clock.h"
#include "clock/clock_mock.h"
#include "led/led.h"
#include "led/led_mock.h"

namespace context_switcher_tests {
  constexpr std::uint16_t kStartingNumberOfSeconds = 1000;
}  // namespace context_switcher_tests


TEST_GROUP(ContextSwitcher) {
  Led* led_;
  Clock* clock_;
  ContextSwitcher* context_switcher_;

  void setup() {
    led_ = new LedMock();
    clock_ = new ClockMock();
    context_switcher_ = new ContextSwitcher(led_, clock_, context_switcher_tests::kStartingNumberOfSeconds);
  }

  void teardown() {
    delete context_switcher_;
    delete clock_;
    delete led_;
  }
};

TEST(ContextSwitcher, HandlePressed) {
  mock("clock").expectOneCall("Pause");
  mock("clock").expectOneCall("remaining_seconds");
  mock("led").expectOneCall("SwitchOnOnly").withParameter("led_pin", led::kPlayer1LedPin);
  mock("clock").expectOneCall("Resume")
    .withParameter("remaining_seconds", context_switcher_tests::kStartingNumberOfSeconds);
  context_switcher_->HandlePressed(button::kPlayer1ButtonPin);
}

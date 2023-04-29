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

namespace context_switcher_tests {
  constexpr std::uint16_t kStartingNumberOfSeconds = 1000;
} // namespace context_switcher_tests


TEST_GROUP(ContextSwitcher) {
  ContextSwitcher* context_switcher_;
  Clock* clock_;

  void setup() {
    clock_ = new ClockMock();
    context_switcher_ = new ContextSwitcher(clock_, context_switcher_tests::kStartingNumberOfSeconds);
  }

  void teardown() {
    delete context_switcher_;
    delete clock_;
  }
};

TEST(ContextSwitcher, HandlePressed) {
  FAIL("Not yet implemented");
}

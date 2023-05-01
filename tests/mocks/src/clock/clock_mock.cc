/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "clock/clock_mock.h"

#include "CppUTestExt/MockSupport.h"

ClockMock::ClockMock() : Clock(nullptr, nullptr) {}

// TODO(jisbert): return expected value
bool ClockMock::Pause() {
  mock("clock").actualCall("Pause");

  return true;
}

// TODO(jisbert): return expected value
bool ClockMock::Resume(std::uint16_t remaining_seconds) {
  mock("clock").actualCall("Resume").withParameter("remaining_seconds", remaining_seconds);

  return true;
}

std::uint16_t ClockMock::remaining_seconds() {
  mock("clock").actualCall("remaining_seconds");

  return clock_mock::kRemainingSeconds;
}

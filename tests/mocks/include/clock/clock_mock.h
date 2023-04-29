/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_CLOCK_MOCK_H_
#define CLOCK_CLOCK_MOCK_H_

#include "clock/clock.h"

#include <cstdint>

namespace clock_mock {
  constexpr std::uint16_t kRemainingSeconds = 5;
} // namespace clock_mock


class ClockMock : public Clock {
 public:  // editorconfig-checker-disable-line
  ClockMock();
  void Pause();
  void Resume(std::uint16_t remaining_seconds);
  std::uint16_t remaining_seconds();
};

#endif  // CLOCK_CLOCK_MOCK_H_

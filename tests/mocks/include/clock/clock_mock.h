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
}  // namespace clock_mock


class ClockMock : public Clock {
 public:  // editorconfig-checker-disable-line
  ClockMock();
  bool Pause() final;
  bool Resume(std::uint16_t remaining_seconds) final;
  std::uint16_t remaining_seconds() final;
};

#endif  // CLOCK_CLOCK_MOCK_H_

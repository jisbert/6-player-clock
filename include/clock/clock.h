/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_CLOCK_H_
#define CLOCK_CLOCK_H_

#include <cstdint>

#include "buzzer/buzzer.h"
#include "display/display.h"
#include "player/player_context.h"

class Clock {
  const Buzzer& buzzer_;
  const Display& display_;
  std::uint32_t remaining_seconds_;
 public:  // editorconfig-checker-disable-line
  void Pause() const;
  void Resume(std::uint32_t remaining_seconds);
  std::uint32_t remaining_seconds() const;
};

#endif  // CLOCK_CLOCK_H_

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
 public:  // editorconfig-checker-disable-line
  Clock(Buzzer* buzzer, Display* display);
  virtual void Pause();
  virtual void Resume(std::uint16_t remaining_seconds);
  virtual std::uint16_t remaining_seconds();
 private:  // editorconfig-checker-disable-line
  Buzzer* buzzer_;
  Display* display_;
  std::uint16_t remaining_seconds_;
};

#endif  // CLOCK_CLOCK_H_

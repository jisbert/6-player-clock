/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_CLOCK_H_
#define CLOCK_CLOCK_H_

#include <cstdint>

#include "pico/time.h"

#include "buzzer/buzzer.h"
#include "display/display.h"
#include "player/player_context.h"

namespace clock_clock {
  constexpr std::int16_t k1SecondDelayInMs = -1000;
}  // namespace clock_clock


class Clock {
 public:  // editorconfig-checker-disable-line
  Clock(Buzzer* buzzer, Display* display);
  virtual bool Pause();
  virtual bool Resume(std::uint16_t remaining_seconds);
  virtual std::uint16_t remaining_seconds();
 private:  // editorconfig-checker-disable-line
  Buzzer* buzzer_;
  Display* display_;
  repeating_timer_t* repeating_timer_;
  std::uint16_t remaining_seconds_;
  static bool RepeatingTimerCallback(repeating_timer_t* repeating_timer);
};

#endif  // CLOCK_CLOCK_H_

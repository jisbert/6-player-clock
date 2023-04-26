/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "clock/clock.h"

#include <cstdint>

#include "buzzer/buzzer.h"
#include "display/display.h"
#include "player/player_context.h"

Clock::Clock(Display* display, Buzzer* buzzer): display_(display), buzzer_(buzzer) {}

void Clock::Resume(std::uint32_t remaining_seconds) {}

void Clock::Pause() const {}

std::uint32_t Clock::remaining_seconds() const {
  return remaining_seconds_;
}

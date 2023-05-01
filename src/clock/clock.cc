/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "clock/clock.h"

#include <cstdint>

#include "buzzer/buzzer.h"
#include "display/display.h"
#include "player/player_context.h"

Clock::Clock(Buzzer* buzzer, Display* display): buzzer_(buzzer), display_(display) {}

void Clock::Resume(std::uint16_t remaining_seconds) {
  buzzer_->Beep();
  display_->ShowAsMinutesAndSeconds(remaining_seconds);
  remaining_seconds_ = remaining_seconds;
}

void Clock::Pause() {}

std::uint16_t Clock::remaining_seconds() {
  return remaining_seconds_;
}

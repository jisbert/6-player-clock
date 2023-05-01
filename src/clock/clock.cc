/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "clock/clock.h"

#include <cstdint>

#include "pico/time.h"

#include "buzzer/buzzer.h"
#include "display/display.h"
#include "player/player_context.h"

bool Clock::RepeatingTimerCallback(repeating_timer_t* repeating_timer) {
  Clock* clock = static_cast<Clock*>(repeating_timer->user_data);
  clock->display_->ShowAsMinutesAndSeconds(clock->remaining_seconds_);

  return --(clock->remaining_seconds_) >= 0;
}

Clock::Clock(Buzzer* buzzer, Display* display): buzzer_(buzzer), display_(display) {}

void Clock::Resume(std::uint16_t remaining_seconds) {
  remaining_seconds_ = remaining_seconds;

  if (remaining_seconds_ > 0) {
    buzzer_->Beep();
    add_repeating_timer_ms(clock_clock::k1SecondDelayInMs, Clock::RepeatingTimerCallback, this, repeating_timer_);
  } else {
    buzzer_->Beep(2);
  }
}

void Clock::Pause() {
  cancel_repeating_timer(repeating_timer_);
  repeating_timer_ = nullptr;
}

std::uint16_t Clock::remaining_seconds() {
  return remaining_seconds_;
}

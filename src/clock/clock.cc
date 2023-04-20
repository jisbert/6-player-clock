/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "clock/clock.h"

#include "buzzer/buzzer.h"
#include "display/display.h"
#include "player/player_context.h"

Clock::Clock(Buzzer buzzer, Display display): buzzer_(buzzer), display_(display), player_context_(nullptr) {}

void Clock::player_context(PlayerContext player_context) {
  player_context_ = &player_context;
}

void Clock::Start() {}

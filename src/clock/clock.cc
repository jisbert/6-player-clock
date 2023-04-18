/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "clock/clock.h"

#include "buzzer/buzzer.h"
#include "display/display.h"

Clock::Clock(Buzzer buzzer, Display display): buzzer_(buzzer), display_(display) {}

void Clock::Start(std::uint32_t initial_seconds) {}

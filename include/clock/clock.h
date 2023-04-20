/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_CLOCK_H_
#define CLOCK_CLOCK_H_

#include "buzzer/buzzer.h"
#include "display/display.h"
#include "player/player_context.h"

class Clock {
  const Buzzer buzzer_;
  const Display display_;
  PlayerContext *player_context_;
 public:  // editorconfig-checker-disable-line
  Clock(Buzzer buzzer, Display display);
  void player_context(PlayerContext player_context);
  void Start();
};

#endif  // CLOCK_CLOCK_H_

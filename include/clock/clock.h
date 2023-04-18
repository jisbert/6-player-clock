/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_CLOCK_H_
#define CLOCK_CLOCK_H_

#include "buzzer/buzzer.h"
#include "display/display.h"

class Clock {
  const Buzzer buzzer_;
  const Display display_;
 public:  // editorconfig-checker-disable-line
  Clock(Buzzer buzzer, Display display);
  void Start(std::uint32_t initial_seconds);
};

#endif  // CLOCK_CLOCK_H_

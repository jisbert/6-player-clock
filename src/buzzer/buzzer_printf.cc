/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "buzzer/buzzer.h"

#include <cstdio>

#include "pico/stdlib.h"

Buzzer::Buzzer(unsigned int buzzer_pin): buzzer_pin_(buzzer_pin) {}

void Buzzer::Beep() {
  printf("Beep\n");
}

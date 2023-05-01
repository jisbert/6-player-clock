/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "buzzer/buzzer.h"

#include <cstdint>
#include <cstdio>

#include "pico/stdlib.h"

Buzzer::Buzzer(unsigned int buzzer_pin): buzzer_pin_(buzzer_pin) {}

void Buzzer::Beep(std::uint16_t number_of_beeps) {
  for (int index = 0; index < number_of_beeps; index++) {
    printf("Beep\n");
  }
}

void Buzzer::Beep() {
  Beep(1);
}

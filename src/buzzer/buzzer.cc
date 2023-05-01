/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "buzzer/buzzer.h"

#include <cstdint>

Buzzer::Buzzer(unsigned int buzzer_pin): buzzer_pin_(buzzer_pin) {}

void Buzzer::Beep() {
  Beep(1);
}

void Buzzer::Beep(std::uint16_t number_of_beeps) {}

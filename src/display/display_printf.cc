/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "display/display.h"

#include <cstdint>

#include <cstdio>

#include "pico/stdlib.h"

void Display::ShowAsMinutesAndSeconds(std::uint16_t seconds) {
  printf("%u\n", seconds);
  printf("%02u:%02u\n", (seconds/60)%100, seconds%60);
}

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>

#include "pico/stdlib.h"

#include "buzzer/buzzer.h"

int main() {
  stdio_init_all();
  Buzzer buzzer(1);
  return 0;
}

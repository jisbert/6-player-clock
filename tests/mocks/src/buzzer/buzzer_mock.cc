/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "buzzer/buzzer_mock.h"

#include "CppUTestExt/MockSupport.h"

void BuzzerMock::Beep() {
  mock("buzzer").actualCall("Beep");
}

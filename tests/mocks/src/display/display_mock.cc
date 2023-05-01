/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "display/display_mock.h"

#include <cstdint>

#include "CppUTestExt/MockSupport.h"

void DisplayMock::ShowAsMinutesAndSeconds(std::uint16_t seconds) {
  mock("display").actualCall("ShowAsMinutesAndSeconds").withParameter("seconds", seconds);
}

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "led/led_mock.h"

#include <cstdint>

#include "CppUTestExt/MockSupport.h"

void LedMock::SwitchOnOnly(std::uint16_t led_pin) const {
  mock("led").actualCall("SwitchOnOnly").withParameter("led_pin", led_pin);
}

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_event_handler_mock.h"

#include <cstdint>

#include "CppUTestExt/MockSupport.h"

void ButtonEventHandlerMock::HandlePressed(std::uint16_t gpio) {
  mock().actualCall("HandlePressed").withParameter("gpio", gpio);
}

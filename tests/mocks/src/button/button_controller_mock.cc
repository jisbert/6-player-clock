/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_controller_mock.h"

#include "CppUTestExt/MockSupport.h"

void ButtonControllerMock::SetupAsIrqHandler() {
  mock("button_controller").actualCall("SetupAsIrqHandler");
}

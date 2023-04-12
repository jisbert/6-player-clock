/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_handler_mock.h"

#include "button/button_event.h"

void ButtonHandlerMock::HandlePressed(ButtonEvent event) {
  mock().actualCall("HandlePressed");
}

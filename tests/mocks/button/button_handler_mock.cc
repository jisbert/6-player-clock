/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "./button_event.h"
#include "./button_handler_mock.h"

void ButtonHandlerMock::HandlePressed(ButtonEvent event) {
  mock().actualCall("HandlePressed");
}

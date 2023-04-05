/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "./button_event.h"

ButtonEvent::ButtonEvent(unsigned int gpio): gpio_(gpio) {}

unsigned int ButtonEvent::gpio() {
  return gpio_;
}

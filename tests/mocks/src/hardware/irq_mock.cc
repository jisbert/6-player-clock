/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hardware/irq.h"

#include "CppUTestExt/MockSupport.h"

void irq_set_enabled(unsigned int num, bool enabled) {
  mock("irq").actualCall("irq_set_enabled").withParameter("num", num).withParameter("enabled", enabled);
}

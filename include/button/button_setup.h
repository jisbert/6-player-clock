/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUTTON_BUTTON_SETUP_H_
#define BUTTON_BUTTON_SETUP_H_

#include <cstdint>

#include "button/button_controller.h"

#define GPIO_COUNT 30

void SetupButtonController(const std::uint32_t gpio_mask, ButtonController button_controller);

#endif  // BUTTON_BUTTON_SETUP_H_

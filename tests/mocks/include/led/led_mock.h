/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LED_LED_MOCK_H_
#define LED_LED_MOCK_H_

#include "led/led.h"

#include <cstdint>

class LedMock : public Led {
 public:  // editorconfig-checker-disable-line
  void SwitchOnOnly(std::uint16_t led_pin) const final;
};

#endif  // LED_LED_MOCK_H_

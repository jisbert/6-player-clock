/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LED_LED_H_
#define LED_LED_H_

#include <cstdint>

namespace led {
  constexpr std::uint16_t kUndefinedLedPin = 50;
  constexpr std::uint16_t kPlayer1LedPin = 2;
  constexpr std::uint16_t kPlayer2LedPin = 3;
  constexpr std::uint16_t kPlayer3LedPin = 4;
  constexpr std::uint16_t kPlayer4LedPin = 5;
  constexpr std::uint16_t kPlayer5LedPin = 6;
  constexpr std::uint16_t kPlayer6LedPin = 7;

  void SetupLeds();
}  // namespace led


#endif  // LED_LED_H_

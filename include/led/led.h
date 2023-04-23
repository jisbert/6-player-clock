/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LED_LED_H_
#define LED_LED_H_

#include <cstdint>

namespace led {
  constexpr std::uint16_t kUndefinedLedPin = 0;
  constexpr std::uint16_t kPlayer1LedPin = 11;
  constexpr std::uint16_t kPlayer2LedPin = 12;
  constexpr std::uint16_t kPlayer3LedPin = 13;
  constexpr std::uint16_t kPlayer4LedPin = 14;
  constexpr std::uint16_t kPlayer5LedPin = 15;
  constexpr std::uint16_t kPlayer6LedPin = 16;

  void SetupLeds();
}  // namespace led


#endif  // LED_LED_H_

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _6_PLAYER_CLOCK_H_  // NOLINT(build/header_guard)
#define _6_PLAYER_CLOCK_H_

#include <cstdint>

constexpr std::uint16_t kGpioCount = 30;
constexpr std::uint16_t playerCount = 6;
constexpr std::uint16_t kPlayer1LedPin = 11;
constexpr std::uint16_t kPlayer2LedPin = 12;
constexpr std::uint16_t kPlayer3LedPin = 13;
constexpr std::uint16_t kPlayer4LedPin = 14;
constexpr std::uint16_t kPlayer5LedPin = 15;
constexpr std::uint16_t kPlayer6LedPin = 16;
constexpr std::uint16_t kPlayer1ButtonPin = 20;
constexpr std::uint16_t kPlayer2ButtonPin = 21;
constexpr std::uint16_t kPlayer3ButtonPin = 22;
constexpr std::uint16_t kPlayer4ButtonPin = 23;
constexpr std::uint16_t kPlayer5ButtonPin = 24;
constexpr std::uint16_t kPlayer6ButtonPin = 25;

#endif  // _6_PLAYER_CLOCK_H_  // NOLINT(build/header_guard)

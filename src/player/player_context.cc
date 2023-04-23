/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "player/player_context.h"

#include <cstdint>

#include "led/led.h"

PlayerContext PlayerContext::default_player_context_{led::kUndefinedLedPin, 0};

PlayerContext::PlayerContext(
    std::uint32_t led_pin,
    std::uint32_t remaining_seconds) : led_pin_(led_pin), remaining_seconds_(remaining_seconds) {}

std::int16_t PlayerContext::led_pin() {
  return led_pin_;
}

std::uint32_t PlayerContext::remaining_seconds() {
  return remaining_seconds_;
}

void PlayerContext::remaining_seconds(std::uint32_t remaining_seconds) {
  remaining_seconds_ = remaining_seconds;
}

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "player/player_context.h"

#include <cstdint>

PlayerContext::PlayerContext(std::uint32_t led_gpio, std::uint32_t remaining_seconds) : led_gpio_(led_gpio), remaining_seconds_(remaining_seconds) {}  // NOLINT(whitespace/line_length)

std::uint32_t PlayerContext::remaining_seconds() {
  return remaining_seconds_;
}

void PlayerContext::remaining_seconds(std::uint32_t remaining_seconds) {
  remaining_seconds_ = remaining_seconds;
}

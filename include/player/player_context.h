/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLAYER_PLAYER_CONTEXT_H_
#define PLAYER_PLAYER_CONTEXT_H_

#include <cstdint>

struct PlayerContext {
  const std::uint32_t led_gpio;
  const std::uint32_t remaining_seconds;
};

#endif  // PLAYER_PLAYER_CONTEXT_H_

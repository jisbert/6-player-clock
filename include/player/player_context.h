/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLAYER_PLAYER_CONTEXT_H_
#define PLAYER_PLAYER_CONTEXT_H_

#include <cstdint>

class PlayerContext {
  const std::uint32_t led_gpio_;
  std::uint32_t remaining_seconds_;
 public:
  PlayerContext(std::uint32_t led_gpio, std::uint32_t remaining_seconds);
  std::uint32_t remaining_seconds();
  void remaining_seconds(std::uint32_t remaining_seconds);
};

#endif  // PLAYER_PLAYER_CONTEXT_H_

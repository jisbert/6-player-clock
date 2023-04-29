/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLAYER_PLAYER_CONTEXT_H_
#define PLAYER_PLAYER_CONTEXT_H_

#include <cstdint>

class PlayerContext {
 public:  // editorconfig-checker-disable-line
  static PlayerContext default_player_context_;
  PlayerContext(std::uint16_t led_pin, std::uint16_t remaining_seconds);
  std::int16_t led_pin();
  std::uint16_t remaining_seconds();
  void remaining_seconds(std::uint16_t remaining_seconds);
 private:  // editorconfig-checker-disable-line
  const std::uint16_t led_pin_;
  std::uint16_t remaining_seconds_;
};

#endif  // PLAYER_PLAYER_CONTEXT_H_

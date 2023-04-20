/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "player/context_switcher.h"

#include <algorithm>
#include <cstdint>
#include <unordered_map>
#include <vector>

ContextSwitcher::ContextSwitcher(Clock *clock, std::unordered_map<std::uint32_t, std::uint32_t> button_to_led_map_, std::uint32_t initial_time) : clock_(clock) {  // NOLINT(whitespace/line_length)
  player_context_map_;

  for (auto button_to_led_pair : button_to_led_map_) {
    player_context_map_.emplace(button_to_led_pair.first, PlayerContext(button_to_led_pair.first, initial_time));
  }
}

void ContextSwitcher::HandlePressed(std::uint32_t gpio) {
  auto tuple = player_context_map_.find(gpio);

  if (tuple != player_context_map_.end()) {
    clock_->player_context(tuple->second);
    clock_->Start();
  }
}

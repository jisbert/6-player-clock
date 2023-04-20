/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "player/context_switcher.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

ContextSwitcher::ContextSwitcher(Clock& clock, std::unordered_map<std::uint32_t, std::uint32_t> button_to_led_map_, std::uint32_t initial_time) : clock_(clock) {  // NOLINT(whitespace/line_length)
  player_context_map_;
  player_context_map_.reserve(button_to_led_map_.size());

  for (auto button_to_led_pair : button_to_led_map_) {
    player_context_map_.emplace(button_to_led_pair.first, PlayerContext(button_to_led_pair.first, initial_time));
  }
}

void ContextSwitcher::SaveLastPlayerContext() {
  auto last_player_context = player_context_map_.find(last_button_pressed_);

  if (last_player_context != player_context_map_.end()) {
    last_player_context->second.remaining_seconds(clock_.remaining_seconds());
  }
}

void ContextSwitcher::ResumeClockWithCurrentPlayerContext(std::uint32_t button_pressed) {
  auto tuple = player_context_map_.find(button_pressed);

  if (tuple != player_context_map_.end()) {
    last_button_pressed_ = button_pressed;
    clock_.Resume(tuple->second.remaining_seconds());
  }
}

void ContextSwitcher::HandlePressed(std::uint32_t button_pressed) {
  clock_.Pause();
  SaveLastPlayerContext();
  ResumeClockWithCurrentPlayerContext(button_pressed);
}

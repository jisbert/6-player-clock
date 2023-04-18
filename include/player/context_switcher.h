/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLAYER_CONTEXT_SWITCHER_H_
#define PLAYER_CONTEXT_SWITCHER_H_

#include <cstdint>
#include <map>

#include "button/button_event_handler.h"
#include "player/player_context.h"

class ContextSwitcher : ButtonEventHandler {
  std::map<std::uint32_t, PlayerContext> context_map_;
 public:  // editorconfig-checker-disable-line
  ContextSwitcher(std::map<std::uint32_t, std::uint32_t> button_to_led_map_, std::uint32_t initial_time);
  void HandlePressed(std::uint32_t gpio) final;
};

#endif  // PLAYER_CONTEXT_SWITCHER_H_

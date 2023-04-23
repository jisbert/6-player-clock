/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLAYER_CONTEXT_SWITCHER_H_
#define PLAYER_CONTEXT_SWITCHER_H_

#include <cstdint>
#include <unordered_map>

#include "button/button.h"
#include "button/button_event_handler.h"
#include "clock/clock.h"
#include "player/player_context.h"

class ContextSwitcher : public ButtonEventHandler {
 public:  // editorconfig-checker-disable-line
  // TODO(jisbert): Can be clock passed like this const Clock& clock
  ContextSwitcher(Clock& clock, std::uint32_t initial_time);  // NOLINT(*)
  void HandlePressed(std::uint16_t button_pin) final;
 private:  // editorconfig-checker-disable-line
  Clock& clock_;
  std::unordered_map<std::uint16_t, PlayerContext> player_context_map_;
  PlayerContext* last_player_context_;
  void UpdateLastPlayerRemainingSeconds();
  void SwitchContext(std::uint16_t button_pin);
  void SwitchLed(std::uint16_t clearing_led_pin, std::uint16_t setting_lend_pin);
  void ResumeClock();
};

#endif  // PLAYER_CONTEXT_SWITCHER_H_

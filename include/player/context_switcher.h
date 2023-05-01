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
#include "led/led.h"
#include "player/player_context.h"

class ContextSwitcher : public ButtonEventHandler {
 public:  // editorconfig-checker-disable-line
  ContextSwitcher(Led* led, Clock* clock, std::uint16_t starting_number_of_seconds);
  void HandlePressed(std::uint16_t button_pin) override;
 private:  // editorconfig-checker-disable-line
  Led* led_;
  Clock* clock_;
  std::unordered_map<std::uint16_t, PlayerContext> player_context_map_;
  PlayerContext* last_player_context_;
  void UpdateLastPlayerRemainingSeconds();
  void SwitchContext(std::uint16_t button_pin);
  void SwitchOnOnlyLed(std::uint16_t led_pin);
  void ResumeClock();
};

#endif  // PLAYER_CONTEXT_SWITCHER_H_

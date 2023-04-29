/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "player/context_switcher.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

#include "hardware/gpio.h"

#include "button/button.h"
#include "clock/clock.h"
#include "led/led.h"
#include "player/player_context.h"

ContextSwitcher::ContextSwitcher(
    Clock* clock,
    std::uint16_t starting_number_of_seconds) : clock_(clock), last_player_context_(&PlayerContext::default_player_context_) {
  player_context_map_ = {
    {button::kPlayer1ButtonPin, {led::kPlayer1LedPin, starting_number_of_seconds}},
    {button::kPlayer2ButtonPin, {led::kPlayer2LedPin, starting_number_of_seconds}},
    {button::kPlayer3ButtonPin, {led::kPlayer3LedPin, starting_number_of_seconds}},
    {button::kPlayer4ButtonPin, {led::kPlayer4LedPin, starting_number_of_seconds}},
    {button::kPlayer5ButtonPin, {led::kPlayer5LedPin, starting_number_of_seconds}},
    {button::kPlayer6ButtonPin, {led::kPlayer6LedPin, starting_number_of_seconds}},
  };
}

void ContextSwitcher::UpdateLastPlayerRemainingSeconds() {
  clock_->Pause();
  last_player_context_->remaining_seconds(clock_->remaining_seconds());
}

void ContextSwitcher::SwitchContext(std::uint16_t button_pin) {
  auto iterator = player_context_map_.find(button_pin);

  if (iterator != player_context_map_.end()) {
    std::uint16_t clearing_led_pin = last_player_context_->led_pin();
    last_player_context_ = &iterator->second;
    std::uint16_t setting_led_pin = last_player_context_->led_pin();
    SwitchLed(clearing_led_pin, setting_led_pin);
    ResumeClock();
  }
}

void ContextSwitcher::SwitchLed(std::uint16_t clearing_led_pin, std::uint16_t setting_lend_pin) {
  gpio_put(clearing_led_pin, false);
  gpio_put(setting_lend_pin, true);
}

void ContextSwitcher::ResumeClock() {
  clock_->Resume(last_player_context_->remaining_seconds());
}

void ContextSwitcher::HandlePressed(std::uint16_t button_pin) {
  UpdateLastPlayerRemainingSeconds();
  SwitchContext(button_pin);
}

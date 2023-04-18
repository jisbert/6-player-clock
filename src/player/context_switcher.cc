/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "player/context_switcher.h"

ContextSwitcher::ContextSwitcher(std::map<std::uint32_t, std::uint32_t> button_to_led_map_, std::uint32_t initial_time) {
  context_map_;
}

void ContextSwitcher::HandlePressed(std::uint32_t gpio) {}

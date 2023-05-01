/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUTTON_BUTTON_H_
#define BUTTON_BUTTON_H_

#include "button/button_controller.h"

namespace button {
  constexpr std::uint16_t kUndefinedButtonPin = 50;
  constexpr std::uint16_t kPlayer1ButtonPin = 20;
  constexpr std::uint16_t kPlayer2ButtonPin = 21;
  constexpr std::uint16_t kPlayer3ButtonPin = 22;
  constexpr std::uint16_t kPlayer4ButtonPin = 8;
  constexpr std::uint16_t kPlayer5ButtonPin = 9;
  constexpr std::uint16_t kPlayer6ButtonPin = 10;

  void SetupButtons(ButtonController& button_controller_);  // NOLINT(runtime/references)
}  // namespace button


#endif  // BUTTON_BUTTON_H_

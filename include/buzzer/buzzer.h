/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUZZER_BUZZER_H_
#define BUZZER_BUZZER_H_

#include <cstdint>

namespace buzzer {
  constexpr std::uint16_t kBuzzerPin = 18;
}  // namespace buzzer

class Buzzer {
 public:  // editorconfig-checker-disable-line
  explicit Buzzer(unsigned int buzzer_pin);
  virtual void Beep();
 private:  // editorconfig-checker-disable-line
  const unsigned int buzzer_pin_;
};

#endif  // BUZZER_BUZZER_H_

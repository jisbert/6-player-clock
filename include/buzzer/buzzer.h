/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUZZER_BUZZER_H_
#define BUZZER_BUZZER_H_

class Buzzer {
  const unsigned int gpio_;
 public:
  explicit Buzzer(unsigned int gpio);
  void Beep();
};

#endif  // BUZZER_BUZZER_H_

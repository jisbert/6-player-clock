/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIX_PLAYER_CLOCK_BUZZER_BUZZER_H_
#define SIX_PLAYER_CLOCK_BUZZER_BUZZER_H_

class Buzzer {
  const unsigned int gpio_;
public:
  Buzzer(unsigned int gpio);
  void Beep();
};

#endif

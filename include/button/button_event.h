/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIX_PLAYER_CLOCK_BUTTON_BUTTON_EVENT_H_
#define SIX_PLAYER_CLOCK_BUTTON_BUTTON_EVENT_H_

class ButtonEvent {
  const unsigned int gpio_;
  public:
    ButtonEvent(unsigned int gpio);
    unsigned int gpio();
};

#endif

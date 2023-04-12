/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUTTON_BUTTON_EVENT_H_
#define BUTTON_BUTTON_EVENT_H_

class ButtonEvent {
  const unsigned int gpio_;
 public:
  explicit ButtonEvent(unsigned int gpio);
  unsigned int gpio();
};

#endif  // BUTTON_BUTTON_EVENT_H_

/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef DISPLAY_DISPLAY_MOCK_H_
#define DISPLAY_DISPLAY_MOCK_H_

#include "display/display.h"

#include <cstdint>

class DisplayMock : public Display {
 public:  // editorconfig-checker-disable-line
  void ShowAsMinutesAndSeconds(std::uint16_t seconds) final;
};

#endif  // DISPLAY_DISPLAY_MOCK_H_

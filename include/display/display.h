/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef DISPLAY_DISPLAY_H_
#define DISPLAY_DISPLAY_H_

#include <cstdint>

class Display {
 public:  // editorconfig-checker-disable-line
  void Show(std::uint32_t digits[4]);
};

#endif  // DISPLAY_DISPLAY_H_

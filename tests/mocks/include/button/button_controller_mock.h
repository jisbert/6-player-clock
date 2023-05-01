/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUTTON_BUTTON_CONTROLLER_MOCK_H_
#define BUTTON_BUTTON_CONTROLLER_MOCK_H_

#include "button/button_controller.h"

class ButtonControllerMock : public ButtonController {
 public:  // editorconfig-checker-disable-line
  void SetupAsIrqHandler() final;
};

#endif  // BUTTON_BUTTON_CONTROLLER_MOCK_H_

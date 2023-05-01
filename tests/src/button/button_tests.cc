/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button.h"
#include "button/button_controller.h"
#include "button/button_controller_mock.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"

TEST_GROUP(Button) {
  ButtonController* button_controller_;

  void setup() {
    button_controller_ = new ButtonControllerMock();
  }

  void teardown() {
    delete button_controller_;
  }
};

TEST(Button, SetupButtons) {
  for (auto player_button_pin : { button::kPlayer1ButtonPin,
                                  button::kPlayer2ButtonPin,
                                  button::kPlayer3ButtonPin,
                                  button::kPlayer4ButtonPin,
                                  button::kPlayer5ButtonPin,
                                  button::kPlayer6ButtonPin, }) {
    mock("gpio").expectOneCall("gpio_init").withParameter("gpio", player_button_pin);
    mock("gpio").expectOneCall("gpio_pull_up").withParameter("gpio", player_button_pin);
    mock("gpio").expectOneCall("gpio_set_irq_enabled")
      .withParameter("gpio", player_button_pin)
      .withParameter("event_mask", GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL)
      .withParameter("enabled", true);
  }

  mock("irq").expectOneCall("irq_set_enabled")
    .withParameter("num", IO_IRQ_BANK0)
    .withParameter("enabled", true);
  mock("button_controller").expectOneCall("SetupAsIrqHandler");
  button::SetupButtons(*button_controller_);
}


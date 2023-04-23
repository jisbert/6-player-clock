/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button/button_controller.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "hardware/gpio.h"

#include "6_player_clock.h"
#include "button/button_event_handler.h"
#include "button/button_event_handler_mock.h"

TEST_GROUP(ButtonController) {
  void setup() {}

  void teardown() {}
};

IGNORE_TEST(ButtonController, Setup) {
  for (auto player_button_pin : { kPlayer1ButtonPin,
                                  kPlayer2ButtonPin,
                                  kPlayer3ButtonPin,
                                  kPlayer4ButtonPin,
                                  kPlayer5ButtonPin,
                                  kPlayer6ButtonPin}) {
    mock("gpio").expectOneCall("gpio_init").withParameter("gpio", player_button_pin);
    mock("gpio").expectOneCall("gpio_pull_up").withParameter("gpio", player_button_pin);
    mock("gpio").expectOneCall("gpio_set_irq_enabled")
      .withParameter("gpio", player_button_pin)
      .withParameter("event_mask", GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL)
      .withParameter("enabled", true);
  }

  mock("gpio").expectOneCall("gpio_set_irq_callback");
  mock("irq").expectOneCall("irq_set_enabled")
    .withParameter("num", IO_IRQ_BANK0)
    .withParameter("enabled", true);
}


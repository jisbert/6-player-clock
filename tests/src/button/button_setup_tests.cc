/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "button/button_setup.h"

TEST_GROUP(ButtonSetup) {
  ButtonController button_controller;
};

void SetupExpectationsForGpio(std::uint32_t gpio) {
  mock("gpio").expectOneCall("gpio_init").withParameter("gpio", gpio);
  mock("gpio").expectOneCall("gpio_pull_up").withParameter("gpio", gpio);
  mock("gpio").expectOneCall("gpio_set_irq_enabled")
    .withParameter("gpio", gpio)
    .withParameter("event_mask", GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL)
    .withParameter("enabled", true);
}

TEST(ButtonSetup, SetupButtons) {
  std::vector<std::uint32_t> gpios = { 0, 5, 7 };

  for (auto gpio : gpios) {
    SetupExpectationsForGpio(gpio);
  }

  mock("gpio").expectOneCall("gpio_set_irq_callback");
  mock("irq").expectOneCall("irq_set_enabled")
    .withParameter("num", IO_IRQ_BANK0)
    .withParameter("enabled", true);
  SetupButtons(gpios, button_controller);
}

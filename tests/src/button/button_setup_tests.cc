/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "button/button_setup.h"

TEST_GROUP(ButtonSetup) {
  ButtonController button_controller;
};

TEST(ButtonSetup, SetupPullUpAndEnableIrqInitsExpectedGpios) {
  int gpios[]= { 10, 17, 20 };
  std::uint32_t gpio_mask;

  for (auto gpio : gpios) {
    mock("gpio").expectOneCall("gpio_pull_up").withParameter("gpio", gpio);
    mock("gpio").expectOneCall("gpio_set_irq_enabled")
      .withParameter("gpio", gpio)
      .withParameter("event_mask", GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL)
      .withParameter("enabled", true);
    gpio_mask += (1 << gpio);
  }

  mock("gpio").ignoreOtherCalls();
  mock("irq").ignoreOtherCalls();
  SetupButtonController(gpio_mask, button_controller);
}

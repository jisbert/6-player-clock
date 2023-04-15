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

void SetupPullUpAndEnableIrqExpectationsForGpio(std::uint32_t gpio) {
  mock("gpio").expectOneCall("gpio_pull_up").withParameter("gpio", gpio);
  mock("gpio").expectOneCall("gpio_set_irq_enabled")
    .withParameter("gpio", gpio)
    .withParameter("event_mask", GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL)
    .withParameter("enabled", true);
}

std::uint32_t SetupPullUpAndEnableIrqExpectationsForGpiosAndGpioMask(std::vector<std::uint32_t> gpios) {
  std::uint32_t gpio_mask;

  for (auto gpio : gpios) {
    SetupPullUpAndEnableIrqExpectationsForGpio(gpio);
    gpio_mask += (1 << gpio);
  }

  return gpio_mask;
}

TEST(ButtonSetup, SetupPullUpAndEnableIrqInitsExpectedGpios) {
  std::vector<std::uint32_t> gpios = { 1, 5, 7 };
  std::uint32_t gpio_mask = SetupPullUpAndEnableIrqExpectationsForGpiosAndGpioMask(gpios);
  mock("gpio").ignoreOtherCalls();
  mock("irq").ignoreOtherCalls();
  SetupButtonController(gpio_mask, button_controller);
}

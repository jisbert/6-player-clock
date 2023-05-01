/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hardware/gpio.h"

#include "CppUTestExt/MockSupport.h"

void gpio_init(unsigned int gpio) {
  mock("gpio").actualCall("gpio_init").withParameter("gpio", gpio);
}

void gpio_init_mask(unsigned int gpio_mask) {
  mock("gpio").actualCall("gpio_init_mask").withParameter("gpio_mask", gpio_mask);
}

void gpio_pull_up(unsigned int gpio) {
  mock("gpio").actualCall("gpio_pull_up").withParameter("gpio", gpio);
}

void gpio_put(unsigned int gpio, bool value) {
  mock("gpio").actualCall("gpio_put")
    .withParameter("gpio", gpio)
    .withParameter("value", value);
}

void gpio_put_all(uint32_t value) {
  mock("gpio").actualCall("gpio_put_all")
    .withParameter("value", value);
}

void gpio_set_dir(unsigned int gpio, bool out) {
  mock("gpio").actualCall("gpio_set_dir")
    .withParameter("gpio", gpio)
    .withParameter("out", out);
}

// TODO(jgisbert): Implement gpio_irq_callback_t comparator
void gpio_set_irq_callback(gpio_irq_callback_t callback) {
  mock("gpio").actualCall("gpio_set_irq_callback");
}

void gpio_set_irq_enabled(unsigned int gpio, unsigned long event_mask, bool enabled) {  // NOLINT(runtime/int)
  mock("gpio").actualCall("gpio_set_irq_enabled")
    .withParameter("gpio", gpio)
    .withParameter("event_mask", event_mask)
    .withParameter("enabled", enabled);
}

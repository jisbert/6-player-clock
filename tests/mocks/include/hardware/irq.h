/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef HARDWARE_IRQ_H_
#define HARDWARE_IRQ_H_

#include <cstdint>

#define IO_IRQ_BANK0 1

void irq_set_enabled(unsigned int num, bool enabled);

#endif  // HARDWARE_IRQ_H_

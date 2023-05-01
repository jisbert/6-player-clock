/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupportPlugin.h"

int main(int ac, char** av) {
  MockSupportPlugin mockPlugin;
  TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);

  return CommandLineTestRunner::RunAllTests(ac, av);
}

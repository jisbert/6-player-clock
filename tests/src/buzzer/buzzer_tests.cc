/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "CppUTest/TestHarness.h"
#include "./buzzer.h"

TEST_GROUP(Buzzer) {
  Buzzer* buzzer;

  void setup() {
    buzzer = new Buzzer(1);
  }

  void teardown() {
    delete buzzer;
  }
};

TEST(Buzzer, General) {
  CHECK(0 != buzzer);
  CHECK(true);
  CHECK_EQUAL(1, 1);
  LONGS_EQUAL(1, 1);
  DOUBLES_EQUAL(1.000, 1.001, .01);
  STRCMP_EQUAL("hello", "hello");
  FAIL("The prior tests pass, but this one doesn't");
}

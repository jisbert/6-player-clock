#include "CppUTest/TestHarness.h"
#include "Buzzer.hpp"

TEST_GROUP(Buzzer)
{
  Buzzer *buzzer = nullptr;

  void setup() {
    buzzer = new Buzzer(1);
  }

  void teardown() {
    delete buzzer;
  }
};

TEST(Buzzer, Create) {
  CHECK(0 != buzzer);
  CHECK(true);
  CHECK_EQUAL(1,1);
  LONGS_EQUAL(1,1);
  DOUBLES_EQUAL(1.000, 1.001, .01);
  STRCMP_EQUAL("hello", "hello");
  FAIL("The prior tests pass, but this one doesn't");
}
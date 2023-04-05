#include "CppUTest/TestHarness.h"
#include "button_handler_mock.h"

TEST_GROUP(ButtonHandler)
{
  ButtonHandler* button;

  void setup() {
    button = new ButtonHandlerMock();
  }

  void teardown() {
    delete button;
  }
};

TEST(ButtonHandler, General)
{
  mock().expectOneCall("HandlePressed");
  ButtonEvent event = 1;
  button->HandlePressed(event);
}
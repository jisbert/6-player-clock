#include "button_handler_mock.h"

void ButtonHandlerMock::HandlePressed(ButtonEvent event) {
  mock().actualCall("HandlePressed");
}
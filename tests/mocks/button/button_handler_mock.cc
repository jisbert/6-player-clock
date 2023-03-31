#include "button_handler_mock.h"

void ButtonHandlerMock::handlePressed(ButtonEvent event) {
  mock().actualCall("handlePressed");
}
#include "CppUTestExt/MockSupport.h"
#include "button_handler.h"

class ButtonHandlerMock: public ButtonHandler {
  void handlePressed(ButtonEvent event) final;
};
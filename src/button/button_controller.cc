#include "button_controller.h"

ButtonController::ButtonController(unsigned int gpio): gpio_(gpio) {}

void ButtonController::handler(ButtonHandler *handler) {
  this->handler_ = handler;
}
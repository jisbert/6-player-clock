#include "button_controller.h"

ButtonController::ButtonController(unsigned int new_gpio_mask): gpio_mask(new_gpio_mask) {}

void ButtonController::setHandler(ButtonHandler *handler) {
    this->handler = handler;
}
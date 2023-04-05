#ifndef SIX_PLAYER_CLOCK_BUTTON_BUTTON_CONTROLLER_H_
#define SIX_PLAYER_CLOCK_BUTTON_BUTTON_CONTROLLER_H_
#include "button_handler.h"

class ButtonController {
    const unsigned int gpio_mask;
    ButtonHandler *handler;
public:
    ButtonController(unsigned int new_gpio_mask);
    void setHandler(ButtonHandler *handler);
};

#endif
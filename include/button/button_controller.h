#include "button_handler.h"

class ButtonController {
    const unsigned int gpio_mask;
    ButtonHandler *handler;
public:
    ButtonController(unsigned int new_gpio_mask);
    void setHandler(ButtonHandler *handler);
};
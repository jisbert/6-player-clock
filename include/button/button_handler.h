#ifndef SIX_PLAYER_CLOCK_BUTTON_BUTTON_HANDLER_H_
#define SIX_PLAYER_CLOCK_BUTTON_BUTTON_HANDLER_H_
#include "button_event.h"

class ButtonHandler {
    public:
        virtual void handlePressed(ButtonEvent event) =0;
};

#endif
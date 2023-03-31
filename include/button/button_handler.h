#include "button_event.h"

class ButtonHandler {
    public:
        virtual void handlePressed(ButtonEvent event) =0;
};
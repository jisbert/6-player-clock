#include "button_event.h"

ButtonEvent::ButtonEvent(unsigned int gpio): gpio_(gpio) {}

unsigned int ButtonEvent::gpio() {
  return gpio_;
}
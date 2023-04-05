#ifndef SIX_PLAYER_CLOCK_BUTTON_BUTTON_EVENT_H_
#define SIX_PLAYER_CLOCK_BUTTON_BUTTON_EVENT_H_

class ButtonEvent {
  const unsigned int gpio_;
  public:
    ButtonEvent(unsigned int gpio);
    unsigned int gpio();
};

#endif
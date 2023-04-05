#ifndef SIX_PLAYER_CLOCK_BUZZER_BUZZER_H_
#define SIX_PLAYER_CLOCK_BUZZER_BUZZER_H_

class Buzzer {
  const int buzzer_pin;
public:
  Buzzer(int new_buzzer_pin);
  void beep();
};

#endif
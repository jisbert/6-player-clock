#include <stdio.h>
#include "pico/stdlib.h"
#include "buzzer.h"

int main() {
  stdio_init_all();
  Buzzer buzzer(1);
  return 0;
}

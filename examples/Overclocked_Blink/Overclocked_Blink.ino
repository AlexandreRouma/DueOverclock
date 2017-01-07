/*
   This is a modified version of blink example
   When you overclock and arduino due, the delay
   function will not work correctly because it
   is based on the Due's clock. If it get's faster
   the delay function will also end faster.
*/

#include <DueOverclock.h>

void setup() {
  DueOverclock.setCoreFrequency(114); // Set CPU frequency to 114 Mhz
  pinMode(LED_BUILTIN, OUTPUT); // Set LED pin to OUTPUT
}

void loop() {
  digitalWrite(LED_BUILTIN, 1);
  DueOverclock.OCDelay(1000); // Delay with new frequency
  digitalWrite(LED_BUILTIN, 0);
  DueOverclock.OCDelay(1000);
}
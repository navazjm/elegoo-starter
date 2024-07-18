#define F_CPU 16000000UL // Define the CPU clock frequency
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // Set PB5 (pin 13 on the Arduino) as output
  DDRB |= (1 << PB5);

  while (1) {
    // Toggle PB5
    PORTB ^= (1 << PB5);
    _delay_ms(500); // Wait 1 second
  }

  return 0;
}

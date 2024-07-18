#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // Set PB5 (pin 13 on the Arduino) as output
  DDRB |= (1 << PB5);

  while (1) {
    // Toggle PB5
    PORTB ^= (1 << PB5);
    _delay_ms(3000); // Wait 3 seconds
  }

  return 0;
}

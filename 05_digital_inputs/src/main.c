#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PD5
#define BUTTON_A_PIN PB1
#define BUTTON_B_PIN PB0

void setup() {
    // Set LED_PIN as output
    DDRD |= (1 << LED_PIN);
    // Set BUTTON_A_PIN and BUTTON_B_PIN as input with pull-up resistors
    DDRB &= ~(1 << BUTTON_A_PIN);
    PORTB |= (1 << BUTTON_A_PIN);
    DDRB &= ~(1 << BUTTON_B_PIN);
    PORTB |= (1 << BUTTON_B_PIN);
}

int main(void) {
    setup();

    while (1) {
        // Check if button A is pressed
        if (!(PINB & (1 << BUTTON_A_PIN))) {
            // Turn on the LED
            PORTD |= (1 << LED_PIN);
        }
        // Check if button B is pressed
        if (!(PINB & (1 << BUTTON_B_PIN))) {
            // Turn off the LED
            PORTD &= ~(1 << LED_PIN);
        }
    }

    return 0;
}

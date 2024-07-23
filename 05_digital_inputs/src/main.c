#include <avr/io.h>
#include <util/delay.h>

int main(void) {

    // set pins to their corresponding ports
    const uint8_t LED_PIN = PD5;
    const uint8_t BUTTON_A_PIN = PB1;
    const uint8_t BUTTON_B_PIN = PB0;

    // Set LED_PIN as output
    DDRD |= (1 << LED_PIN);

    // Set BUTTON_A_PIN and BUTTON_B_PIN as input with pull-up resistors
    DDRB &= ~(1 << BUTTON_A_PIN);
    PORTB |= (1 << BUTTON_A_PIN);
    DDRB &= ~(1 << BUTTON_B_PIN);
    PORTB |= (1 << BUTTON_B_PIN);

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

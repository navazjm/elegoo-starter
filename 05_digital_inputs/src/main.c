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

/* Additional challenge solution

int main(void) {

    // set pins to their corresponding ports
    const uint8_t LED_PIN = PD5;
    const uint8_t BUTTON_A_PIN = PB1;

    // Set LED_PIN as output
    DDRD |= (1 << LED_PIN);

    // Set BUTTON_A_PIN and BUTTON_B_PIN as input with pull-up resistors
    DDRB &= ~(1 << BUTTON_A_PIN);
    PORTB |= (1 << BUTTON_A_PIN);

    uint8_t is_led_on = 0;      // 0 = LED off, 1 = LED on
    uint8_t is_btn_pressed = 0; // 0 = not pressed, 1 = pressed

    while (1) {
        // Guard clause for checking if button is not pressed
        if (PINB & (1 << BUTTON_A_PIN)) {
            is_btn_pressed = 0;
            continue;
        }

        // Debounce: wait for a short period to confirm the button press
        _delay_ms(50);

        // Guard clause for checking if button is still pressed after debounce
        if (PINB & (1 << BUTTON_A_PIN))
            continue;

        // Guard clause for checking if button was already marked as pressed
        if (is_btn_pressed)
            continue;

        // Toggle the LED state
        is_led_on = !is_led_on;
        if (is_led_on)
            // Turn on the LED
            PORTD |= (1 << LED_PIN);
        else
            // Turn off the LED
            PORTD &= ~(1 << LED_PIN);

        is_btn_pressed = 1;
    }

    return 0;
}
*/

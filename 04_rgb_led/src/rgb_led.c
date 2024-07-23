#include <avr/io.h>
#include <util/delay.h>

#define RED PD6
#define GREEN PD5
#define BLUE PD3
#define DELAY_TIME 10

void setup() {
    // Set pins as outputs
    DDRD |= (1 << RED) | (1 << GREEN) | (1 << BLUE); // Assuming RED, GREEN, BLUE are on PORTB

    // Initialize pin states
    PORTB &= ~((1 << RED) | (1 << GREEN) | (1 << BLUE)); // Set all pins low initially

    // Configure Timer0 for PWM on PB0 (Digital 6) and PB1 (Digital 5)
    TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00) | (1 << WGM01); // Fast PWM mode, non-inverted
    TCCR0B = (1 << CS00);                                                 // No prescaling

    // Configure Timer2 for PWM on PB2 (Digital 3)
    TCCR2A = (1 << COM2B1) | (1 << WGM20) | (1 << WGM21); // Fast PWM mode, non-inverted
    TCCR2B = (1 << CS00);                                 // No prescaling
}

void analog_write(uint8_t pin, uint8_t value) {
    switch (pin) {
    case RED:
        OCR0A = value; // Output value to RED pin
        break;
    case GREEN:
        OCR0B = value; // Output value to GREEN pin
        break;
    case BLUE:
        OCR2B = value; // Output value to BLUE pin
        break;
    default:
        break; // do nothing
    }
}

void loop() {
    uint8_t red_value = 255;
    uint8_t green_value = 0;
    uint8_t blue_value = 0;

    // Fade out RED and bring GREEN full
    for (uint8_t i = 0; i < 255; i++) {
        red_value -= 1;
        green_value += 1;
        analog_write(RED, red_value);
        analog_write(GREEN, green_value);
        _delay_ms(DELAY_TIME);
    }

    red_value = 0;
    green_value = 255;
    blue_value = 0;

    // Fade out GREEN and bring BLUE full
    for (uint8_t i = 0; i < 255; i++) {
        green_value -= 1;
        blue_value += 1;
        analog_write(GREEN, green_value);
        analog_write(BLUE, blue_value);
        _delay_ms(DELAY_TIME);
    }

    red_value = 0;
    green_value = 0;
    blue_value = 255;

    // Fade out BLUE and bring RED full
    for (uint8_t i = 0; i < 255; i++) {
        blue_value -= 1;
        red_value += 1;
        analog_write(BLUE, blue_value);
        analog_write(RED, red_value);
        _delay_ms(DELAY_TIME);
    }
}

int main(void) {
    setup();
    while (1) {
        loop();
    }
}

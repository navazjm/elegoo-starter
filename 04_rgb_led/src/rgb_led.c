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

void analogWrite(uint8_t pin, uint8_t value) {
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
    uint8_t redValue = 255;
    uint8_t greenValue = 0;
    uint8_t blueValue = 0;

    // Fade out RED and bring GREEN full
    for (uint8_t i = 0; i < 255; i++) {
        redValue -= 1;
        greenValue += 1;
        analogWrite(RED, redValue);
        analogWrite(GREEN, greenValue);
        _delay_ms(DELAY_TIME);
    }

    redValue = 0;
    greenValue = 255;
    blueValue = 0;

    // Fade out GREEN and bring BLUE full
    for (uint8_t i = 0; i < 255; i++) {
        greenValue -= 1;
        blueValue += 1;
        analogWrite(GREEN, greenValue);
        analogWrite(BLUE, blueValue);
        _delay_ms(DELAY_TIME);
    }

    redValue = 0;
    greenValue = 0;
    blueValue = 255;

    // Fade out BLUE and bring RED full
    for (uint8_t i = 0; i < 255; i++) {
        blueValue -= 1;
        redValue += 1;
        analogWrite(BLUE, blueValue);
        analogWrite(RED, redValue);
        _delay_ms(DELAY_TIME);
    }
}

int main(void) {
    setup();
    while (1) {
        loop();
    }
}

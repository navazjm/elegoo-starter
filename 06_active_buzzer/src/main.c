#include <avr/io.h>
#include <util/delay.h>

// wrote custom delay function as _delay_ms expects compile time integer constant
void delay_ms(uint16_t ms) {
    while (ms) {
        _delay_ms(1);
        ms--;
    }
}

int main(void) {
    const uint8_t BUZZER_PIN = PB4; // Physical Pin 18 -> Port Pin PB4

    // initialize the buzzer pin as an output
    DDRB |= (1 << BUZZER_PIN);

    uint16_t sound_duration = 500;
    for (int i = 0; i < 20; i++) {
        // gradually shorten the interval of the sound
        if (i < 5) {
            sound_duration = 500;
        } else if (i < 10) {
            sound_duration = 300;
        } else if (i < 20) {
            sound_duration = 100;
        }

        // activate the active buzzer
        PORTB |= (1 << BUZZER_PIN);
        delay_ms(sound_duration);

        // deactivate the active buzzer)
        PORTB &= ~(1 << BUZZER_PIN);
        delay_ms(sound_duration);
    }

    // activate the active buzzer for 5 seconds
    PORTB |= (1 << BUZZER_PIN);
    /* _delay_ms(5000); */
    delay_ms(5000);
    PORTB &= ~(1 << BUZZER_PIN);

    return 0;
}

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define BUZZER_PIN PB0      // Physical Pin 14 -> Port Pin PB0
#define PUSH_SWITCH_PIN PB1 // Physical Pin 15 -> Port Pin PB1

void tone(int16_t frequency) {
    if (frequency < 0) {
        // Disable compare match interrupt
        TIMSK1 &= ~(1 << OCIE1A);
        // Set buzzer pin low
        PORTB &= ~(1 << BUZZER_PIN);
        return;
    }

    uint16_t ocr_value = (F_CPU / (2 * frequency)) - 1;

    // Set the buzzer pin as output
    DDRB |= (1 << BUZZER_PIN);

    // Configure Timer1 (Clear Timer/Counter Control Registers)
    TCCR1A = 0;
    TCCR1B = 0;

    // Set CTC mode (Clear Timer on Compare Match)
    TCCR1B |= (1 << WGM12);

    // Set prescaler to 1 (no prescaling)
    TCCR1B |= (1 << CS10);

    // Set compare match register
    OCR1A = ocr_value;

    // Enable compare match interrupt
    TIMSK1 |= (1 << OCIE1A);
}

// Timer1 Compare Match A interrupt service routine
ISR(TIMER1_COMPA_vect) {
    // Toggle the buzzer pin
    PORTB ^= (1 << BUZZER_PIN);
}

int main(void) {
    // Enable global interrupts
    sei();

    // Set BUTTON_A_PIN and BUTTON_B_PIN as input with pull-up resistors
    DDRB &= ~(1 << PUSH_SWITCH_PIN);
    PORTB |= (1 << PUSH_SWITCH_PIN);

    // notes in the melody:
    uint16_t melody[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
    // flag if the melody is playing
    uint8_t is_melody_playing = 0;

    while (1) {

        // Guard clause for checking if button is not pressed
        if (PINB & (1 << PUSH_SWITCH_PIN)) {
            continue;
        }

        // Debounce: wait for a short period to confirm the button press
        _delay_ms(50);

        // Guard clause for checking if button is still pressed after debounce
        // aka continue while loop if user is holding down the button
        // do NOT do anything until they release the button
        if (!(PINB & (1 << PUSH_SWITCH_PIN)))
            continue;

        if (is_melody_playing) {
            uint8_t is_btn_pressed = 0; // track if button is pressed to stop playing the melody

            for (uint8_t note_idx = 0; note_idx < 8; note_idx++) {
                tone(melody[note_idx]); // play note
                // we loop so we can check for user input while we wait 300ms per note
                for (uint16_t i = 0; i < 300; i++) {
                    _delay_ms(1);
                    // flag that the button has been pressed and break the waiting loop
                    if (!(PINB & (1 << PUSH_SWITCH_PIN))) {
                        is_btn_pressed = 1;
                        break;
                    }
                }
                // stop playing the melody notes if button has been pressed
                if (is_btn_pressed) {
                    tone(-1);
                    is_melody_playing = 0;
                    break;
                }
            }
        } else {
            is_melody_playing = 1;
        }
    }

    return 0;
}

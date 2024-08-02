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

#define BUZZER_PIN PB0 // Physical Pin 14 -> Port Pin PB0

void tone(uint16_t frequency) {
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

    // notes in the melody:
    int melody[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};

    // play the melody
    for (int thisNote = 0; thisNote < 8; thisNote++) {
        tone(melody[thisNote]);
        _delay_ms(500);
    }

    return 0;
}

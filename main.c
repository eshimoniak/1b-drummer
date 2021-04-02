#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// Pins
// Port B
#define PIN_SPEAKER PB0
// PORT C
#define PIN_BUTTON PC0

// Miscellaneous constants
#define SAMPLE_RATE 22050U
#define F_TONE 440U

// Audio time
volatile uint8_t i = 0;
// True if audio playing
volatile uint8_t loud = 0;
// Next state of loud
volatile uint8_t nextLoud = 0;

void main() {
	// Set up Timer 0 for main loop interrupt
	// Set timer to CTC mode
	TCCR0A |= (1 << WGM01);
	// Start timer with prescaler of 8
	TCCR0B |= (1 << CS01);
	// Set compare value
	OCR0A = (F_CPU / 64) / SAMPLE_RATE;
	// Enable compare/match interrupt
	TIMSK0 |= (1 << OCIE0A);
	
	// Enable button interrupt
	// Enable interrupt group
	PCICR |= (1 << PCIE1);
	// Enable interrupt pin
	PCMSK1 |= (1 << PCINT8);

	// Set port data directions
	DDRB |= (1 << PIN_SPEAKER);
	DDRC &= ~(1 << PIN_BUTTON);

	// Enable button pull up
	PORTC |= (1 << PIN_BUTTON);

	// Enable global interrupts
	sei();
	
	while (1);
}

ISR (TIMER0_COMPA_vect) {
	if (loud) {
		if (i == 2UL * SAMPLE_RATE / F_TONE) {
			PORTB ^= (1 << PIN_SPEAKER);
			i = 0;
		} else {
			i++;
		}
	}
}

ISR (PCINT1_vect) {
	if (nextLoud) {
		loud = !loud;
	}
	nextLoud = !nextLoud;
}

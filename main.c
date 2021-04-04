#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "main.h"
#include "noise.h"


// Pins
// Port B
#define PIN_SPEAKER PB0
// PORT C
#define PIN_BUTTON_KICK PC0
#define PIN_BUTTON_SNARE PC1

static NoiseGenerator kick = {
	// Mask
	0x00 | BM_NG_SOUNDING,
	// Time
	0,
	// Last Swap
	0,
	// Timbre
	{
		// High pass
		FREQ_TO_SAMPLES(10) * 2,
		// Low Pass
		FREQ_TO_SAMPLES(400) * 2,
		// Swap chance
		16,
		// Duration
		MS_TO_SAMPLES(100)
	}
};

static NoiseGenerator snare = {
	// Mask
	0x00,
	// Time
	0,
	// Last Swap
	0,
	// Timbre
	{
		// High pass
		FREQ_TO_SAMPLES(400) * 2,
		// Low Pass
		FREQ_TO_SAMPLES(8000) * 2,
		// Swap chance
		2,
		// Duration
		MS_TO_SAMPLES(75)
	}
};

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
	// Enable interrupt pins
	PCMSK1 |= (1 << PCINT8) | (1 << PCINT9);

	// Set port data directions
	DDRB |= (1 << PIN_SPEAKER);
	DDRC &= ~(1 << PIN_BUTTON_KICK) | (1 << PIN_BUTTON_SNARE);

	// Enable button pull up
	PORTC |= (1 << PIN_BUTTON_KICK) | (1 << PIN_BUTTON_SNARE);

	// Enable global interrupts
	sei();
	
	while (1);
}

ISR (TIMER0_COMPA_vect) {
	stepNoise(&kick);
	stepNoise(&snare);
	if (getSample(&kick)) {
		PORTB ^= (1 << PIN_SPEAKER);
		clearSample(&kick);
	} else if (getSample(&snare)) {
		PORTB ^= (1 << PIN_SPEAKER);
		clearSample(&snare);
	}
}

ISR (PCINT1_vect) {
	if ((PINC & (1 << PIN_BUTTON_KICK)) == 0) {
		startNoise(&kick);
	}
	if ((PINC & (1 << PIN_BUTTON_SNARE)) == 0) {
		startNoise(&snare);
	}
}

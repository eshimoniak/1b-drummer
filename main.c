#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "main.h"
#include "noise.h"
#include "loop.h"

// Misc Constants
#define INPUT_SAMPLE_DIV 16

NoiseGenerator kick = {
	// Mask
	0x00,
	// Time
	0,
	// Last Swap
	0,
	// Timbre
	{
		// High Pass
		FREQ_TO_SAMPLES(10) / 2,
		// Low Pass
		FREQ_TO_SAMPLES(400) / 2,
		// Swap Chance
		{1, 9},
		// Duration
		MS_TO_SAMPLES(75)
	}
};

NoiseGenerator snare = {
	// Mask
	0x00,
	// Time
	0,
	// Last Swap
	0,
	// Timbre
	{
		// High Pass
		FREQ_TO_SAMPLES(200) / 2,
		// Low Pass
		FREQ_TO_SAMPLES(5000) / 2,
		// Swap Chance
		{9, 14},
		// Duration
		MS_TO_SAMPLES(50)
	}
};

NoiseGenerator hiHat = {
	// Mask
	0x00,
	// Time
	0,
	// Last Swap
	0,
	// Timbre
	{
		// High Pass
		FREQ_TO_SAMPLES(3000) / 2,
		// Low Pass
		FREQ_TO_SAMPLES(8000) / 2,
		// Swap Chance
		{27, 42},
		// Duration
		MS_TO_SAMPLES(25)
	}
};

/*
 * The number of the current sample
 * Used for clock dividing
 */
uint8_t iSample = 0;
// Last state of PINC
uint8_t lastPinC = 0x00;
// Last state of PIND
uint8_t lastPinD = 0x00;

void pollButtons();

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

	// Set port data directions
	DDRB |= (1 << PINB_SPEAKER);
	DDRC &= ~PINC_MASK_BUTTONS;
	DDRD |= (1 << PIND_LED_RECORD) | (1 << PIND_LED_PLAY);
	DDRD &= ~PIND_MASK_BUTTONS;

	// Enable button pull ups
	PORTC |= PINC_MASK_BUTTONS;
	PORTD |= PIND_MASK_BUTTONS;
	
	// Enable global interrupts
	sei();
	
	while (1);
}


ISR (TIMER0_COMPA_vect) {
	if (iSample == INPUT_SAMPLE_DIV - 1) {
		pollButtons();
		iSample = 0;
	} else {
		iSample++;
	}

	stepNoise(&kick);
	stepNoise(&snare);
	stepNoise(&hiHat);

	if (getSample(&kick)) {
		PORTB ^= (1 << PINB_SPEAKER);
		clearSample(&kick);
	} else if (getSample(&snare)) {
		PORTB ^= (1 << PINB_SPEAKER);
		clearSample(&snare);
	} else if (getSample(&hiHat)) {
		PORTB ^= (1 << PINB_SPEAKER);
		clearSample(&hiHat);
	}
}


void pollButtons() {
	// Port C
	uint8_t hits = 0x00;
	
	if ((PINC & (1 << PINC_BUTTON_KICK)) == 0 && (lastPinC & (1 << PINC_BUTTON_KICK))) {
		startNoise(&kick);
		hits |= (1 << PINC_BUTTON_KICK);
	}
	if ((PINC & (1 << PINC_BUTTON_SNARE)) == 0 && (lastPinC & (1 << PINC_BUTTON_SNARE))) {
		startNoise(&snare);
		hits |= (1 << PINC_BUTTON_SNARE);
	}
	if ((PINC & (1 << PINC_BUTTON_HI_HAT)) == 0 && (lastPinC & (1 << PINC_BUTTON_HI_HAT))) {
		startNoise(&hiHat);
		hits |= (1 << PINC_BUTTON_HI_HAT);
	}
	lastPinC = PINC & PINC_MASK_BUTTONS;
	stepLoop(hits);
	
	// Port D
	if ((PIND & (1 << PIND_BUTTON_PLAY)) == 0 && (lastPinD & (1 << PIND_BUTTON_PLAY))) {
		playLoop();
	} else if ((PIND & (1 << PIND_BUTTON_RECORD)) == 0 && (lastPinD & (1 << PIND_BUTTON_RECORD))) {
		recordLoop();
	}
	lastPinD = PIND & PIND_MASK_BUTTONS;
}


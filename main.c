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
#define PIN_BUTTON_HI_HAT PC2
#define PIN_MASK_BUTTONS ((1 << PIN_BUTTON_KICK) | (1 << PIN_BUTTON_SNARE) | (1 << PIN_BUTTON_HI_HAT))
// Misc Constants
#define INPUT_SAMPLE_DIV 16

static NoiseGenerator kick = {
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

static NoiseGenerator snare = {
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

static NoiseGenerator hiHat = {
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

uint8_t iSample = 0;
uint8_t buttonLastStateMask = 0x00;

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
	
	// Enable button interrupt
	// Enable interrupt group
//	PCICR |= (1 << PCIE1);
	// Enable interrupt pins
//	PCMSK1 |= (1 << PCINT8) | (1 << PCINT9) | (1 << PCINT10);

	// Set port data directions
	DDRB |= (1 << PIN_SPEAKER);
	DDRC &= ~(
		(1 << PIN_BUTTON_KICK)
		| (1 << PIN_BUTTON_SNARE)
		| (1 << PIN_BUTTON_HI_HAT)
	);

	// Enable button pull ups
	PORTC |= (
		(1 << PIN_BUTTON_KICK)
		| (1 << PIN_BUTTON_SNARE)
		| (1 << PIN_BUTTON_HI_HAT)
	);

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
		PORTB ^= (1 << PIN_SPEAKER);
		clearSample(&kick);
	} else if (getSample(&snare)) {
		PORTB ^= (1 << PIN_SPEAKER);
		clearSample(&snare);
	} else if (getSample(&hiHat)) {
		PORTB ^= (1 << PIN_SPEAKER);
		clearSample(&hiHat);
	}
}


void pollButtons() {
//ISR (PCINT1_vect) {
	if ((PINC & (1 << PIN_BUTTON_KICK)) == 0 && (buttonLastStateMask & (1 << PIN_BUTTON_KICK))) {
		startNoise(&kick);
	}
	if ((PINC & (1 << PIN_BUTTON_SNARE)) == 0 && (buttonLastStateMask & (1 << PIN_BUTTON_SNARE))) {
		startNoise(&snare);
	}
	if ((PINC & (1 << PIN_BUTTON_HI_HAT)) == 0 && (buttonLastStateMask & (1 << PIN_BUTTON_HI_HAT))) {
		startNoise(&hiHat);
	}
	buttonLastStateMask = PINC & PIN_MASK_BUTTONS;
}

/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdint.h>
#include <avr/io.h>
#include "main.h"
#include "loop.h"

#define LEN_MAX_LOOP 32

typedef enum _LoopState {
	OFF,
	PLAY,
	RECORD
} LoopState ;

typedef struct LoopHit {
	// Time since the last hit
	uint16_t dt;
	// Bit mask of the inputs
	uint8_t inputs;
} LoopHit;

// The current mode of operation of the looper
LoopState state = OFF;
// The number of samples elapsed since the last hit
uint32_t dt = 0;
// Index of hits in the loop
uint8_t i = 0;
// Information about which parts were triggered when
LoopHit loopHits[LEN_MAX_LOOP];
// The number of elements in the loop
uint8_t loopLength = 0;


void stepLoop(uint8_t hits) {
	if (state == PLAY && loopLength > 0) {
		if (dt >= loopHits[i].dt) {
			if (loopHits[i].inputs & (1 << PINC_BUTTON_KICK)) {
				startNoise(&kick);
			}
			if (loopHits[i].inputs & (1 << PINC_BUTTON_SNARE)) {
				startNoise(&snare);
			}
			if (loopHits[i].inputs & (1 << PINC_BUTTON_HI_HAT)) {
				startNoise(&hiHat);
			}
			
			i++;
			if (i == loopLength) {
				i = 0;
			}
			// Will be incremented to 0 soon
			dt = -1;
		}
		dt++;
	} else if (state == RECORD) {
		if (hits && i < LEN_MAX_LOOP - 1) {
			loopHits[i] = (LoopHit) {dt, hits};
			
			i++;
			if (i == LEN_MAX_LOOP - 1) {
				playLoop();
			}
			// Will be incremented to 0 soon
			dt = -1;
		}
		dt++;
	}
}


void playLoop() {
	if (state == OFF) {
		dt = 0;
		i = 0;
		state = PLAY;
		PORTD |= (1 << PIND_LED_PLAY);
		PORTD &= ~(1 << PIND_LED_RECORD);
	} else if (state == PLAY) {
		stopLoop();
	} else if (state == RECORD) {
		loopHits[i] = (LoopHit) {dt, 0x00};
		loopLength = i + 1;
		dt = 0;
		i = 0;
		state = PLAY;
		PORTD |= (1 << PIND_LED_PLAY);
		PORTD &= ~(1 << PIND_LED_RECORD);
	}
}


void recordLoop() {
	dt = 0;
	i = 0;
	state = RECORD;
	PORTD |= (1 << PIND_LED_RECORD);
	PORTD &= ~(1 << PIND_LED_PLAY);
}


void stopLoop() {
	dt = 0;
	i = 0;
	state = OFF;
	PORTD &= ~((1 << PIND_LED_RECORD) | (1 << PIND_LED_PLAY));
}


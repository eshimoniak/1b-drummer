#include <avr/io.h>

#ifndef MAIN_H
#define MAIN_H

#include "noise.h"

// Pins
// Port B
#define PINB_SPEAKER PB0
// Port C
#define PINC_BUTTON_KICK PC0
#define PINC_BUTTON_SNARE PC1
#define PINC_BUTTON_HI_HAT PC2
#define PINC_MASK_BUTTONS ((1 << PINC_BUTTON_KICK) | (1 << PINC_BUTTON_SNARE) | (1 << PINC_BUTTON_HI_HAT))
// Port D
#define PIND_BUTTON_RECORD PD0
#define PIND_BUTTON_PLAY PD1
#define PIND_MASK_BUTTONS ((1 << PIND_BUTTON_RECORD) | (1 << PIND_BUTTON_PLAY))
#define PIND_LED_RECORD PD6
#define PIND_LED_PLAY PD7
// Misc Constants
#define SAMPLE_RATE 22050U

extern NoiseGenerator kick, snare, hiHat;

#endif


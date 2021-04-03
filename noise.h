#include <stdint.h>
#include "main.h"

#ifndef NOISE_H
#define NOISE_H

#define BM_NG_SOUNDING (1 << 0)
#define BM_NG_QUEUE_SAMPLE (1 << 1)
#define FREQ_TO_SAMPLES(freq) (SAMPLE_RATE / freq)
#define MS_TO_SAMPLES(ms) ((((uint32_t) SAMPLE_RATE) * ms) / 1000)

/* 
 * Stores information necessary to represent
 * a one-shot, band-limited, decaying noise
 *
 * Periods are represented as halves to allow for
 * XOR to swap audio at the halfway point
 */
typedef struct _NoiseTimbre {
	// One half period of the high-pass filter in samples
	uint16_t highPass;
	// One half the period of the low-pass filter in samples
	uint16_t lowPass;
	// Duration in samples of the noise
	uint16_t duration;
} NoiseTimbre;

// Stores information necessary to perform a noise
typedef struct _NoiseGenerator {
	/*
	 * Bit 0: 1 iff the noise is producing an audio output
	 * Bit 1: 1 iff the noise has a sample queued for output
	 */
	uint8_t mask;
	// Time since the start of the noise
	uint16_t t;
	/*
	 * Time elapsed since the last rising or falling edge
	 * of the output audio signal
	 */
	uint8_t dtLastSwap;
	// The sonic characteristics of the noise
	NoiseTimbre timbre;
} NoiseGenerator;

// Start playing a noise
void startNoise(NoiseGenerator *noiseGen);
// Incerment the time of the noise by one sample
void stepNoise(NoiseGenerator *noiseGen);
// Check if an audio edge is queued
uint8_t getSample(NoiseGenerator *noiseGen);
// Clear the sample queued flag
void clearSample(NoiseGenerator *noiseGen);

#endif

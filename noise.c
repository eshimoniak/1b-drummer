#include <stdint.h>
#include <stdlib.h>
#include "noise.h"


void startNoise(NoiseGenerator *noiseGen) {
	noiseGen->mask |= BM_NG_SOUNDING;
	noiseGen->t = 0;
	noiseGen->dtLastSwap = 0;
}


void stepNoise(NoiseGenerator *noiseGen) {
	if (noiseGen->mask & BM_NG_SOUNDING) {
		noiseGen->t++;
		if (noiseGen->t > noiseGen->timbre.duration) {
			noiseGen->mask &= ~BM_NG_SOUNDING;
		} else {
			if ((
				(
				 	noiseGen->dtLastSwap > noiseGen->timbre.lowPass
				) && (
					rand() % noiseGen->timbre.swapChance == 0
				)
			) || (
				noiseGen->dtLastSwap > noiseGen->timbre.highPass
			)) {
				noiseGen->mask |= BM_NG_QUEUE_SAMPLE;
				noiseGen->dtLastSwap = 0;
			} else {
				noiseGen->dtLastSwap++;
			}
		}
	}
}


uint8_t getSample(NoiseGenerator *noiseGen) {
	return noiseGen->mask & BM_NG_QUEUE_SAMPLE;
}


void clearSample(NoiseGenerator *noiseGen) {
	noiseGen->mask &= ~BM_NG_QUEUE_SAMPLE;
}

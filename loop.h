#include <stdint.h>

#ifndef LOOP_H
#define LOOP_H

// Increment the position in the loop by one sample
void stepLoop(uint8_t hits);
// Begin playback of the loop
void playLoop();
// Begin recording of the loop
void recordLoop();
// Stop playback or recording of the loop
void stopLoop();

#endif


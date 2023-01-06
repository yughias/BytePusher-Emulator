#ifndef _BYTEPUSHER_H_
#define _BYTEPUSHER_H_

#include <SDL_MAINLOOP.h>
#include "buzzer.h"

#define HERTZ_PER_FRAME 65536
#define MEMORY_SIZE     0x1000008
#define BYTEPUSHER_W    256
#define BYTEPUSHER_H    256

uint8_t memory[MEMORY_SIZE];

void initBytePusher();
void loadROM(const char*);
void emulate();

void setBytePusherKey(keyboard);
void unsetBytePusherKey(keyboard);

#endif
#ifndef _BUZZER_H_
#define _BUZZER_H_

#include <SDL_MAINLOOP.h>

void initBuzzer();
void closeBuzzer();
void playSoundData(uint8_t*);

#endif
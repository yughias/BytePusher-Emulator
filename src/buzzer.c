#include "buzzer.h"

SDL_AudioDeviceID audio_device;
SDL_AudioSpec audio_spec;

void initBuzzer(){
    SDL_zero(audio_spec);
    audio_spec.freq = 15360;
    audio_spec.format = AUDIO_S8;
    audio_spec.channels = 1;
    audio_spec.samples = 1024;
    audio_spec.callback = NULL;

    audio_device = SDL_OpenAudioDevice(
        NULL, 0, &audio_spec, NULL, 0);

    SDL_PauseAudioDevice(audio_device, 0);
}

void closeBuzzer(){
    SDL_CloseAudioDevice(audio_device);
}

void playSoundData(uint8_t* sample){
    SDL_QueueAudio(audio_device, sample, 256);
}
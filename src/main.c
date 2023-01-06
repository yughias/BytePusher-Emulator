#include "bytepusher.h"
#include "tinyfiledialogs.h"

void render();
void sound();
const char* selectFile();

void setup(){
    size(BYTEPUSHER_W, BYTEPUSHER_H);
    frameRate(60);
    setTitle("BytePusher");
    
    initBuzzer();
    initBytePusher();
    const char* filename = selectFile();
    if(filename == NULL)
        exit(1);
    loadROM(filename);
    onKeyPressed = setBytePusherKey;
    onKeyReleased = unsetBytePusherKey;
    onExit = closeBuzzer;
}

void loop(){
    emulate();
    render();
    sound();

    if(isKeyReleased && keyReleased == ' '){
        const char* filename = selectFile();
        if(filename != NULL){
            initBytePusher();
            loadROM(filename);
        }
    }
}

void render(){
    uint8_t* vram = memory + (memory[5]<<16);
    for(int y = 0; y < BYTEPUSHER_H; y++){
        for(int x = 0; x < BYTEPUSHER_W; x++){
            uint8_t col = vram[x + y*BYTEPUSHER_W];
            uint8_t blue = col % 6;
            uint8_t green = (col / 6) % 6;
            uint8_t red = (col / 36) % 6;
            pixels[x+y*BYTEPUSHER_W] = color(red*255/6, green*255/6, blue*255/6);
        }
    }
}

void sound(){
    uint8_t* audio_ram = memory + (memory[6]<<16 | memory[7]<<8);
    playSoundData(audio_ram);
}

const char* selectFile(){
    return tinyfd_openFileDialog("select ROM", "ROMs/", 0, NULL, NULL, 0);
}
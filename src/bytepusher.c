#include "bytepusher.h"

uint8_t memory[MEMORY_SIZE];

void initBytePusher(){
    memset(memory, 0, MEMORY_SIZE);
}

void loadROM(const char* filename){
    FILE* fptr = fopen(filename, "rb");
    fseek(fptr, 0, SEEK_END);
    unsigned int filesize = ftell(fptr);
    rewind(fptr);
    fread(memory, 1, filesize, fptr);
    fclose(fptr);
}

void emulate(){
    uint8_t* pc =  memory + (memory[2]<<16 | memory[3]<<8 | memory[4]);
    for(int i = 0; i < HERTZ_PER_FRAME; i++){
        memory[pc[3]<<16 | pc[4]<<8 | pc[5]] = memory[pc[0]<<16 | pc[1]<<8 | pc[2]];
        pc = memory + (pc[6]<<16 | pc[7]<<8 | pc[8]);
    }
}


void setBytePusherKey(keyboard k){
    if(k == '1')
        memory[1] |= 1<<1;
    if(k == '2')
        memory[1] |= 1<<2;
    if(k == '3')
        memory[1] |= 1<<3;
    if(k == '4')
        memory[0] |= 1<<4;
    if(k == 'q')
        memory[1] |= 1<<4;
    if(k == 'w')
        memory[1] |= 1<<5;
    if(k == 'e')
        memory[1] |= 1<<6;
    if(k == 'r')
        memory[0] |= 1<<5;
    if(k == 'a')
        memory[1] |= 1<<7;
    if(k == 's')
        memory[0] |= 1<<0;
    if(k == 'd')
        memory[0] |= 1<<1;
    if(k == 'f')
        memory[0] |= 1<<6;
    if(k == 'z')
        memory[0] |= 1<<2;
    if(k == 'x')
        memory[1] |= 1<<0;
    if(k == 'c')
        memory[0] |= 1<<3;
    if(k == 'v')
        memory[0] |= 1<<7;
}

void unsetBytePusherKey(keyboard k){
    if(k == '1')
        memory[1] &= ~(1<<1);
    if(k == '2')
        memory[1] &= ~(1<<2);
    if(k == '3')
        memory[1] &= ~(1<<3);
    if(k == '4')
        memory[0] &= ~(1<<4);
    if(k == 'q')
        memory[1] &= ~(1<<4);
    if(k == 'w')
        memory[1] &= ~(1<<5);
    if(k == 'e')
        memory[1] &= ~(1<<6);
    if(k == 'r')
        memory[0] &= ~(1<<5);
    if(k == 'a')
        memory[1] &= ~(1<<7);
    if(k == 's')
        memory[0] &= ~(1<<0);
    if(k == 'd')
        memory[0] &= ~(1<<1);
    if(k == 'f')
        memory[0] &= ~(1<<6);
    if(k == 'z')
        memory[0] &= ~(1<<2);
    if(k == 'x')
        memory[1] &= ~(1<<0);
    if(k == 'c')
        memory[0] &= ~(1<<3);
    if(k == 'v')
        memory[0] &= ~(1<<7);
}
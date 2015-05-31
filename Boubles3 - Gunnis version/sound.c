#include <stdio.h>
#include "main.h"
#include "sound.h"

// Kod för ljudimplementering skriven med hjälp av Lazy Foo Tutorials
// och SDLWIKI för SDL_Mixer


void soundJump(){
    Mix_Chunk *sound1 = NULL;
    int channel;

    if(Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0) {
    printf("ERROR: %s\n", Mix_GetError());
    exit(1);
    }

    sound1 = Mix_LoadWAV("sound/jumping.wav");
    if(sound1 == NULL) {
        printf("ERROR: %s\n", Mix_GetError());
    }

    channel = Mix_PlayChannel(-1, sound1, 0);
    if(channel == -1) {
        printf("ERROR: %s\n", Mix_GetError());
    }
    while(Mix_Playing(channel) != 0);
}

void soundShoot(){

    Mix_Chunk *sound2 = NULL;
    int channel;

    if(Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0) {
    printf("ERROR: %s\n", Mix_GetError());
    exit(1);
    }

    sound2 = Mix_LoadWAV("sound/shoot.wav");
    if(sound2 == NULL) {
        printf("ERROR: %s\n", Mix_GetError());
    }

    channel = Mix_PlayChannel(-1, sound2, 0);
    if(channel == -1) {
        printf("ERROR: %s\n", Mix_GetError());
    }
    while(Mix_Playing(channel) != 0);
}

void backgroundMusic(){
Mix_Music *sound3 = NULL;
int channel;

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != 0) {
    printf("ERROR: %s\n", Mix_GetError());
    exit(1);
    }
    sound3 = Mix_LoadMUS("sound/background.wav");
    if(sound3 == NULL) {
        printf("ERROR: %s\n", Mix_GetError());
    }

    channel = Mix_PlayChannel(-1, sound3, 0);
    if(channel == -1) {
        printf("ERROR: %s\n", Mix_GetError());
    }
    if( Mix_PlayingMusic() == 0 )
    {
        if( Mix_PlayMusic( sound3, -1 ) == -1 )
        {
            return 1;
        }
    }
}

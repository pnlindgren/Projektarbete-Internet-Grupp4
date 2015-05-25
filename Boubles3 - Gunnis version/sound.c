
#include <stdio.h>
#include "main.h"


void soundJump(){
    Mix_Chunk *sound = NULL;		//Pointer to our sound, in memory
    int channel;				//Channel on which our sound is played

    int audio_rate = 22050;			//Frequency of audio playback
    Uint16 audio_format = AUDIO_S16SYS; 	//Format of the audio we're playing
    int audio_channels = 2;			//2 channels = stereo
    int audio_buffers = 4096;		//Size of the audio buffers in memory

	//Initialize BOTH SDL video and SDL audio


	//Initialize SDL_mixer with our chosen audio settings
    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
    printf("Unable to initialize audio: %s\n", Mix_GetError());
    exit(1);
    }

	//Load our WAV file from disk
    sound = Mix_LoadWAV("jumping.wav");
    if(sound == NULL) {
        printf("Unable to load WAV file: %s\n", Mix_GetError());
    }

    channel = Mix_PlayChannel(-1, sound, 0);
    if(channel == -1) {
        printf("Unable to play WAV file: %s\n", Mix_GetError());
    }
    while(Mix_Playing(channel) != 0);
}

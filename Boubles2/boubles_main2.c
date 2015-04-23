#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//#include <pthread.h>

#include "main.h"
#include "position.h"

bool init();
bool loadMedia();
void close1();

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Surface* loadSurface(char path[100]);

SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gBackground = NULL;

SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

SDL_Surface* gCurrentSurface = NULL;

int main(int argc, char * argv[])
{

    if(initBuild())
    {
        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

        SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);

        keyInput();
    }

    close1();

    return 0;
}

void close1()
{
    SDL_Delay(1000);    // F�r att av knappen ska hinna visa vad den g�r

    SDL_FreeSurface(gBackground);

    gBackground = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

SDL_Surface* loadSurface(char path[100])
{
    SDL_Surface* loadedSurface = IMG_Load(path);

    if( loadedSurface == NULL )
    {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
    }

    return loadedSurface;
}

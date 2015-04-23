#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//#include <pthread.h>

#include "main.h"
#include "initFunctions.h"
#include "close.h"
#include "keyInput.h"
#include "position.h"

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

SDL_Surface* loadSurface(char path[100])
{
    SDL_Surface* loadedSurface = IMG_Load(path);

    if( loadedSurface == NULL )
    {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
    }

    return loadedSurface;
}

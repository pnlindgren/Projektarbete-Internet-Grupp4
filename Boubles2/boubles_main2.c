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

    if(!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if(!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

            SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);

            keyInput();
        }
    }

    close1();

    return 0;
}

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;

    gBackground = SDL_LoadBMP("NewBackground.bmp");

    if (gBackground == NULL)
    {
        printf("Unable to load image %s! SDL_Error: %s\n", "Background.bmp", SDL_GetError());
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("ghostR.png");
    if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("ghostL.png");
    if(gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
    {
        printf( "Failed to load LEFT image!\n" );
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("ghostR.png");
    if(gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
    {
        printf( "Failed to load RIGHT image!\n" );
        success = false;
    }


    return success;
}

void close1()
{
    SDL_Delay(1000);    // För att av knappen ska hinna visa vad den gör

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

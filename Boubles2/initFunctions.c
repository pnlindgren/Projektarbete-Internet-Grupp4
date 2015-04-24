#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "initFunctions.h"

bool initBuild()
{
    bool buildSuccess = true;

    if(!init())
    {
        printf("Failed to initialize!\n");
        buildSuccess = false;
    }
    else
    {
        if(!loadMedia())
        {
            printf("Failed to load media!\n");
            buildSuccess = false;
        }
        else
        {
            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

            SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
        }
    }

    return buildSuccess;
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

    gBackground = SDL_LoadBMP(BACKGROUND);

    if (gBackground == NULL)
    {
        printf("Unable to load image %s! SDL_Error: %s\n", BACKGROUND, SDL_GetError());
        success = false;
    }

    success = loadImage(GHOST_RIGHT, KEY_PRESS_SURFACE_DEFAULT);
    success = loadImage(GHOST_LEFT, KEY_PRESS_SURFACE_LEFT);
    success = loadImage(GHOST_RIGHT, KEY_PRESS_SURFACE_RIGHT);


    return success;
}

bool loadImage(char path[100], int pressed_key)
{
    bool success = true;

    gKeyPressSurfaces[pressed_key] = loadSurface(path);
    if(gKeyPressSurfaces[pressed_key] == NULL)
    {
        printf( "Failed to load %s image!\n", path);
        success = false;
    }

    return success;
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

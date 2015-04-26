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
            character_rect.x = 500;
            character_rect.y = 97;
            character_rect.w = 50;
            character_rect.h = 50;

            background_rect.x = 0;
            background_rect.y = 0;
            background_rect.w = 640;
            background_rect.h = 480;

            ghost_rect.x = 30;
            ghost_rect.y = 97;
            ghost_rect.w = 50;
            ghost_rect.h = 50;

            SDL_RenderClear(gRenderer);
            SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[3],&character_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderPresent(gRenderer);
        }
    }

    return buildSuccess;
}
// tagen från lazy foo
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
        // här skapar vi spelfönstret med odefinerad position (X,Y) och inte minimerat
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

            if(gRenderer == NULL)
            {
                printf("Fungerar ej\n");
                success = false;
            }
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;

    // sätter bakgrundssurfacen till bakgrundsbilden
    gBackground = SDL_LoadBMP(BACKGROUND);
    mBackground = SDL_CreateTextureFromSurface(gRenderer, gBackground);

    if (gBackground == NULL)
    {
        printf("Unable to load image %s! SDL_Error: %s\n", BACKGROUND, SDL_GetError());
        success = false;
    }

    SDL_Surface* gSpacemanSurface = IMG_Load(BLUE_CROCODILE);
    mBlueCrocodile = SDL_CreateTextureFromSurface(gRenderer, gSpacemanSurface);

    SDL_Surface* gGhost = IMG_Load(GHOST);
    mGhost = SDL_CreateTextureFromSurface(gRenderer, gGhost);

    gSpriteClips[ 0 ].x = 0;
    gSpriteClips[ 0 ].y = 0;
    gSpriteClips[ 0 ].w = 50;
    gSpriteClips[ 0 ].h = 50;

    gSpriteClips[ 1 ].x = 50;
    gSpriteClips[ 1 ].y = 0;
    gSpriteClips[ 1 ].w = 50;
    gSpriteClips[ 1 ].h = 50;

    gSpriteClips[ 2 ].x = 100;
    gSpriteClips[ 2 ].y = 0;
    gSpriteClips[ 2 ].w = 50;
    gSpriteClips[ 2 ].h = 50;

    gSpriteClips[ 3 ].x = 150;
    gSpriteClips[ 3 ].y = 0;
    gSpriteClips[ 3 ].w = 50;
    gSpriteClips[ 3 ].h = 50;

    gSpriteClips[ 4 ].x = 200;
    gSpriteClips[ 4 ].y = 0;
    gSpriteClips[ 4 ].w = 50;
    gSpriteClips[ 4 ].h = 50;

    gSpriteClips[ 5 ].x = 250;
    gSpriteClips[ 5 ].y = 0;
    gSpriteClips[ 5 ].w = 50;
    gSpriteClips[ 5 ].h = 50;

    // Background sprite
    gSpriteClips[ 6 ].x = 0;
    gSpriteClips[ 6 ].y = 0;
    gSpriteClips[ 6 ].w = 640;
    gSpriteClips[ 6 ].h = 480;

    // Ghost sprite
    gSpriteClips[ 7 ].x = 0;
    gSpriteClips[ 7 ].y = 0;
    gSpriteClips[ 7 ].w = 50;
    gSpriteClips[ 7 ].h = 50;

    gSpriteClips[ 8 ].x = 50;
    gSpriteClips[ 8 ].y = 0;
    gSpriteClips[ 8 ].w = 50;
    gSpriteClips[ 8 ].h = 50;

    gSpriteClips[ 9 ].x = 100;
    gSpriteClips[ 9 ].y = 0;
    gSpriteClips[ 9 ].w = 50;
    gSpriteClips[ 9 ].h = 50;

    gSpriteClips[ 10 ].x = 150;
    gSpriteClips[ 10 ].y = 0;
    gSpriteClips[ 10 ].w = 50;
    gSpriteClips[ 10 ].h = 50;

    /*


    // laddar bilder associerade med knapptryckningar
    //if(success == true)
    {
        success = loadKeyImage(CROCODILE_RIGHT, KEY_PRESS_SURFACE_DEFAULT);
    }
    //else if(success == true)
    {
        success = loadKeyImage(CROCODILE_LEFT, KEY_PRESS_SURFACE_LEFT);
    }
    //else if(success == true)
    {
        success = loadKeyImage(CROCODILE_RIGHT, KEY_PRESS_SURFACE_RIGHT);
    }
    else if(success == true)
    {
        success = loadKeyImage(GHOST_RIGHT, KEY_PRESS_SURFACE_UP);
    }*/

    return success;
}

// funktion för att ladda bilder associerade till knapptryckningar
bool loadKeyImage(char path[100], int pressed_key)
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

// funktion baserad på lazy foos sdl tutorial nr 4
// Syftet är att ladda en bild till en surface och sedan returnera surfacen
SDL_Surface* loadSurface(char path[100])
{
    SDL_Surface* loadedSurface = IMG_Load(path);

    if( loadedSurface == NULL )
    {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
    }

    return loadedSurface;
}

#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "initFunctions.h"

bool initBuild(int positionStart)
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
            if(positionStart == 1)
            {
                gameRectangels.character_rect.x = 550;
                gameRectangels.character_rect.y = 97;
                gameRectangels.character_rect.w = 50;
                gameRectangels.character_rect.h = 50;

                gameRectangels.rival_rect.x = 40;
                gameRectangels.rival_rect.y = 97;
                gameRectangels.rival_rect.w = 50;
                gameRectangels.rival_rect.h = 50;
            }
            else if(positionStart == 0)
            {
                gameRectangels.character_rect.x = 40;
                gameRectangels.character_rect.y = 97;
                gameRectangels.character_rect.w = 50;
                gameRectangels.character_rect.h = 50;

                gameRectangels.rival_rect.x = 550;
                gameRectangels.rival_rect.y = 97;
                gameRectangels.rival_rect.w = 50;
                gameRectangels.rival_rect.h = 50;
            }

            gameRectangels.background_rect.x = 0;
            gameRectangels.background_rect.y = 0;
            gameRectangels.background_rect.w = 640;
            gameRectangels.background_rect.h = 480;

            gameRectangels.left_wall.x = 0;
            gameRectangels.left_wall.y = 0;
            gameRectangels.left_wall.w = 16;
            gameRectangels.left_wall.h = 480;

            gameRectangels.right_wall.x = 622;
            gameRectangels.right_wall.y = 0;
            gameRectangels.right_wall.w = 16;
            gameRectangels.right_wall.h = 480;

            gameRectangels.game_over.x = 200;
            gameRectangels.game_over.y = 200;
            gameRectangels.game_over.w = 191;
            gameRectangels.game_over.h = 63;

            gameRectangels.bubble_rect.x = 1000;
            gameRectangels.bubble_rect.y = 1000;
            gameRectangels.bubble_rect.w = 40;
            gameRectangels.bubble_rect.h = 40;

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
        gWindow = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gameTextures.renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

            if(gameTextures.renderer == NULL)
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
    SDL_Surface* gBackground = SDL_LoadBMP(BACKGROUND);
    gameTextures.background = SDL_CreateTextureFromSurface(gameTextures.renderer, gBackground);

    if (gBackground == NULL)
    {
        printf("Unable to load image %s! SDL_Error: %s\n", BACKGROUND, SDL_GetError());
        success = false;
    }

    SDL_Surface* gBlueCrocodile = IMG_Load(BLUE_CROCODILE);
    gameTextures.blueCrocodile = SDL_CreateTextureFromSurface(gameTextures.renderer, gBlueCrocodile);

    SDL_Surface* gGhost = IMG_Load(GHOST);
    gameTextures.ghost = SDL_CreateTextureFromSurface(gameTextures.renderer, gGhost);

    SDL_Surface* gBubble = IMG_Load(BUBBLE);
    gameTextures.bubble = SDL_CreateTextureFromSurface(gameTextures.renderer, gBubble);

    SDL_Surface* gGameOver = IMG_Load(GAMEOVER);
    gameTextures.gameOver = SDL_CreateTextureFromSurface(gameTextures.renderer, gGameOver);

    // Crocodile
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

    // Right wall
    gSpriteClips[ 9 ].x = 0;
    gSpriteClips[ 9 ].y = 0;
    gSpriteClips[ 9 ].w = 16;
    gSpriteClips[ 9 ].h = 480;

    // Bubbla
    gSpriteClips[ 10 ].x = 0;
    gSpriteClips[ 10 ].y = 0;
    gSpriteClips[ 10 ].w = 40;
    gSpriteClips[ 10 ].h = 40;

    // Game Over
    gSpriteClips[ 11 ].x = 0;
    gSpriteClips[ 11 ].y = 0;
    gSpriteClips[ 11 ].w = 191;
    gSpriteClips[ 11 ].h = 63;

    return success;
}

// funktion för att ladda bilder associerade till knapptryckningar
bool loadKeyImage(char path[100], int pressed_key)
{
    bool success = true;

    //gKeyPressSurfaces[pressed_key] = loadSurface(path);
    //if(gKeyPressSurfaces[pressed_key] == NULL)
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

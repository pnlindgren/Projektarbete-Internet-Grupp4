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
                gameVariables.character_rect.x = 550;
                gameVariables.character_rect.y = 97;
                gameVariables.character_rect.w = 50;
                gameVariables.character_rect.h = 50;

                gameVariables.rival_rect.w = 50;
                gameVariables.rival_rect.h = 50;
            }
            else if(positionStart == 0)
            {
                gameVariables.character_rect.x = 40;
                gameVariables.character_rect.y = 97;
                gameVariables.character_rect.w = 50;
                gameVariables.character_rect.h = 50;

                gameVariables.character_flip =SDL_FLIP_HORIZONTAL;

                gameVariables.rival_rect.w = 50;
                gameVariables.rival_rect.h = 50;
            }

            localRects.background_rect.x = 0;
            localRects.background_rect.y = 0;
            localRects.background_rect.w = 640;
            localRects.background_rect.h = 480;

            localRects.left_wall.x = 0;
            localRects.left_wall.y = 0;
            localRects.left_wall.w = 16;
            localRects.left_wall.h = 480;

            localRects.right_wall.x = 622;
            localRects.right_wall.y = 0;
            localRects.right_wall.w = 16;
            localRects.right_wall.h = 480;

            localRects.game_over.x = 200;
            localRects.game_over.y = 200;
            localRects.game_over.w = 191;
            localRects.game_over.h = 63;

            gameVariables.bubble_rect.x = 1000;
            gameVariables.bubble_rect.y = 1000;
            gameVariables.bubble_rect.w = 40;
            gameVariables.bubble_rect.h = 40;

            gameVariables.enemy_bubble.x = 1000;
            gameVariables.enemy_bubble.y = 1000;
            gameVariables.enemy_bubble.w = 40;
            gameVariables.enemy_bubble.h = 40;

            gameVariables.ghost_rect1.x = 300;
            gameVariables.ghost_rect1.y = 97;
            gameVariables.ghost_rect1.w = 50;
            gameVariables.ghost_rect1.h = 50;

            gameVariables.ghost_rect2.x = 50;
            gameVariables.ghost_rect2.y = 195;
            gameVariables.ghost_rect2.w = 50;
            gameVariables.ghost_rect2.h = 50;

            gameVariables.ghost_rect3.x = 500;
            gameVariables.ghost_rect3.y = 195;
            gameVariables.ghost_rect3.w = 50;
            gameVariables.ghost_rect3.h = 50;

            gameVariables.ghost_rect4.x = 300;
            gameVariables.ghost_rect4.y = 297;
            gameVariables.ghost_rect4.w = 50;
            gameVariables.ghost_rect4.h = 50;

            gameVariables.ghost_rect5.x = 400;
            gameVariables.ghost_rect5.y = 415;
            gameVariables.ghost_rect5.w = 50;
            gameVariables.ghost_rect5.h = 50;
        }
    }

    return buildSuccess;
}
// funktionen är baserad på lazy foo
bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // här skapar vi spelfönstret med odefinerad position (X,Y) och inte minimerat
        gameWindow = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gameWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gameTextures.renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);

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
    SDL_Surface* backgroundSurface = SDL_LoadBMP(BACKGROUND);
    gameTextures.background = SDL_CreateTextureFromSurface(gameTextures.renderer, backgroundSurface);

    SDL_Surface* blueCroc = IMG_Load(BLUE_CROCODILE);
    gameTextures.blueCrocodile = SDL_CreateTextureFromSurface(gameTextures.renderer, blueCroc);

    SDL_Surface* pinkCroc = IMG_Load(PINK_CROCODILE);
    gameTextures.pinkCrocodile = SDL_CreateTextureFromSurface(gameTextures.renderer, pinkCroc);

    SDL_Surface* ghostSurface = IMG_Load(GHOST);
    gameTextures.ghost = SDL_CreateTextureFromSurface(gameTextures.renderer, ghostSurface);

    SDL_Surface* bubbleSurface = IMG_Load(BUBBLE);
    gameTextures.bubble = SDL_CreateTextureFromSurface(gameTextures.renderer, bubbleSurface);

    SDL_Surface* gameOverSurface = IMG_Load(GAMEOVER);
    gameTextures.gameOver = SDL_CreateTextureFromSurface(gameTextures.renderer, gameOverSurface);

    // Crocodile
    spriteClips[ 0 ].x = 0;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = 50;
    spriteClips[ 0 ].h = 50;

    spriteClips[ 1 ].x = 50;
    spriteClips[ 1 ].y = 0;
    spriteClips[ 1 ].w = 50;
    spriteClips[ 1 ].h = 50;

    spriteClips[ 2 ].x = 100;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = 50;
    spriteClips[ 2 ].h = 50;

    spriteClips[ 3 ].x = 150;
    spriteClips[ 3 ].y = 0;
    spriteClips[ 3 ].w = 50;
    spriteClips[ 3 ].h = 50;

    //spriteClips[ 4 ].x = 200;     /* Används inte längre - kan anpassas för bilder med 6 frames */
    //spriteClips[ 4 ].y = 0;
    //spriteClips[ 4 ].w = 50;
    //spriteClips[ 4 ].h = 50;

    //spriteClips[ 5 ].x = 250;
    //spriteClips[ 5 ].y = 0;
    //spriteClips[ 5 ].w = 50;
    //spriteClips[ 5 ].h = 50;

    // Background sprite
    spriteClips[ 6 ].x = 0;
    spriteClips[ 6 ].y = 0;
    spriteClips[ 6 ].w = 640;
    spriteClips[ 6 ].h = 480;

    // Ghost sprite
    spriteClips[ 7 ].x = 0;
    spriteClips[ 7 ].y = 0;
    spriteClips[ 7 ].w = 50;
    spriteClips[ 7 ].h = 50;

    spriteClips[ 8 ].x = 50;
    spriteClips[ 8 ].y = 0;
    spriteClips[ 8 ].w = 50;
    spriteClips[ 8 ].h = 50;

    // Right wall
    spriteClips[ 9 ].x = 0;
    spriteClips[ 9 ].y = 0;
    spriteClips[ 9 ].w = 16;
    spriteClips[ 9 ].h = 480;

    // Bubbla
    spriteClips[ 10 ].x = 0;
    spriteClips[ 10 ].y = 0;
    spriteClips[ 10 ].w = 40;
    spriteClips[ 10 ].h = 40;

    // Game Over
    spriteClips[ 11 ].x = 0;
    spriteClips[ 11 ].y = 0;
    spriteClips[ 11 ].w = 191;
    spriteClips[ 11 ].h = 63;

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

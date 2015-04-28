#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "initFunctions.h"
#include "close.h"
#include "keyInput.h"
#include "position.h"
#include "keyInput2.h"
#include "screenUpdater.h"
#include "wallDetector.h"
#include "dropFunction.h"

SDL_Surface* loadSurface(char path[100]);       // Behövs
SDL_Window*  gWindow = NULL;                    // Behövs
SDL_Surface* gScreenSurface = NULL;             // Behövs
SDL_Surface* gBackground = NULL;                // Behövs
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gCurrentSurface = NULL;

SDL_Surface* gEnemySurface = NULL;

// Nytt *******************************************************

SDL_Renderer* gRenderer = NULL;
SDL_Texture* mBlueCrocodile = NULL;
SDL_Texture* mBackground = NULL;
SDL_Texture* mGhost = NULL;
SDL_Texture* mWall = NULL;

SDL_Rect gSpriteClips[13];

SDL_Rect character_rect;
SDL_Rect background_rect;
SDL_Rect ghost_rect;
SDL_Rect wall_rect;
SDL_Rect left_wall;
SDL_Rect right_wall;

SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

int frame = 3;  // vilken frame blåa krokodilen börjar på
bool characterCollision = false;

// Nytt *******************************************************

int main(int argc, char * argv[])
{
    SDL_Thread *enemy;
    SDL_Thread *updateScreen;
    SDL_Thread *dropGravitation;

    if(initBuild()) // Om init och loadmedia fungerar körs programmet
    {
        updateScreen = SDL_CreateThread(screenUpdateFunction, "updateThread", (void *)NULL);

        dropGravitation = SDL_CreateThread(dropFunction, "dropThread", (void*)NULL);

        enemy = SDL_CreateThread(nextMove, "enemyThread", (void *)NULL);

        keyInput2(); // Funktion för att ta hand om knapptryckningar
    }

    close1();       // funktion för att stänga av programmet med röda krysset

    return 0;
}

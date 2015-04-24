#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "initFunctions.h"
#include "close.h"
#include "keyInput.h"
#include "position.h"
#include "keyInput2.h"

SDL_Surface* loadSurface(char path[100]);       // Behövs
SDL_Window*  gWindow = NULL;                    // Behövs
SDL_Surface* gScreenSurface = NULL;             // Behövs för att bakgrundsbilden genereras genom processorn
SDL_Surface* gBackground = NULL;                // Behövs
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gCurrentSurface = NULL;

SDL_Surface* gEnemySurface = NULL;

// Nytt *******************************************************

SDL_Renderer* gRenderer = NULL;
SDL_Texture* mBlueCrocodile = NULL;
SDL_Texture* mBackground = NULL;
SDL_Texture* mGhost = NULL;

SDL_Rect gSpriteClips[13];

SDL_Rect character_rect;
SDL_Rect background_rect;
SDL_Rect ghost_rect;

// Nytt *******************************************************

int main(int argc, char * argv[])
{
    SDL_Thread *enemy;

    if(initBuild()) // Om init och loadmedia fungerar körs programmet
    {
        enemy = SDL_CreateThread(nextMove, "enemyThread", (void *)NULL);

        keyInput2(); // Funktion för att ta hand om knapptryckningar
    }

    close1();       // funktion för att stänga av programmet med röda krysset

    return 0;
}

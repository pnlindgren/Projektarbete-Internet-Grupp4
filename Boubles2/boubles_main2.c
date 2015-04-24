#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//#include <pthread.h>

#include "main.h"
#include "initFunctions.h"
#include "close.h"
#include "keyInput.h"
#include "position.h"
#include "keyInput2.h"

SDL_Surface* loadSurface(char path[100]);
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gBackground = NULL;
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gCurrentSurface = NULL;

int main(int argc, char * argv[])
{
    if(initBuild()) // Om init och loadmedia fungerar körs programmet
    {
        keyInput2(); // Funktion för att ta hand om knapptryckningar
    }

    close1();       // funktion för att stänga av programmet med röda krysset

    return 0;
}

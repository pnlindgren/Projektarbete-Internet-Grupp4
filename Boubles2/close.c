#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "close.h"

void close1()
{
    SDL_Delay(1000);    // F�r att av knappen ska hinna visa vad den g�r

    SDL_FreeSurface(gBackground);

    gBackground = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();

}

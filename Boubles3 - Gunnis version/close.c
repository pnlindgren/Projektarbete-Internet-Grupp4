#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "close.h"

void closeProgram()
{
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

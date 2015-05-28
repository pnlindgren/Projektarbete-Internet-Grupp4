#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "close.h"

void closeProgram()
{
    SDL_DestroyWindow(gameWindow);
    gameWindow = NULL;

    SDL_Quit();
}

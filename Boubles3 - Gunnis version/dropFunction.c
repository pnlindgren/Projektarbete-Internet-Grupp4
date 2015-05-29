#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "dropFunction.h"

SDL_mutex *jumpMutex;

int dropFunction(void *pointer)
{
    jumpMutex = SDL_CreateMutex();
    int status;
    while(true)
    {
        status = SDL_LockMutex(jumpMutex);
        int x = localRects.character_rect.x, y = localRects.character_rect.y;
        if(status != 0)
        {
            printf("Mutex failed to lock");
        }
        //om karaktären är nånstans ovanför rad 3
        if( y < 97)
        {
            while(localRects.character_rect.y < 97)
            {
                localRects.character_rect.y++;
                SDL_Delay(5);
            }
        }
        // om karaktären är mellan rad 2 och 3
        else if(y > 97 && y < 196)
        {
            while(localRects.character_rect.y < 196)
            {
                localRects.character_rect.y ++;
                SDL_Delay(5);
            }
        }
        //om karaktären är mellan rad 1 och 2
        else if(y > 196 && y < 297)
        {
            while(localRects.character_rect.y < 297)
            {
                localRects.character_rect.y ++;
                SDL_Delay(5);
            }
        }
        //om karaktären är mellan rad 0(golv) och 1
        else if (y > 297 && y < 416)
        {
            while(localRects.character_rect.y < 416)
            {
                localRects.character_rect.y ++;
                SDL_Delay(5);
            }
        }
        // Rad 3 hål 1
        else if(y == 97 && x <= 160 && x >= 80)
        {
            localRects.character_rect.y ++;
            SDL_Delay(5);
        }
        // Rad 3 hål 2
        else if(y == 97 && x <= 516 && x >= 428)
        {
            localRects.character_rect.y ++;
            SDL_Delay(5);
        }
        // Rad 2 hål 1
        else if(y == 196 && x <= 344 && x >= 256)
        {
            localRects.character_rect.y ++;
            SDL_Delay(5);
        }
        // Rad 1 hål 1
        else if(y == 297 && x <= 160 && x >= 80)
        {
            localRects.character_rect.y ++;
            SDL_Delay(5);
        }
        else if(y == 297 && x <= 516 && x >= 432)
        {
            localRects.character_rect.y ++;
            SDL_Delay(5);
        }
        SDL_UnlockMutex(jumpMutex);
        SDL_Delay(5); //För att hinna läsa av keyinput för hopp innan mutex låses igen
    }
}

/*int enemyDrop(void *pointer)
{
    while(true)
    {
        int x = gameVariables.ghost_rect1.x, y = gameVariables.ghost_rect1.y;
        // Rad 3 hål 1
        if(y <= 97 && x <= 160 && x >= 80)
        {
            while(gameVariables.ghost_rect.y <= 195)
            {
                gameVariables.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }
        // Rad 3 hål 2
        else if(y <= 97 && x <= 516 && x >= 428)
        {
            while(gameVariables.ghost_rect.y <= 195)
            {
                gameVariables.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 2 hål 1
        else if(y <= 196 && y > 97 && x <= 344 && x >= 256)
        {
            while(gameVariables.ghost_rect.y <= 297)
            {
                gameVariables.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 1 hål 1
        else if(y <= 298 && y > 196 && x <= 160 && x >= 80)
        {
            while(gameVariables.ghost_rect.y <= 416)
            {
                gameVariables.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }
        else if(y <= 298 && y > 196 && x <= 516 && x >= 432)
        {
            while(gameVariables.ghost_rect.y <= 416)
            {
                gameVariables.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }
    }
}*/

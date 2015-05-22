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
        int x = gameRectangels.character_rect.x, y = gameRectangels.character_rect.y;
        if(status != 0)
        {
            printf("Mutex failed to lock");
        }
        //om karakt�ren �r n�nstans ovanf�r rad 3
        if( y < 97)
        {
            while(gameRectangels.character_rect.y < 97)
            {
                gameRectangels.character_rect.y++;
                SDL_Delay(5);
            }
        }
        // om karakt�ren �r mellan rad 2 och 3
        else if(y > 97 && y < 196)
        {
            while(gameRectangels.character_rect.y < 196)
            {
                gameRectangels.character_rect.y ++;
                SDL_Delay(5);
            }
        }
        //om karakt�ren �r mellan rad 1 och 2
        else if(y > 196 && y < 297)
        {
            while(gameRectangels.character_rect.y < 297)
            {
                gameRectangels.character_rect.y ++;
                SDL_Delay(5);
            }
        }
        //om karakt�ren �r mellan rad 0(golv) och 1
        else if (y > 297 && y < 416)
        {
            while(gameRectangels.character_rect.y < 416)
            {
                gameRectangels.character_rect.y ++;
                SDL_Delay(5);
            }
        }
        // Rad 3 h�l 1
        else if(y == 97 && x <= 160 && x >= 80)
        {
            gameRectangels.character_rect.y ++;
            SDL_Delay(5);
        }
        // Rad 3 h�l 2
        else if(y == 97 && x <= 516 && x >= 428)
        {
            gameRectangels.character_rect.y ++;
            SDL_Delay(5);
        }
        // Rad 2 h�l 1
        else if(y == 196 && x <= 344 && x >= 256)
        {
            gameRectangels.character_rect.y ++;
            SDL_Delay(5);
        }
        // Rad 1 h�l 1
        else if(y == 297 && x <= 160 && x >= 80)
        {
            gameRectangels.character_rect.y ++;
            SDL_Delay(5);
        }
        else if(y == 297 && x <= 516 && x >= 432)
        {
            gameRectangels.character_rect.y ++;
            SDL_Delay(5);
        }
        SDL_UnlockMutex(jumpMutex);
        SDL_Delay(5); //F�r att hinna l�sa av keyinput f�r hopp innan mutex l�ses igen
    }
}

int enemyDrop(void *pointer)
{
    while(true)
    {
        int x = gameRectangels.ghost_rect.x, y = gameRectangels.ghost_rect.y;
        // Rad 3 h�l 1
        if(y <= 97 && x <= 160 && x >= 80)
        {
            while(gameRectangels.ghost_rect.y <= 195)
            {
                gameRectangels.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }
        // Rad 3 h�l 2
        else if(y <= 97 && x <= 516 && x >= 428)
        {
            while(gameRectangels.ghost_rect.y <= 195)
            {
                gameRectangels.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 2 h�l 1
        else if(y <= 196 && y > 97 && x <= 344 && x >= 256)
        {
            while(gameRectangels.ghost_rect.y <= 297)
            {
                gameRectangels.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 1 h�l 1
        else if(y <= 298 && y > 196 && x <= 160 && x >= 80)
        {
            while(gameRectangels.ghost_rect.y <= 416)
            {
                gameRectangels.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }
        else if(y <= 298 && y > 196 && x <= 516 && x >= 432)
        {
            while(gameRectangels.ghost_rect.y <= 416)
            {
                gameRectangels.ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }
    }
}

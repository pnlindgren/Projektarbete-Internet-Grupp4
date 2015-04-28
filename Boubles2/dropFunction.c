#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "dropFunction.h"

int dropFunction(void *pointer)
{
    while(true)
    {
        int x = character_rect.x, y = character_rect.y;
        // Rad 3 hål 1
        if(y <= 97 && x <= 160 && x >= 80)
        {
            while(character_rect.y <= 195)
            {
                character_rect.y += 1;
                SDL_Delay(5);
            }
        }
        // Rad 3 hål 2
        else if(y <= 97 && x <= 516 && x >= 428)
        {
            while(character_rect.y <= 195)
            {
                character_rect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 2 hål 1
        else if(y <= 196 && y > 97 && x <= 344 && x >= 256)
        {
            while(character_rect.y <= 297)
            {
                character_rect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 1 hål 1
        else if(y <= 298 && y > 196 && x <= 160 && x >= 80)
        {
            while(character_rect.y <= 416)
            {
                character_rect.y += 1;
                SDL_Delay(5);
            }
        }
        else if(y <= 298 && y > 196 && x <= 516 && x >= 432)
        {
            while(character_rect.y <= 416)
            {
                character_rect.y += 1;
                SDL_Delay(5);
            }
        }
    }
}

int enemyDrop(void *pointer)
{
    while(true)
    {
        int x = ghost_rect.x, y = ghost_rect.y;
        // Rad 3 hål 1
        if(y <= 97 && x <= 160 && x >= 80)
        {
            while(ghost_rect.y <= 195)
            {
                ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }
        // Rad 3 hål 2
        else if(y <= 97 && x <= 516 && x >= 428)
        {
            while(ghost_rect.y <= 195)
            {
                ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 2 hål 1
        else if(y <= 196 && y > 97 && x <= 344 && x >= 256)
        {
            while(ghost_rect.y <= 297)
            {
                ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 1 hål 1
        else if(y <= 298 && y > 196 && x <= 160 && x >= 80)
        {
            while(ghost_rect.y <= 416)
            {
                ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }
        else if(y <= 298 && y > 196 && x <= 516 && x >= 432)
        {
            while(ghost_rect.y <= 416)
            {
                ghost_rect.y += 1;
                SDL_Delay(5);
            }
        }
    }
}

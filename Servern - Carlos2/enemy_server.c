#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//#include "main.h" --> finns i header filen
#include "enemy_Server.h"
#include "collisionHandler_server.h"

void nextMove(SDL_Rect *ghostRect)
{
    int direction = RIGHT;

    bool quit = false;

    SDL_Thread *droppingEnemy;

    srand(time(NULL));

    direction = rand() % 2;
    while(true)
    {
        while(ghostRect->y != 600)
        {
            if(collisions(*ghostRect) == true)
            {
                if(direction == RIGHT && ghostRect->y != 600)
                {
                    direction = LEFT;
                    ghostRect->x = ghostRect->x + 4;
                }
                else if(direction == LEFT && ghostRect->y != 600)
                {
                    direction = RIGHT;
                    ghostRect->x = ghostRect->x - 4;
                }
            }
            else
            {
                if(direction == RIGHT && ghostRect->y != 600)
                {
                    ghostRect->x = ghostRect->x - 4;    // lista ut senare hur mycket
                }
                else if(direction == LEFT && ghostRect->y != 600)
                {
                    ghostRect->x = ghostRect->x + 4;    // lista ut senare hur mycket
                }
            }

            SDL_Delay(100);       // för att se till så att funktionen inte körs hela tiden (sparar skickningar mellan server och client)
        }

        SDL_Delay(1000);
    }
}

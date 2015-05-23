#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//#include "main.h" --> finns i header filen
#include "enemy_Server.h"
#include "collisionHandler_server.h"

void nextMove(SDL_Rect *ghostRect1)
{
    int direction = RIGHT;

    bool quit = false;

    SDL_Thread *droppingEnemy;

    srand(time(NULL));

    direction = rand() % 2;

    while(1)
    {
        if(collisions(*ghostRect1) == true)
        {
            if(direction == RIGHT)
            {
                direction = LEFT;
                ghostRect1->x = ghostRect1->x + 4;
            }
            else
            {
                direction = RIGHT;
                ghostRect1->x = ghostRect1->x - 4;
            }
        }
        else
        {
            if(direction == RIGHT)
            {
                ghostRect1->x = ghostRect1->x - 4;    // lista ut senare hur mycket
            }
            else if(direction == LEFT)
            {
                ghostRect1->x = ghostRect1->x + 4;    // lista ut senare hur mycket
            }
        }

        SDL_Delay(100);       // för att se till så att funktionen inte körs hela tiden (sparar skickningar mellan server och client)
    }
}

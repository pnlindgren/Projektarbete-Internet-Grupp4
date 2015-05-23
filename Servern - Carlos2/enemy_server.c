#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//#include "main.h" --> finns i header filen
#include "enemy_Server.h"
#include "collisionHandler_server.h"
#include "dropFunction_server.h"

void nextMove(void * pointer)
{
    int direction = RIGHT;

    bool quit = false;

    SDL_Thread *droppingEnemy;

    srand(time(NULL));

    direction = rand() % 2;

    droppingEnemy = SDL_CreateThread(enemyDrop, "EnemyDrop", (void *)NULL); // drop detect

    while(1)
    {
        if(collisions(ghostRect) == true)
        {
            if(direction == RIGHT)
            {
                direction = LEFT;
                ghostRect.x = ghostRect.x + 4;
            }
            else
            {
                direction = RIGHT;
                ghostRect.x = ghostRect.x - 4;
            }
        }
        else
        {
            if(direction == RIGHT)
            {
                ghostRect.x = ghostRect.x - 4;    // lista ut senare hur mycket
            }
            else if(direction == LEFT)
            {
                ghostRect.x = ghostRect.x + 4;    // lista ut senare hur mycket
            }
        }

        SDL_Delay(100);       // för att se till så att funktionen inte körs hela tiden (sparar skickningar mellan server och client)
    }
}

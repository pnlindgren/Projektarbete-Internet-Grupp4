#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "position.h"
#include "wallDetector.h"

#define RIGHT 1
#define LEFT 0

int drop()              // Hur den faller
{
    return 97;
}
void collisionDetection(SDL_Rect enemy)
{
    //return 0;
}

void nextMove(void * pointer)
{
    int direction = RIGHT;

    bool moved = false;

    srand(time(NULL));

    if(moved == false)
    {
        direction = rand() % 1;
    }

    while(1)
    {
        if(wallDetection() == true)
        {
            if(direction == RIGHT)
            {
                direction = LEFT;
                ghost_rect.x = ghost_rect.x + 4;
            }
            else
            {
                direction = RIGHT;
                ghost_rect.x = ghost_rect.x - 4;
            }
        }
        else
        {
            if(direction == RIGHT)
            {
                ghost_rect.x = ghost_rect.x - 4;    // lista ut senare hur mycket
            }
            else if(direction == LEFT)
            {
                ghost_rect.x = ghost_rect.x + 4;    // lista ut senare hur mycket
            }
        }

        ghost_rect.y = drop(ghost_rect.x);        // h�r returnerar drop samma y v�rde om gubben inte faller

        collisionDetection(ghost_rect);   // kollar om sp�ket ska st� stilla pga en collision eller inte

        SDL_Delay(500);       // f�r att se till s� att funktionen inte k�rs hela tiden (sparar skickningar mellan server och client)
    }
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "position.h"


#define RIGHT 1
#define LEFT 0

bool wallDetection()    // funktion för att hålla koll på om fienden har stött på en vägg
{
    return false;
}
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
            else
            {
                ghost_rect.x = ghost_rect.x + 4;    // lista ut senare hur mycket
            }
        }

        ghost_rect.y = drop(ghost_rect.x);        // här returnerar drop samma y värde om gubben inte faller

        collisionDetection(ghost_rect);   // kollar om spöket ska stå stilla pga en collision eller inte

        SDL_Delay(1000);       // för att se till så att funktionen inte körs hela tiden (sparar skickningar mellan server och client)
    }
}

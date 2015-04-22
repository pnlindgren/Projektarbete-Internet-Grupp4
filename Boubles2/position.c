#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "position.h"

#define right 1
#define left 0

/*struct position{
    int x, y;
}; typedef struct position Position*/

bool wallDetection()    // funktion f�r att h�lla koll p� om fienden har st�tt p� en v�gg
{
    return true;
}
int drop()              // Hur den faller
{
    return 1;
}
void collisionDetection()
{
    return 0;
}

void updateSurface()
{
    //SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
    //SDL_UpdateWindowSurface(gWindow);
}

void nextMove(int x,int y, bool moved, int direction)
{
    srand(time(NULL));

    if(moved == false)
    {
        direction = rand() % 1;
    }

    if(wallDetection() == true)
    {
        if(direction == right)
        {
            direction = left;
            x--;
        }
        else
        {
            direction = right;
            x++;
        }
    }
    else
    {
        if(direction == right)
        {
            x++;    // lista ut senare hur mycket
        }
        else
        {
            x--;    // lista ut senare hur mycket
        }
    }

    y = drop(x);        // h�r returnerar drop samma y v�rde om gubben inte faller

    updateSurface();

    collisionDetection(x,y);   // kollar om sp�ket ska st� stilla pga en collision eller inte

    Sleep(1000);       // f�r att se till s� att funktionen inte k�rs hela tiden (sparar skickningar mellan server och client)
}

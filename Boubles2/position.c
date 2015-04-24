#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>

#include "main.h"
#include "position.h"


#define RIGHT 1
#define LEFT 0

bool wallDetection()    // funktion f�r att h�lla koll p� om fienden har st�tt p� en v�gg
{
    return true;
}
int drop()              // Hur den faller
{
    return 1;
}
void collisionDetection(SDL_Rect enemy)
{
    //return 0;
}

void updateSurface()
{
    //SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
    //SDL_UpdateWindowSurface(gWindow);
}

void nextMove(void * pointer)
{
    int direction = LEFT;

    bool moved = false;

    SDL_Rect enemy;

    enemy.x = 100;
    enemy.y = 100;
    enemy.w = 50;
    enemy.h = 50;

    //Apply the image
    SDL_BlitSurface(gKeyPressSurfaces[KEY_PRESS_SURFACE_UP], NULL, gScreenSurface, &enemy );
    //Update the surface
    SDL_UpdateWindowSurface( gWindow );

    srand(time(NULL));

    if(moved == false)
    {
        direction = rand() % 1;
    }

    if(wallDetection() == true)
    {
        if(direction == RIGHT)
        {
            direction = LEFT;
            enemy.x--;
        }
        else
        {
            direction = RIGHT;
            enemy.x++;
        }
    }
    else
    {
        if(direction == RIGHT)
        {
            enemy.x++;    // lista ut senare hur mycket
        }
        else
        {
            enemy.x--;    // lista ut senare hur mycket
        }
    }

    enemy.y = drop(enemy.x);        // h�r returnerar drop samma y v�rde om gubben inte faller

    updateSurface();

    collisionDetection(enemy);   // kollar om sp�ket ska st� stilla pga en collision eller inte

    SDL_Delay(1000);       // f�r att se till s� att funktionen inte k�rs hela tiden (sparar skickningar mellan server och client)
}

#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "collisionHandler_server.h"

bool collisions(SDL_Rect rectangle)
{
    bool collision = false;

    if(SDL_HasIntersection(&left_wall, &rectangle))
    {
        collision = true;
        //printf("\nLeft wall\n");
    }
    if(SDL_HasIntersection(&right_wall, &rectangle))
    {
        collision = true;
        //printf("\nRight wall\n");
    }

    return collision;
}
#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "collisionHandler_server.h"

bool collisions(SDL_Rect rectangle)
{
    bool collision = false;

    if(SDL_HasIntersection(&r3p1v, &rectangle))
    {
        collision = true;
    }
    if(SDL_HasIntersection(&r3p1h, &rectangle))
    {
        collision = true;
    }
    if(SDL_HasIntersection(&r2p0v, &rectangle))
    {
        collision = true;
    }
    if(SDL_HasIntersection(&r2p0h, &rectangle))
    {
        collision = true;
    }

    return collision;
}

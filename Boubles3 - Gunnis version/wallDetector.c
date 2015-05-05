#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "wallDetector.h"

bool collisions(SDL_Rect rectangle)
{
    bool collision = false;

    if(SDL_HasIntersection(&ghost_rect, &character_rect))
    {
        collision = true;
        characterCollision = true;
    }
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

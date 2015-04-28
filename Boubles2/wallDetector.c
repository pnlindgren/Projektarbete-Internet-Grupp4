#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "wallDetector.h"

bool wallDetection(SDL_Rect rectangle)
{
    bool collision = false;

    if((rectangle.x == ghost_rect.x && rectangle.y == ghost_rect.y) && SDL_HasIntersection(&character_rect, &rectangle))
    {
        collision = true;
    }
    if(SDL_HasIntersection(&left_wall, &rectangle))
    {
        collision = true;
        printf("\nLeft wall\n");
    }
    if(SDL_HasIntersection(&right_wall, &rectangle))
    {
        collision = true;
        printf("\nRight wall\n");
    }

    return collision;
}

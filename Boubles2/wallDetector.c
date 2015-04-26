#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "wallDetector.h"

// Baserad på lazyfoo.net/SDL_tutorials/lesson17/
bool wallDetection()
{
    bool collision = false;

    SDL_Rect left_wall, right_wall;

    left_wall.x = 0;
    left_wall.y = 0;
    left_wall.w = 8;
    left_wall.h = 480;

    right_wall.x = 621;
    right_wall.y = 0;
    right_wall.w = 8;
    right_wall.h = 480;

    if(SDL_HasIntersection(&character_rect, &ghost_rect))
    {
        collision = true;
    }
    if(SDL_HasIntersection(&left_wall, &ghost_rect))
    {
        collision = true;
        printf("\nLeft wall\n");
    }
    if(SDL_HasIntersection(&right_wall, &ghost_rect))
    {
        collision = true;
        printf("\nRight wall\n");
    }

    return collision;
}

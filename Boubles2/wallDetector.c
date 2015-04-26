#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "wallDetector.h"

// Baserad på lazyfoo.net/SDL_tutorials/lesson17/
bool wallDetection()
{
    bool collision = false;

    SDL_Rect left_wall, right_wall;

    left_wall.x = 16;
    left_wall.y = 0;
    left_wall.w = 1;
    left_wall.h = 480;

    left_wall.x = 624;
    left_wall.y = 0;
    left_wall.w = 1;
    left_wall.h = 480;

    if(SDL_HasIntersection(&character_rect, &ghost_rect))
    {
        collision = true;
    }
    else if(SDL_HasIntersection(&left_wall, &ghost_rect))
    {
        collision = true;
    }

    return collision;
}

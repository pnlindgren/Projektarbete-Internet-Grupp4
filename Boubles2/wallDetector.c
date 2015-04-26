#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "wallDetector.h"

// Baserad på lazyfoo.net/SDL_tutorials/lesson17/
bool wallDetection()
{
    // kan bli en array
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = character_rect.x;
    rightA = character_rect.x + character_rect.w;
    topA = character_rect.y;
    bottomA = character_rect.y + character_rect.h;

    leftB = ghost_rect.x;
    rightB = ghost_rect.x + ghost_rect.w;
    topB = ghost_rect.y;
    bottomB = ghost_rect.y + ghost_rect.h;

    if(bottomA <= topB)
    {
        return false;
    }

    if(topA >= bottomB)
    {
        return false;
    }

    if(rightA <= leftB)
    {
        return false;
    }

    if(leftA >= rightB)
    {
        return false;
    }

    return true;
}

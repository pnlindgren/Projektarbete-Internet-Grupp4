#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "wallDetector.h"

// Baserad på lazyfoo.net/SDL_tutorials/lesson17/
bool wallDetection()
{
    return SDL_HasIntersection(&character_rect, &ghost_rect);
}

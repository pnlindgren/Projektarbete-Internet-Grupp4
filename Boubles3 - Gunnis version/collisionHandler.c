#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "collisionHandler.h"

bool collisions(SDL_Rect rectangle)
{
    bool collision = false;

    if(SDL_HasIntersection(&gameVariables.left_wall, &rectangle))
    {
        collision = true;
    }
    if(SDL_HasIntersection(&gameVariables.right_wall, &rectangle))
    {
        collision = true;
    }

    return collision;
}

int enemyCollision()
{
    while(1)
    {
        if(SDL_HasIntersection(&gameVariables.ghost_rect, &gameVariables.character_rect) || SDL_HasIntersection(&gameVariables.ghost_rect, &gameVariables.rival_rect))
        {
            characterCollision = true;
        }
        SDL_Delay(50);
    }
}

#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "collisionHandler.h"

bool collisions(SDL_Rect rectangle)
{
    bool collision = false;

    if(SDL_HasIntersection(&localRects.left_wall, &rectangle))
    {
        collision = true;
    }
    if(SDL_HasIntersection(&localRects.right_wall, &rectangle))
    {
        collision = true;
    }

    return collision;
}

int enemyCollision()
{
    SDL_Delay(2000);    // Gör karaktärerna odödliga i början för
                        // att förhindra att de ska intersecta när de placeras vid början
    while(1)
    {
        if(SDL_HasIntersection(&localRects.ghost_rect1, &localRects.character_rect) || SDL_HasIntersection(&localRects.ghost_rect1, &localRects.rival_rect))
        {
            gameVariables.character_collision = true;
        }
        if(SDL_HasIntersection(&localRects.ghost_rect2, &localRects.character_rect) || SDL_HasIntersection(&localRects.ghost_rect2, &localRects.rival_rect))
        {
            gameVariables.character_collision = true;
        }
        if(SDL_HasIntersection(&localRects.ghost_rect3, &localRects.character_rect) || SDL_HasIntersection(&localRects.ghost_rect3, &localRects.rival_rect))
        {
            gameVariables.character_collision = true;
        }
        if(SDL_HasIntersection(&localRects.ghost_rect4, &localRects.character_rect) || SDL_HasIntersection(&localRects.ghost_rect4, &localRects.rival_rect))
        {
            gameVariables.character_collision = true;
        }
        if(SDL_HasIntersection(&localRects.ghost_rect5, &localRects.character_rect) || SDL_HasIntersection(&localRects.ghost_rect5, &localRects.rival_rect))
        {
            gameVariables.character_collision = true;
        }
        SDL_Delay(50);
    }
}

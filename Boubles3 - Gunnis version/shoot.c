#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "shoot.h"
#include "sound.h"

#define SPEED 3

// <-----
int shootFunc()
{
    soundShoot();

    bool quit = false;

    gameVariables.bubble_view = true;

    localRects.bubble_rect.x = localRects.character_rect.x - 40;
    localRects.bubble_rect.y = localRects.character_rect.y;

    while(localRects.bubble_rect.x>0 && quit == false)
    {
        localRects.bubble_rect.x = localRects.bubble_rect.x - SPEED;

        if(SDL_HasIntersection(&localRects.ghost_rect1, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect1.x=0;
            localRects.ghost_rect1.y=600;
            quit = true;
            gameVariables.ghostFlag1 = true;
        }
        else if(SDL_HasIntersection(&localRects.ghost_rect2, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect2.x=0;
            localRects.ghost_rect2.y=600;
            quit = true;
            gameVariables.ghostFlag2 = true;
        }
        else if(SDL_HasIntersection(&localRects.ghost_rect3, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect3.x=0;
            localRects.ghost_rect3.y=600;
            quit = true;
            gameVariables.ghostFlag3 = true;
        }
        else if(SDL_HasIntersection(&localRects.ghost_rect4, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect4.x=0;
            localRects.ghost_rect4.y=600;
            quit = true;
            gameVariables.ghostFlag4 = true;
        }
        else if(SDL_HasIntersection(&localRects.ghost_rect5, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect5.x=0;
            localRects.ghost_rect5.y=600;
            quit = true;
            gameVariables.ghostFlag5 = true;
        }

        SDL_Delay(30);
    }

    shootFlag = true;
    gameVariables.bubble_view = false;

    localRects.bubble_rect.x = 600;
    localRects.bubble_rect.y = 600;
}

// ---->
int shootFuncRight()
{
    soundShoot();

    bool quit = false;

    gameVariables.bubble_view = true;

    localRects.bubble_rect.x = localRects.character_rect.x + 40;
    localRects.bubble_rect.y = localRects.character_rect.y;

    while(localRects.bubble_rect.x<580 && quit == false)
    {
        localRects.bubble_rect.x = localRects.bubble_rect.x + SPEED;

        if(SDL_HasIntersection(&localRects.ghost_rect1, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect1.x=0;
            localRects.ghost_rect1.y=600;
            quit = true;
            gameVariables.ghostFlag1 = true;
        }
        else if(SDL_HasIntersection(&localRects.ghost_rect2, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect2.x=0;
            localRects.ghost_rect2.y=600;
            quit = true;
            gameVariables.ghostFlag2 = true;
        }
        else if(SDL_HasIntersection(&localRects.ghost_rect3, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect3.x=0;
            localRects.ghost_rect3.y=600;
            quit = true;
            gameVariables.ghostFlag3 = true;
        }
        else if(SDL_HasIntersection(&localRects.ghost_rect4, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect4.x=0;
            localRects.ghost_rect4.y=600;
            quit = true;
            gameVariables.ghostFlag4 = true;
        }
        else if(SDL_HasIntersection(&localRects.ghost_rect5, &localRects.bubble_rect))
        {
            gameVariables.bubble_view = false;
            localRects.ghost_rect5.x=0;
            localRects.ghost_rect5.y=600;
            quit = true;
            gameVariables.ghostFlag5 = true;
        }

        SDL_Delay(30);
    }

    shootFlag = true;
    gameVariables.bubble_view = false;

    localRects.bubble_rect.x = 600;
    localRects.bubble_rect.y = 600;
}

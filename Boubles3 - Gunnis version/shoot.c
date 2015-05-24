#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "shoot.h"

#define SPEED 3

// <-----
int shootFunc(){

    bool quit = false;
    shootFlag = false;

    gameVariables.bubble_view = true;

    gameVariables.bubble_rect.x = gameVariables.character_rect.x - 40;
    gameVariables.bubble_rect.y = gameVariables.character_rect.y;

    while(gameVariables.bubble_rect.x>0 && quit == false)
    {
        gameVariables.bubble_rect.x = gameVariables.bubble_rect.x - SPEED;

        if(SDL_HasIntersection(&gameVariables.ghost_rect1, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect1.x=0;
            gameVariables.ghost_rect1.y=600;
            quit = true;
        }
        else if(SDL_HasIntersection(&gameVariables.ghost_rect2, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect2.x=0;
            gameVariables.ghost_rect2.y=600;
            quit = true;
        }
        else if(SDL_HasIntersection(&gameVariables.ghost_rect3, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect3.x=0;
            gameVariables.ghost_rect3.y=600;
            quit = true;
        }
        else if(SDL_HasIntersection(&gameVariables.ghost_rect4, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect4.x=0;
            gameVariables.ghost_rect4.y=600;
            quit = true;
        }
        else if(SDL_HasIntersection(&gameVariables.ghost_rect5, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect5.x=0;
            gameVariables.ghost_rect5.y=600;
            quit = true;
        }

        SDL_Delay(30);
    }

    shootFlag = true;
    gameVariables.bubble_view = false;

    gameVariables.bubble_rect.x = 600;
    gameVariables.bubble_rect.y = 600;
}

// ---->
int shootFuncRight(){

    bool quit = false;
    shootFlag = false;

    gameVariables.bubble_view = true;

    gameVariables.bubble_rect.x = gameVariables.character_rect.x + 40;
    gameVariables.bubble_rect.y = gameVariables.character_rect.y;

    while(gameVariables.bubble_rect.x<600 && quit == false)
    {
        gameVariables.bubble_rect.x = gameVariables.bubble_rect.x + SPEED;

        if(SDL_HasIntersection(&gameVariables.ghost_rect1, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect1.x=0;
            gameVariables.ghost_rect1.y=600;
            quit = true;
        }
        else if(SDL_HasIntersection(&gameVariables.ghost_rect2, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect2.x=0;
            gameVariables.ghost_rect2.y=600;
            quit = true;
        }
        else if(SDL_HasIntersection(&gameVariables.ghost_rect3, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect3.x=0;
            gameVariables.ghost_rect3.y=600;
            quit = true;
        }
        else if(SDL_HasIntersection(&gameVariables.ghost_rect4, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect4.x=0;
            gameVariables.ghost_rect4.y=600;
            quit = true;
        }
        else if(SDL_HasIntersection(&gameVariables.ghost_rect5, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            gameVariables.ghost_rect5.x=0;
            gameVariables.ghost_rect5.y=600;
            quit = true;
        }

        SDL_Delay(30);
    }

    shootFlag = true;
    gameVariables.bubble_view = false;

    gameVariables.bubble_rect.x = 600;
    gameVariables.bubble_rect.y = 600;
}

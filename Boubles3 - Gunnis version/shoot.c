#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "shoot.h"

int shootFunc(){

    bool quit = false;

    gameVariables.bubble_view = true;

    gameVariables.bubble_rect.x = gameVariables.character_rect.x - 40;
    gameVariables.bubble_rect.y = gameVariables.character_rect.y;

    while(gameVariables.bubble_rect.x>0 && quit == false)
    {
        if(SDL_HasIntersection(&gameVariables.ghost_rect1, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            ghosthit++;
            gameVariables.ghost_rect1.x=0;
            gameVariables.ghost_rect1.y=0;
            quit = true;
        }

        gameVariables.bubble_rect.x = gameVariables.bubble_rect.x - 1;
        SDL_Delay(30);
        gameVariables.bubble_rect.x--;
    }


    gameVariables.bubble_view = false;
}

int shootFuncRight(){

    bool quit = false;

    gameVariables.bubble_view = true;

    gameVariables.bubble_rect.x = gameVariables.character_rect.x + 40;
    gameVariables.bubble_rect.y = gameVariables.character_rect.y;

    while(gameVariables.bubble_rect.x<600 && quit == false)
    {
        if(SDL_HasIntersection(&gameVariables.ghost_rect1, &gameVariables.bubble_rect))
        {
            gameVariables.bubble_view = false;
            ghosthit++;
            gameVariables.ghost_rect1.x=0;
            gameVariables.ghost_rect1.y=0;
            quit = true;
        }

        gameVariables.bubble_rect.x = gameVariables.bubble_rect.x + 1;
        SDL_Delay(30);
        gameVariables.bubble_rect.x++;
    }

    gameVariables.bubble_view = false;
}

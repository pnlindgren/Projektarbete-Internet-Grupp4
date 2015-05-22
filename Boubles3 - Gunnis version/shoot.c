#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "shoot.h"

int shootFunc(){

    bool quit = false;

    bubble_view = true;

    gameRectangels.bubble_rect.x = gameRectangels.character_rect.x - 40;
    gameRectangels.bubble_rect.y = gameRectangels.character_rect.y;

    while(gameRectangels.bubble_rect.x>0 && quit == false)
    {
        if(SDL_HasIntersection(&gameRectangels.ghost_rect, &gameRectangels.bubble_rect))
        {
            bubble_view = false;
            ghosthit++;
            gameRectangels.ghost_rect.x=0;
            gameRectangels.ghost_rect.y=0;
            quit = true;
        }

        gameRectangels.bubble_rect.x = gameRectangels.bubble_rect.x - 1;
        SDL_Delay(30);
        gameRectangels.bubble_rect.x--;
    }


    bubble_view = false;
}

int shootFuncRight(){

    bool quit = false;

    bubble_view = true;

    gameRectangels.bubble_rect.x = gameRectangels.character_rect.x + 40;
    gameRectangels.bubble_rect.y = gameRectangels.character_rect.y;

    while(gameRectangels.bubble_rect.x<600 && quit == false)
    {
        if(SDL_HasIntersection(&gameRectangels.ghost_rect, &gameRectangels.bubble_rect))
        {
            bubble_view = false;
            ghosthit++;
            gameRectangels.ghost_rect.x=0;
            gameRectangels.ghost_rect.y=0;
            quit = true;
        }

        gameRectangels.bubble_rect.x = gameRectangels.bubble_rect.x + 1;
        SDL_Delay(30);
        gameRectangels.bubble_rect.x++;
    }

    bubble_view = false;
}

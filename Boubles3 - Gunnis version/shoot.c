#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "shoot.h"

int shootFunc(){

    bool quit = false;

    printf("\nbubblan\n");

    bubble_rect.x = character_rect.x;
    bubble_rect.y = character_rect.y;
    bubble_rect.w = 40;
    bubble_rect.h = 40;

    bubble_view = true;
    bubble_rect.x = bubble_rect.x - 40;

    while(bubble_rect.x>0 && quit == false)
    {
         if(SDL_HasIntersection(&ghost_rect, &bubble_rect))
        {
            bubble_view = false;
            ghosthit++;
            ghost_rect.x=0;
            ghost_rect.y=0;
            quit = true;
        }

        bubble_rect.x = bubble_rect.x - 1;
        SDL_Delay(30);
        bubble_rect.x--;
    }


    bubble_view = false;
}

int shootFuncRight(){

    printf("\nbubblan\n");

    bubble_rect.x = character_rect.x;
    bubble_rect.y = character_rect.y;
    bubble_rect.w = 40;
    bubble_rect.h = 40;

    bubble_view = true;
    bubble_rect.x = bubble_rect.x + 10;

    while(bubble_rect.x<640)
    {
        if(ghost_rect.x==bubble_rect.x){
        bubble_view = false;
        }
        bubble_rect.x = bubble_rect.x + 1;
        SDL_Delay(30);
        bubble_rect.x++;
    }


    bubble_view = false;
}

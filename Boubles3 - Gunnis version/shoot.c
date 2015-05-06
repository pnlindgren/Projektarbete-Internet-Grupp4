#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "shoot.h"
#include "enemy.h"


int shootFunc(){

    printf("\nbubblan\n");

    bubble_rect.x = character_rect.x;
    bubble_rect.y = character_rect.y;
    bubble_rect.w = 40;
    bubble_rect.h = 40;

    bubble_view = true;
    bubble_rect.x = bubble_rect.x - 40;

    while(bubble_rect.x>0)
    {
        if(ghost_rect.x==bubble_rect.x){
        bubble_view = false;
        }
        bubble_rect.x = bubble_rect.x - 1;
        SDL_Delay(30);
        bubble_rect.x--;
    }

    bubble_view = false;
}




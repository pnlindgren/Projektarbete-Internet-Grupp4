#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "dropFunction_server.h"

SDL_mutex *jumpMutex;

int enemyDrop(void *pointer)
{
    while(true)
    {
        int x = sendInfo.ghostRect.x, y = sendInfo.ghostRect.y;
        // Rad 3 h�l 1
        if(y <= 97 && x <= 160 && x >= 80)
        {
            while(sendInfo.ghostRect.y <= 195)
            {
                sendInfo.ghostRect.y += 1;
                SDL_Delay(5);
            }
        }
        // Rad 3 h�l 2
        else if(y <= 97 && x <= 516 && x >= 428)
        {
            while(sendInfo.ghostRect.y <= 195)
            {
                sendInfo.ghostRect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 2 h�l 1
        else if(y <= 196 && y > 97 && x <= 344 && x >= 256)
        {
            while(sendInfo.ghostRect.y <= 297)
            {
                sendInfo.ghostRect.y += 1;
                SDL_Delay(5);
            }
        }

        // Rad 1 h�l 1
        else if(y <= 298 && y > 196 && x <= 160 && x >= 80)
        {
            while(sendInfo.ghostRect.y <= 416)
            {
                sendInfo.ghostRect.y += 1;
                SDL_Delay(5);
            }
        }
        else if(y <= 298 && y > 196 && x <= 516 && x >= 432)
        {
            while(sendInfo.ghostRect.y <= 416)
            {
                sendInfo.ghostRect.y += 1;
                SDL_Delay(5);
            }
        }
    }
}
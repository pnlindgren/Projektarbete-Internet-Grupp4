#include "main.h"
#include "screenUpdater.h"
#include <stdbool.h>

int screenUpdateFunction(void * pointer)
{
    bool quit = false;

    while(quit != true)
    {
        // SDL_RenderClear(gRenderer);
        SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[frame],&character_rect , 0, NULL, flip);
        SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
        //SDL_RenderCopyEx(gRenderer, mWall, &gSpriteClips[9],&wall_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderPresent(gRenderer);

        if(characterCollision == true)
        {
            quit = true;
        }
         if(bubble_view==true){

            SDL_RenderClear(gRenderer);
            SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[frame],&character_rect , 0, NULL, flip);
            SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gRenderer, mBubble, &gSpriteClips[9],&bubble_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderPresent(gRenderer);
        }
    }

    SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);

    SDL_Delay(100);

    SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[frame],&character_rect , 0, NULL, flip);
    SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);


    }


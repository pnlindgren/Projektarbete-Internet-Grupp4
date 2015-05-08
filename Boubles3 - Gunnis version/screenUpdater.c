#include "main.h"
#include "screenUpdater.h"
#include <stdbool.h>

int screenUpdateFunction(void * pointer)
{
    bool quit = false;

    while(quit != true)
    {
        if(bubble_view==false)
        {
        // SDL_RenderClear(gRenderer);
        SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[frame],&character_rect , 0, NULL, flip);
        SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[1],&recievedI.character_rects[1] , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderPresent(gRenderer);
        }
        else
        {
            SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[frame],&character_rect , 0, NULL, flip);
            SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gRenderer, mBubble, &gSpriteClips[10],&bubble_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[1],&recievedI.character_rects[1] , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderPresent(gRenderer);
        }

        if(characterCollision == true)
        {
            quit = true;
        }
    }

    SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[1],&recievedI.character_rects[1] , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);

    SDL_Delay(1000);

    SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[frame],&character_rect , 0, NULL, flip);
    SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[1],&recievedI.character_rects[1] , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);
}

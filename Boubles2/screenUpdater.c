#include "main.h"
#include "screenUpdater.h"

void screenUpdateFunction(void * pointer)
{
    while(1)
    {
        // SDL_RenderClear(gRenderer);
        SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[frame],&character_rect , 0, NULL, flip);
        SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
        //SDL_RenderCopyEx(gRenderer, mWall, &gSpriteClips[9],&wall_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderPresent(gRenderer);
    }
}

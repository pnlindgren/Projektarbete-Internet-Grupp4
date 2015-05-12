#include "main.h"
#include "screenUpdater.h"
#include <stdbool.h>

int screenUpdateFunction(void * pointer)
{
    bool quit = false;

    SDL_Rect game_over;

    game_over.x = 200;
    game_over.y = 200;
    game_over.w = 191;
    game_over.h = 63;

    while(quit != true)
    {
        if(bubble_view == false)
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

        if((characterCollision == true) || (ghosthit == 5))
        {
            quit = true;
        }
    }

    SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);

    SDL_Delay(1000);

    SDL_RenderCopyEx(gRenderer, mBackground, &gSpriteClips[6],&background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[frame],&character_rect , 0, NULL, flip);
    SDL_RenderCopyEx(gRenderer, mGhost, &gSpriteClips[8],&ghost_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mBlueCrocodile, &gSpriteClips[1],&recievedI.character_rects[1] , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gRenderer, mGameOver, &gSpriteClips[11],&game_over, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);
}

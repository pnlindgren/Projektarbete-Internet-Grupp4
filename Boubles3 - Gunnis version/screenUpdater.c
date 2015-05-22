#include "main.h"
#include "screenUpdater.h"
#include <stdbool.h>

int screenUpdateFunction(void * pointer)
{
    bool quit = false;

    while(quit != true)
    {
        if(bubble_view == false)
        {
            // SDL_RenderClear(gRenderer);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &gSpriteClips[6],&gameRectangels.background_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[frame],&gameRectangels.character_rect , 0, NULL, flip);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameRectangels.ghost_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[1],&gameRectangels.rival_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderPresent(gameTextures.renderer);
        }
        else
        {
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &gSpriteClips[6],&gameRectangels.background_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[frame],&gameRectangels.character_rect , 0, NULL, flip);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameRectangels.ghost_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.bubble, &gSpriteClips[10],&gameRectangels.bubble_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[1],&gameRectangels.rival_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderPresent(gameTextures.renderer);
        }

        if((characterCollision == true) || (ghosthit == 5))
        {
            quit = true;
        }
    }

    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &gSpriteClips[6],&gameRectangels.background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameRectangels.ghost_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gameTextures.renderer);

    SDL_Delay(1000);

    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &gSpriteClips[6],&gameRectangels.background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[frame],&gameRectangels.character_rect , 0, NULL, flip);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameRectangels.ghost_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[1],&gameRectangels.rival_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.gameOver, &gSpriteClips[11],&gameRectangels.game_over, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gameTextures.renderer);
}

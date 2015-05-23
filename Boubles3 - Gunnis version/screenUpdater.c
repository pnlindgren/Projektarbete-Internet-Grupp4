#include "main.h"
#include "screenUpdater.h"
#include <stdbool.h>

int screenUpdateFunction(void * pointer)
{
    bool quit = false;

    while(quit != true)
    {
        if(gameVariables.bubble_view == false)
        {
            // SDL_RenderClear(gRenderer);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &gSpriteClips[6],&gameVariables.background_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[gameVariables.frame],&gameVariables.character_rect , 0, NULL, gameVariables.character_flip);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[gameVariables.enemy_frame],&gameVariables.rival_rect , 0, NULL, gameVariables.enemy_flip);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect1 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect2 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect3 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect4 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect5 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.bubble, &gSpriteClips[10],&gameVariables.bubble_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderPresent(gameTextures.renderer);
        }
        else
        {
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &gSpriteClips[6],&gameVariables.background_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[gameVariables.frame],&gameVariables.character_rect , 0, NULL, gameVariables.character_flip);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[gameVariables.enemy_frame],&gameVariables.rival_rect , 0, NULL, gameVariables.enemy_flip);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect1 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect2 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect3 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect4 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect5 , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(gameTextures.renderer, gameTextures.bubble, &gSpriteClips[10],&gameVariables.bubble_rect , 0, NULL, SDL_FLIP_NONE);
            SDL_RenderPresent(gameTextures.renderer);
        }

        if((characterCollision == true) || (ghosthit == 5))
        {
            quit = true;
        }
    }

    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &gSpriteClips[6],&gameVariables.background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect1 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect2 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect3 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect4 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect5 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gameTextures.renderer);

    SDL_Delay(1000);

    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &gSpriteClips[6],&gameVariables.background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[gameVariables.frame],&gameVariables.character_rect , 0, NULL, gameVariables.character_flip);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &gSpriteClips[gameVariables.enemy_frame],&gameVariables.rival_rect , 0, NULL, gameVariables.enemy_flip);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect1 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect2 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect3 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect4 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &gSpriteClips[8],&gameVariables.ghost_rect5 , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.gameOver, &gSpriteClips[11],&gameVariables.game_over, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gameTextures.renderer);
}

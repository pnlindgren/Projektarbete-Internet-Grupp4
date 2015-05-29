#include "main.h"
#include "screenUpdater.h"
#include <stdbool.h>

int screenUpdateFunction(void * pointer)
{
    bool quit = false;

    while(quit != true)
    {
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &spriteClips[6],&localRects.background_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.pinkCrocodile, &spriteClips[gameVariables.character_frame],&localRects.character_rect , 0, NULL, gameVariables.character_flip);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &spriteClips[gameVariables.enemy_frame],&localRects.rival_rect , 0, NULL, gameVariables.enemy_flip);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect1 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect2 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect3 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect4 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect5 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.bubble, &spriteClips[10],&localRects.bubble_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.bubble, &spriteClips[10],&localRects.enemy_bubble , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderPresent(gameTextures.renderer);

        if((gameVariables.character_collision == true) || (gameVariables.ghostHit == 5))
        {
            quit = true;
        }

        SDL_Delay(50);
    }

    SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &spriteClips[6],&localRects.background_rect , 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gameTextures.renderer);

    SDL_Delay(1000);

    if(gameVariables.ghostHit == 5)
    {
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &spriteClips[6],&localRects.background_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.pinkCrocodile, &spriteClips[gameVariables.character_frame],&localRects.character_rect , 0, NULL, gameVariables.character_flip);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &spriteClips[gameVariables.enemy_frame],&localRects.rival_rect , 0, NULL, gameVariables.enemy_flip);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.gameOver, &spriteClips[11],&localRects.game_over, 0, NULL, SDL_FLIP_NONE);
        SDL_RenderPresent(gameTextures.renderer);
    }
    else
    {
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.background, &spriteClips[6],&localRects.background_rect , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.pinkCrocodile, &spriteClips[gameVariables.character_frame],&localRects.character_rect , 0, NULL, gameVariables.character_flip);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.blueCrocodile, &spriteClips[gameVariables.enemy_frame],&localRects.rival_rect , 0, NULL, gameVariables.enemy_flip);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect1 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect2 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect3 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect4 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.ghost, &spriteClips[8],&localRects.ghost_rect5 , 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(gameTextures.renderer, gameTextures.gameOver, &spriteClips[11],&localRects.game_over, 0, NULL, SDL_FLIP_NONE);
        SDL_RenderPresent(gameTextures.renderer);
    }
}

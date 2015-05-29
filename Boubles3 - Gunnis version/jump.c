#include "main.h"
#include "jump.h"

void jump()
{
    int y;
    int status = SDL_TryLockMutex(jumpMutex);
    if (status == 0)
    {
        if(localRects.character_rect.y < 150)
        {
            for(y = 0; y < 20; y++)
            {
                localRects.character_rect.y -= 4;
                SDL_Delay(20);
            }
        }
        else
        {
            for(y = 0; y < 36; y++)
            {
                localRects.character_rect.y -= 4;
                SDL_Delay(20);
            }
        }

        SDL_UnlockMutex(jumpMutex);
    }
}

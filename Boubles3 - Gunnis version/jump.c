
#include "main.h"
#include "jump.h"
#include "dropFunction.h"

void jump()
{
    int y;
    int status = SDL_TryLockMutex(jumpMutex);
    if (status == 0)
    {
        printf("Jump mutex locked\n");
        for(y = 0; y < 40; y++)
        {
            gameVariables.character_rect.y -= 4;
            SDL_Delay(20);
        }
        SDL_UnlockMutex(jumpMutex);
    }
}

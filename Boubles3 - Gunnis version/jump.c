
#include "main.h"
#include "jump.h"
#include "dropFunction.h"

void jump()
{
    int x;
    int status = SDL_TryLockMutex(jumpMutex);
    if (status == 0)
    {
        printf("Jump mutex locked\n");
        for(x = 0; x < 35; x++)
        {
            gameRectangels.character_rect.y -= 4;
            SDL_Delay(20);
        }
        SDL_UnlockMutex(jumpMutex);
    }
}

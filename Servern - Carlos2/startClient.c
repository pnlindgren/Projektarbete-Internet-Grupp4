#include <stdio.h>
#include <stdbool.h>

#include "server_main.h"
#include "startClient.h"

int setPosition();

int startClient(recieved_Information *gameData)
{
    int charNr = setPosition();
    printf("%d\n", charNr);

}

int setPosition()
{
    int setNr;
    SDL_LockMutex(positionSetMutex);
        if(!client1Position)
        {
            setNr = rand()%2;
            client1Position = setNr + 1;
        }
        else
        {
            if(client1Position==1)
            {
                setNr = 1;
            }
            else
            {
                setNr = 0;
            }
        }
    SDL_UnlockMutex(positionSetMutex);

    return setNr;
}

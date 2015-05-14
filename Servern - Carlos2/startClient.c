#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "server_main.h"
#include "startClient.h"

int setPosition();

int startClient(recieved_Information *gameData)
{

    int positionNr = setPosition();//0 eller 1, slumpas och båda kan inte få samma

    int sendNumberX, sendNumberY;


    while(1)
    {
        sendNumberX=(rand()%999)+1;
        sendNumberY=(rand()%2);

        SDLNet_TCP_Send(csd[positionNr], gameData, sizeof(*gameData));

    }

}

/* Första klienten som nåt till mutexen får slumptal
0 eller 1, andra klienten får sin position baserat efter vad första klienten fick*/
int setPosition()
{
    int setNr;
    int x;
    SDL_LockMutex(positionSetMutex);

    if(!client1Position)//Flagga om det är första klienten som besöker den här
    {
        setNr = rand()%2;
        client1Position = setNr + 1;

    }
    else
    {
        //Andra klienten är igång, skickar även startpositioner till båda klienter
        setNr = client1Position % 2;//Motsatt till första klienten

        x = client1Position - 1;
        //SDLNet_TCP_Send(csd[0], &x, sizeof(int));

        x = client1Position % 2;
        //SDLNet_TCP_Send(csd[1], &x, sizeof(int));

    }

    SDL_UnlockMutex(positionSetMutex);

    return setNr;
}

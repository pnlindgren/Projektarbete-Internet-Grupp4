#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "server_main.h"
#include "startClient.h"

int setPosition();

int startClient(recieved_Information *gameData)
{

    int positionNr = setPosition();//0 eller 1, slumpas och b�da kan inte f� samma

    int sendNumberX, sendNumberY;


    while(1)
    {
        sendNumberX=(rand()%999)+1;
        sendNumberY=(rand()%2);

        SDLNet_TCP_Send(csd[positionNr], gameData, sizeof(*gameData));

    }

}

/* F�rsta klienten som n�t till mutexen f�r slumptal
0 eller 1, andra klienten f�r sin position baserat efter vad f�rsta klienten fick*/
int setPosition()
{
    int setNr;
    int x;
    SDL_LockMutex(positionSetMutex);

    if(!client1Position)//Flagga om det �r f�rsta klienten som bes�ker den h�r
    {
        setNr = rand()%2;
        client1Position = setNr + 1;

    }
    else
    {
        //Andra klienten �r ig�ng, skickar �ven startpositioner till b�da klienter
        setNr = client1Position % 2;//Motsatt till f�rsta klienten

        x = client1Position - 1;
        //SDLNet_TCP_Send(csd[0], &x, sizeof(int));

        x = client1Position % 2;
        //SDLNet_TCP_Send(csd[1], &x, sizeof(int));

    }

    SDL_UnlockMutex(positionSetMutex);

    return setNr;
}

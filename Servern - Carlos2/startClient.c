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

    rect_objects gameRectangles;

    int len = sizeof(gameRectangles);

    char serialiseradStruct[len];



    while(1)
    {
        SDLNet_TCP_Recv(csd[positionNr], &serialiseradStruct, len);
        memcpy(&gameRectangles, &serialiseradStruct, len);

        //printf("%d\n", gameRectangles.character_rect.x);

        if(positionNr == 0)
        {
            klientPositionX[0] = gameRectangles.character_rect.x;
            klientPositionY[0] = gameRectangles.character_rect.y;

            SDL_Delay(100);

            gameRectangles.rival_rect.x = klientPositionX[1];
            gameRectangles.rival_rect.y = klientPositionY[1];
        }
        else
        {
            klientPositionX[1] = gameRectangles.character_rect.x;
            klientPositionY[1] = gameRectangles.character_rect.y;

            SDL_Delay(100);

            gameRectangles.rival_rect.x = klientPositionX[0];
            gameRectangles.rival_rect.y = klientPositionY[0];

        }

        memcpy(&serialiseradStruct, &gameRectangles, len);

        SDLNet_TCP_Send(csd[positionNr],&serialiseradStruct,len);

        SDL_Delay(100);

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

        klientPositionX[0]=15;
        klientPositionY[0]=15;

        klientPositionX[1]= 300;
        klientPositionY[1]= 300;

        int sendInfo = 0;

        int len_int = sizeof(sendInfo)+1;
        SDLNet_TCP_Send(csd[0], &sendInfo, len_int);

    }
    else
    {
        //Andra klienten är igång, skickar även startpositioner till båda klienter
        setNr = client1Position % 2;//Motsatt till första klienten

        x = client1Position - 1;
        //SDLNet_TCP_Send(csd[0], &x, sizeof(int));

        x = client1Position % 2;
        //SDLNet_TCP_Send(csd[1], &x, sizeof(int));

        int sendInfo = 1;


        int len_int = sizeof(sendInfo)+1;
        SDLNet_TCP_Send(csd[1], &sendInfo, len_int);

    }

    SDL_UnlockMutex(positionSetMutex);

    return setNr;
}

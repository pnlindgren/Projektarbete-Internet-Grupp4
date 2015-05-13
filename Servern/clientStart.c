#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "server_main.h"
#include "clientStart.h"

int clientStart()
{
    //Initiering
    transfer_Information transInfoReceived; // Karaktärernas Positioner i servern
    bool firstPosition;//För att välja start position med mutex
    TCPsocket csd;
    int len = sizeof(transInfo);
    int characterNR;


    SDL_mutex *positionSelectMutex;
    positionSelectMutex = SDL_CreateMutex();
    if(!positionSelectMutex)
    {
        printf("Failed to create positionSelectMutex");
        exit(EXIT_FAILURE);
    }


    if(!client1Initiated)
    {
        client1Initiated = true;//Flagga för server_main ska vänta tills detta är klart.
        csd = csd1;
        characterNR = 0;
        SDLNet_TCP_Send(csd, &position, sizeof(position) + 1);
    }
    else
    {
        csd = csd2;
        characterNR = 1;
        int secondPosition;
        if(position == 0)
        {
            secondPosition = 1;
        }
        else
        {
            secondPosition = 0;
        }
        SDLNet_TCP_Send(csd, &secondPosition, sizeof(secondPosition)+1);
    }



    while(true)
    {

        SDLNet_TCP_Send(csd, &transInfo, len);

        printf("Send success: %d\n", transInfo.character_rects[characterNR].x);

        SDLNet_TCP_Recv(csd, &transInfo, (len+1) );

        transInfo.character_rects[characterNR] = transInfoReceived.character_rects[0];

        printf("Recieve success: %d\n", transInfoReceived.character_rects[0].x);



        SDL_Delay(2000);

    }

    return;
}

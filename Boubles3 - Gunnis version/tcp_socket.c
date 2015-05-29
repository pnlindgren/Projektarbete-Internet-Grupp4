#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "tcp_socket.h"

void tcp_socket_connect(TCPsocket *socketPekare)
{
    char serverIP[20] = {0};
    int serverPort = 0;
    bool continueProgram = false;
    IPaddress ipaddress;

    printf("Welcome!\nEnter IP:");
    fgets(serverIP, sizeof(serverIP), stdin);
    printf("Enter port:");
    scanf("%d", &serverPort);

    if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

    SDLNet_ResolveHost(&ipaddress, serverIP, serverPort);

    if(!(*socketPekare = SDLNet_TCP_Open(&ipaddress)))
    {
        fprintf(stderr,"SDLNet_TCP_Open: %s\n", SDLNet_GetError());
    }
    else
    {
        printf("Connection success\n");
        continueProgram = true;
    }

    while(!continueProgram)
    {
        SDL_Delay(1000);
        printf("Not connected...\n");
    }
}

void clientConnection(TCPsocket *socketPekare)
{
    client_send_information clientSendData;
    client_recieve_information clientRecieveData;

    int len1,len2;
    len1 = sizeof(clientSendData);
    len2 = sizeof(clientRecieveData);
    char serialiseradStruct1[len1];
    char serialiseradStruct2[len2];

    while(1)
    {
        SDL_Delay(10);

        convertSend(&clientSendData);
        memcpy(&serialiseradStruct1, &clientSendData, len1);
        SDLNet_TCP_Send(*socketPekare, &serialiseradStruct1, len1);

        SDL_Delay(10);

        SDLNet_TCP_Recv(*socketPekare,&serialiseradStruct2,len2);
        memcpy(&clientRecieveData,&serialiseradStruct2,len2);
        convertRecieve(&clientRecieveData);
    }
}

int position_start_function(TCPsocket *socketPekare)
{
    int len, result, startPosition = 2;

    len = sizeof(startPosition) + 1;

    result=SDLNet_TCP_Recv(*socketPekare,&startPosition,len);
    if(result < len)
    {
        printf("Position start error: %s\n", SDLNet_GetError());
        // It may be good to disconnect sock because it is likely invalid now.
    }
    printf("%d\n", startPosition);

    return startPosition;
}

void convertSend(client_send_information *clientSendData)
{
    clientSendData->charX = localRects.character_rect.x;
    clientSendData->charY = localRects.character_rect.y;
    clientSendData->char_bubbleX = localRects.bubble_rect.x;
    clientSendData->char_bubbleY = localRects.bubble_rect.y;
    clientSendData->char_frame = gameVariables.character_frame;
    clientSendData->char_collision = gameVariables.character_collision;
    clientSendData->ghostFlag1 = gameVariables.ghostFlag1;
    clientSendData->ghostFlag2 = gameVariables.ghostFlag2;
    clientSendData->ghostFlag3 = gameVariables.ghostFlag3;
    clientSendData->ghostFlag4 = gameVariables.ghostFlag4;
    clientSendData->ghostFlag5 = gameVariables.ghostFlag5;
    clientSendData->end_game = gameVariables.end_game;
    clientSendData->char_flip = gameVariables.character_flip;
}

void convertRecieve(client_recieve_information *clientRecieveData)
{
    localRects.rival_rect.x = clientRecieveData->rivalX;
    localRects.rival_rect.y = clientRecieveData->rivalY;
    localRects.enemy_bubble.x = clientRecieveData->rival_bubbleX;
    localRects.enemy_bubble.y = clientRecieveData->rival_bubbleY;
    gameVariables.enemy_frame = clientRecieveData->rival_frame;
    gameVariables.enemy_flip = clientRecieveData->rival_flip;
    localRects.ghost_rect1.x = clientRecieveData->ghost1X;
    localRects.ghost_rect1.y = clientRecieveData->ghost1Y;
    localRects.ghost_rect2.x = clientRecieveData->ghost2X;
    localRects.ghost_rect2.y = clientRecieveData->ghost2Y;
    localRects.ghost_rect3.x = clientRecieveData->ghost3X;
    localRects.ghost_rect3.y = clientRecieveData->ghost3Y;
    localRects.ghost_rect4.x = clientRecieveData->ghost4X;
    localRects.ghost_rect4.y = clientRecieveData->ghost4Y;
    localRects.ghost_rect5.x = clientRecieveData->ghost5X;
    localRects.ghost_rect5.y = clientRecieveData->ghost5Y;
    gameVariables.ghostHit = clientRecieveData->ghostHit;
}

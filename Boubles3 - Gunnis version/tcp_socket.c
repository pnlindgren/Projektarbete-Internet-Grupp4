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
        fprintf(stderr,"SDLNet_TCP_Open: %s \n", SDLNet_GetError());
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
    int len,result;

    send_information klient_send;

    while(1)
    {
        klient_send.the_bubble = bubble_rect;
        klient_send.the_character = character_rect;

        len = sizeof(klient_send) + 1;

        result=SDLNet_TCP_Send(*socketPekare,&klient_send,len);
        if(result < len)
        {
            printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
            // It may be good to disconnect sock because it is likely invalid now.
        }

        SDL_Delay(100);
    }
}








int position_start_function(TCPsocket *socketPekare)
{
    int len, result, startPosition = 2;

    len = sizeof(startPosition) + 1;

    //result=SDLNet_TCP_Send(*socketPekare,&klient_send,len);
    if(result < len)
    {
        printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
        // It may be good to disconnect sock because it is likely invalid now.
    }

    SDL_Delay(100);
}

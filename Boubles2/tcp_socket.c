#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

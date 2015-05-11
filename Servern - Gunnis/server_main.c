#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "SDL_net.h"
#include "server_main.h"
#include "enemy_Server.h"
#include "main.h"

send_information sendInfo;
SDL_Rect left_wall;
SDL_Rect right_wall;

int main(int argc, char **argv)
{
    srand(time(NULL));

    SDL_Thread *enemy;

    sendInfo.ghostRect.x = 250;
    sendInfo.ghostRect.y = 97;
    sendInfo.ghostRect.w = 50;
    sendInfo.ghostRect.h = 50;

    sendInfo.character_rects[1].x = 250;
    sendInfo.character_rects[1].y = 0;
    sendInfo.character_rects[1].w = 50;
    sendInfo.character_rects[1].h = 50;

    sendInfo.character_rects[0].x = 0;  // ska bort
    sendInfo.character_rects[0].y = 0;  // ska bort
    sendInfo.character_rects[0].w = 0;  // ska bort
    sendInfo.character_rects[0].h = 0;  // ska bort

    left_wall.x = 0;
    left_wall.y = 0;
    left_wall.w = 16;
    left_wall.h = 480;

    right_wall.x = 622;
    right_wall.y = 0;
    right_wall.w = 16;
    right_wall.h = 480;

    enemy = SDL_CreateThread(nextMove, "enemyThread", (void *)NULL);









	TCPsocket sd, csd; /* Socket descriptor, Client socket descriptor */
	IPaddress ip, *remoteIP;
	int quit, quit2, len, len2, position = rand() % 2;
	char buffer[512];

	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	/* Resolving the host using NULL make network interface to listen */
	if (SDLNet_ResolveHost(&ip, NULL, 2000) < 0)
	{
		fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	/* Open a connection with the IP provided (listen on the host's port) */
	if (!(sd = SDLNet_TCP_Open(&ip)))
	{
		fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	/* Wait for a connection, send data and term */
	quit = 0;
	while (!quit)
	{
		/* This check the sd if there is a pending connection.
		* If there is one, accept that, and open a new socket for communicating */
		if ((csd = SDLNet_TCP_Accept(sd)))
		{
			/* Now we can communicate with the client using csd socket
			* sd will remain opened waiting other connections */

			/* Get the remote address */
			if ((remoteIP = SDLNet_TCP_GetPeerAddress(csd)))
				/* Print the address, converting in the host format */
				printf("Host connected: %x %d\n", SDLNet_Read32(&remoteIP->host), SDLNet_Read16(&remoteIP->port));
			else
				fprintf(stderr, "SDLNet_TCP_GetPeerAddress: %s\n", SDLNet_GetError());

			quit2 = 0;
			len = sizeof(position) + 1;

			if (SDLNet_TCP_Send(csd, &position, len) > 0)
            {
                printf("Position success");
            }

            len2 = sizeof(sendInfo);
			while (!quit2)
			{
				if (SDLNet_TCP_Send(csd, &sendInfo, len2) > 0)
				{
					/*if(strcmp(buffer, "exit") == 0)	// Terminate this connection
					{
						quit2 = 1;
						printf("Terminate connection\n");
					}
					if(strcmp(buffer, "quit") == 0)	// Quit the program
					{
						quit2 = 1;
						quit = 1;
						printf("Quit program\n");
					}*/
                    SDL_Delay(100);
				}
			}

			/* Close the client socket */
			SDLNet_TCP_Close(csd);
		}
	}

	SDLNet_TCP_Close(sd);
	SDLNet_Quit();

	return EXIT_SUCCESS;
}

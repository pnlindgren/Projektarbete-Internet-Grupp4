#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "SDL.h"
#include "SDL_net.h"
#include "server_main.h"
#include "gameStart.h"
#include "clientStart.h"

void clientInitiate(void *pointer);

bool gameOver;
TCPsocket csd1, csd2;
bool client1Initiated;
transfer_Information transInfo;

int position;

int main(int argc, char **argv)
{
    srand(time(NULL));
    position = rand()%2;
    //Initiering
	TCPsocket sd, csd; /* Socket descriptor, Client socket descriptor */
	IPaddress ip, *remoteIP;
	int quit, quit2;
	char buffer[512];
    bool oneConnectedClient = false;
    bool twoConnectedClient = false;
    bool startGame = false;
    //firstPosition = false;
    SDL_Thread *client1Thread, *client2Thread, *gameThread;

    transInfo.character_rects[0].x = 0;
    transInfo.character_rects[0].y = 0;
    transInfo.character_rects[0].h = 50;
    transInfo.character_rects[0].w = 50;

    transInfo.character_rects[1].x = 400;
    transInfo.character_rects[1].y = 0;
    transInfo.character_rects[1].h = 50;
    transInfo.character_rects[1].w = 50;

    transInfo.ghostRect.x = 350;
    transInfo.ghostRect.y = 350;
    transInfo.ghostRect.h = 50;
    transInfo.ghostRect.w = 50;



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
	gameOver = false;//Global
	while (!quit)
	{
		/* This check the sd if there is a pending connection.
		* If there is one, accept that, and open a new socket for communicating */
		if ((csd1 = SDLNet_TCP_Accept(sd))&&!oneConnectedClient)
		{
			oneConnectedClient = true;
			/* Now we can communicate with the client using csd socket
			* sd will remain opened waiting other connections */


			/* Get the remote address */
			if ((remoteIP = SDLNet_TCP_GetPeerAddress(csd1)))
            {
                /* Print the address, converting in the host format */
				printf("Host connected: %x %d\n", SDLNet_Read32(&remoteIP->host), SDLNet_Read16(&remoteIP->port));
            }
			else
            {
                fprintf(stderr, "SDLNet_TCP_GetPeerAddress: %s\n", SDLNet_GetError());
            }
            client1Initiated = false;
            client1Thread = SDL_CreateThread(clientStart, "One client", (void*)NULL);

            while(!client1Initiated)
            {
                //Väntar på att första klienten initierats i clientStart
            }


            if(oneConnectedClient)
            {

                //Vänta på klient 2
                quit2 = 0;

                while(!twoConnectedClient)
                {

                    if(csd2 = SDLNet_TCP_Accept((sd)))
                    {
                        twoConnectedClient = true;
                        if ((remoteIP = SDLNet_TCP_GetPeerAddress(csd2)))
                        {
                            /* Print the address, converting in the host format */
                            printf("Host connected: %x %d\n", SDLNet_Read32(&remoteIP->host), SDLNet_Read16(&remoteIP->port));
                            twoConnectedClient = true;


                        }
                        else
                        {
                            fprintf(stderr, "SDLNet_TCP_GetPeerAddress: %s\n", SDLNet_GetError());
                        }
                        client2Thread = SDL_CreateThread(clientStart, "Two clients", (void*)NULL);

                        // SDL_Delay(100); /* Kanske bör vänta ett ögonblick på något sätt så att clienterna startar samtidigt
                        gameThread = SDL_CreateThread(gameStart, "Game start", (void*)NULL);

                    }
                }
            }

            //SDL_Delay(5000);
			/* Close the client socket */
			//SDLNet_TCP_Close(csd);

		}
	}

	SDLNet_TCP_Close(sd);
	SDLNet_Quit();

	return EXIT_SUCCESS;
}

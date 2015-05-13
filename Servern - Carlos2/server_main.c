#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "SDL.h"
#include "SDL_net.h"
#include "server_main.h"
#include "initFunctions.h"
#include "startClient.h"

void waitForClients(TCPsocket *sd, TCPsocket *csd1, TCPsocket *csd2);

SDL_mutex *positionSetMutex;
bool firstPosition;//Används i startClient vid init av startposition
int client1Position;

int main(int argc, char **argv)
{
    srand(time(NULL));
	TCPsocket sd, csd, csd1, csd2; // Socket descriptor, Client socket descriptor
	IPaddress ip, *remoteIP;
	int quit, quit2;
	char buffer[512];
	bool clientInitiated;

	firstPosition = false;
	client1Position = 0;

	SDL_Thread *client1, *client2;
    recieved_Information *gameData;

    positionSetMutex = SDL_CreateMutex();
    if(!positionSetMutex)
    {
        printf("Error: Cannot create mutex");
        return 0;
    }
	initFunctions(&ip, &sd); //Initiera TCP för SDL

	waitForClients(&sd, &csd1, &csd2); // Väntar på 2 st klienter ska koppla upp sig
    client1 = SDL_CreateThread(startClient, "Client1", gameData);
    client2 = SDL_CreateThread(startClient, "Client1", gameData);
    while(true)
    {

    }

	SDLNet_TCP_Close(sd);
	SDLNet_Quit();

	return EXIT_SUCCESS;
}

void waitForClients(TCPsocket *sd, TCPsocket *csd1, TCPsocket *csd2)
{
    bool quit = false, quit2 = false;
    bool connectedClient = false;
    printf("Waiting for connection\n");
    while (!quit)
	{
		// This check the sd if there is a pending connection.
		// If there is one, accept that, and open a new socket for communicating

		//Väntar på klienter

		if ((csd1 = SDLNet_TCP_Accept(*sd)))
		{
		    printf("Client 1 connected.\n");
			//clientInitiated = initiateClient();
			quit = true;
			while(!quit2)
            {
                if((csd2 = SDLNet_TCP_Accept(*sd)))
                {
                    printf("Client 2 connected.\n");
                    quit2 = true;
                }
            }
        }
    }
}

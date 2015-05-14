#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "SDL.h"
#include "SDL_net.h"
#include "server_main.h"
#include "initFunctions.h"
#include "startClient.h"

void waitForClients(TCPsocket *sd);

SDL_mutex *positionSetMutex;
bool firstPosition;//Används i startClient vid init av startposition
int client1Position;
int clientNr; //För at hålla koll på vilken klient som har vilken socket öppen

TCPsocket sd, csd[2]; // Socket descriptor, Client socket descriptor

int main(int argc, char **argv)
{
    srand(time(NULL));

	IPaddress ip, *remoteIP;
	int quit, quit2;
	char buffer[512];
	bool clientInitiated;

	firstPosition = false;
	client1Position = 0;

	SDL_Thread *client1, *client2;

    recieved_Information gameData;
    gameData.character_rects[0].x=123;
    gameData.character_rects[0].y=321;
    gameData.character_rects[0].w=111;
    gameData.character_rects[0].h=222;

    gameData.character_rects[1].x=456;
    gameData.character_rects[1].y=654;
    gameData.character_rects[1].w=333;
    gameData.character_rects[1].h=444;

    gameData.ghostRect.x=789;
    gameData.ghostRect.x=789;
    gameData.ghostRect.w=777;
    gameData.ghostRect.h=888;


    positionSetMutex = SDL_CreateMutex();
    if(!positionSetMutex)
    {
        printf("Error: Cannot create mutex");
        return 0;
    }
	initFunctions(&ip, &sd); //Initiera TCP för SDL

	waitForClients(&sd); // Väntar på 2 st klienter ska koppla upp sig
    client1 = SDL_CreateThread(startClient, "Client1", &gameData);
    client2 = SDL_CreateThread(startClient, "Client1", &gameData);
    while(true)
    {

    }

	SDLNet_TCP_Close(sd);
	SDLNet_Quit();

	return EXIT_SUCCESS;
}

void waitForClients(TCPsocket *sd)
{
    bool quit = false, quit2 = false;
    bool connectedClient = false;
    printf("Waiting for connection\n");

    while (!quit)
	{
		// This check the sd if there is a pending connection.
		// If there is one, accept that, and open a new socket for communicating

		//Väntar på klienter

		if ((csd[0] = SDLNet_TCP_Accept(*sd)))
		{
		    printf("Client 1 connected.\n");
			//clientInitiated = initiateClient();
			quit = true;

			while(!quit2)
            {
                if((csd[1] = SDLNet_TCP_Accept(*sd)))
                {
                    printf("Client 2 connected.\n");
                    quit2 = true;
                }

            }

        }

    }
}

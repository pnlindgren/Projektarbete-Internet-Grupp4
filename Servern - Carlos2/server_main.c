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
#include "enemy_server.h"

void waitForClients(TCPsocket *sd);

SDL_mutex *positionSetMutex;

bool firstPosition;//Anv�nds i startClient vid init av startposition
int client1Position;
int clientNr; //F�r at h�lla koll p� vilken klient som har vilken socket �ppen

int klientPositionX[2];
int klientPositionY[2];

int bubbleX = 1000;
int bubbleY = 1000;

bool bubble_view = false;

int frame[2];
SDL_RendererFlip flip[2];
SDL_Rect ghostRect1;
SDL_Rect ghostRect2;
SDL_Rect ghostRect3;
SDL_Rect ghostRect4;
SDL_Rect ghostRect5;
SDL_Rect r3p1v;         // rad 3 platform 1 v�nstersida (finns 4 rader (0,1,2,3))
SDL_Rect r3p1h;
SDL_Rect r2p0v;
SDL_Rect r2p0h;

TCPsocket sd, csd[2]; // Socket descriptor, Client socket descriptor

int main(int argc, char **argv)
{
    srand(time(NULL));

    r3p1v.x = 180;
    r3p1v.y = 97;
    r3p1v.w = 16;
    r3p1v.h = 50;

    r3p1h.x = 440;
    r3p1h.y = 97;
    r3p1h.w = 16;
    r3p1h.h = 50;

    r2p0v.x = 0;
    r2p0v.y = 195;
    r2p0v.w = 16;
    r2p0v.h = 50;

    r2p0h.x = 270;
    r2p0h.y = 195;
    r2p0h.w = 16;
    r2p0h.h = 50;

    ghostRect1.x = 300;
    ghostRect1.y = 97;
    ghostRect1.w = 50;
    ghostRect1.h = 50;

    ghostRect2.x = 50;
    ghostRect2.y = 195;
    ghostRect2.w = 50;
    ghostRect2.h = 50;

    ghostRect3.x = 500;
    ghostRect3.y = 195;
    ghostRect3.w = 50;
    ghostRect3.h = 50;

    ghostRect4.x = 300;
    ghostRect4.y = 297;
    ghostRect4.w = 50;
    ghostRect4.h = 50;

    ghostRect5.x = 400;
    ghostRect5.y = 415;
    ghostRect5.w = 50;
    ghostRect5.h = 50;

	IPaddress ip, *remoteIP;
	int quit, quit2;
	char buffer[512];
	bool clientInitiated;

	firstPosition = false;
	client1Position = 0;

	SDL_Thread *client1, *client2, *enemy1, *enemy2;

    positionSetMutex = SDL_CreateMutex();
    if(!positionSetMutex)
    {
        printf("Error: Cannot create mutex");
        return 0;
    }
	initFunctions(&ip, &sd); //Initiera TCP f�r SDL

	waitForClients(&sd); // V�ntar p� 2 st klienter ska koppla upp sig
    enemy1 = SDL_CreateThread(nextMove, "ghost1", &ghostRect1);
    enemy2 = SDL_CreateThread(nextMove, "ghost1", &ghostRect2);
    client1 = SDL_CreateThread(startClient, "Client1", (void *)NULL);
    client2 = SDL_CreateThread(startClient, "Client2", (void *)NULL);
    while(true)
    {
        SDL_Delay(100);
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

		//V�ntar p� klienter

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

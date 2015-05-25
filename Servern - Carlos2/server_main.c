#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_net.h"
#include "server_main.h"
#include "initFunctions.h"
#include "startClient.h"
#include "enemy_Server.h"

void waitForClients(TCPsocket *sd);
void resetVariables();

SDL_mutex *positionSetMutex, *ghostHitMutex;

bool firstPosition;//Används i startClient vid init av startposition
int client1Position;
int clientNr; //För at hålla koll på vilken klient som har vilken socket öppen

int klientPositionX[2];
int klientPositionY[2];

SDL_Rect bubble[2];

int frame[2];
SDL_RendererFlip flip[2];

SDL_Rect ghostRect1;
SDL_Rect ghostRect2;
SDL_Rect ghostRect3;
SDL_Rect ghostRect4;
SDL_Rect ghostRect5;

SDL_Rect r3p1v;         // rad 3 platform 1 vänstersida (finns 4 rader (0,1,2,3))
SDL_Rect r3p1h;
SDL_Rect r2p0v;
SDL_Rect r2p0h;
SDL_Rect r2p1v;
SDL_Rect r2p1h;
SDL_Rect r1p1v;
SDL_Rect r1p1h;
SDL_Rect r0p0v;
SDL_Rect r0p0h;

// ghostHitCount håller koll på hur många spöken som har blivit träffade
int ghostHitCount;
bool ghostHitFlag[5];
bool gameOver;

TCPsocket sd, csd[2]; // Socket descriptor, Client socket descriptor

int main(int argc, char **argv)
{
    srand(time(NULL));

    gameOver = true;

    ghostHitCount = 0;

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

    r2p1v.x = 370;
    r2p1v.y = 195;
    r2p1v.w = 16;
    r2p1v.h = 50;

    r2p1h.x = 622;
    r2p1h.y = 195;
    r2p1h.w = 16;
    r2p1h.h = 50;

    r1p1v.x = 190;
    r1p1v.y = 297;
    r1p1v.w = 16;
    r1p1v.h = 50;

    r1p1h.x = 450;
    r1p1h.y = 297;
    r1p1h.w = 16;
    r1p1h.h = 50;

    r0p0v.x = 0;
    r0p0v.y = 415;
    r0p0v.w = 16;
    r0p0v.h = 50;

    r0p0h.x = 622;
    r0p0h.y = 415;
    r0p0h.w = 16;
    r0p0h.h = 50;

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
	//client1Position = 0;

	SDL_Thread *client1, *client2, *enemy1, *enemy2, *enemy3, *enemy4, *enemy5;

    positionSetMutex = SDL_CreateMutex();
    ghostHitMutex = SDL_CreateMutex();
    if(!positionSetMutex)
    {
        printf("Error: Cannot create mutex");
        return 0;
    }
    if(!ghostHitMutex)
    {
        printf("Error: Cannot create ghost mutex");
        return 0;
    }
	initFunctions(&ip, &sd); //Initiera TCP för SDL

	//waitForClients(&sd); // Väntar på 2 st klienter ska koppla upp sig
    enemy1 = SDL_CreateThread(nextMove, "ghost1", &ghostRect1);
    enemy2 = SDL_CreateThread(nextMove, "ghost1", &ghostRect2);
    enemy3 = SDL_CreateThread(nextMove, "ghost1", &ghostRect3);
    enemy4 = SDL_CreateThread(nextMove, "ghost1", &ghostRect4);
    enemy5 = SDL_CreateThread(nextMove, "ghost1", &ghostRect5);
    //client1 = SDL_CreateThread(startClient, "Client1", (void *)NULL);
    //client2 = SDL_CreateThread(startClient, "Client2", (void *)NULL);
    while(true)
    {
        if(gameOver == true)
        {
                waitForClients(&sd); // Väntar på 2 st klienter ska koppla upp sig
                resetVariables();
                gameOver = false;
                client1Position = 0;
                client1 = SDL_CreateThread(startClient, "Client1", (void *)NULL);
                client2 = SDL_CreateThread(startClient, "Client2", (void *)NULL);
        }

        SDL_Delay(1000);
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

void resetVariables()
{
    gameOver = false;
    client1Position = 0;
    ghostHitCount = 0;

    ghostRect1.x = 300;
    ghostRect1.y = 97;

    ghostRect2.x = 50;
    ghostRect2.y = 195;

    ghostRect3.x = 500;
    ghostRect3.y = 195;

    ghostRect4.x = 300;
    ghostRect4.y = 297;

    ghostRect5.x = 400;
    ghostRect5.y = 415;

    ghostHitFlag[0] = false;
    ghostHitFlag[1] = false;
    ghostHitFlag[2] = false;
    ghostHitFlag[3] = false;
    ghostHitFlag[4] = false;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define SOCK_PATH "/tmp/echo_socket"
#define FILE_NAME "/home/carlos/pid/startdem.pid"
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define READ 0
#define WRITE 1
#define ERROR 2

#include "SDL2/SDL.h"
#include "SDL2/SDL_net.h"
#include "server_main.h"
#include "initFunctions.h"
#include "startClient.h"
#include "enemy_Server.h"

void waitForClients(TCPsocket *sd);
void resetVariables();
static void daemonize(void); // baserat p� http://www.ics.uzh.ch/~dpotter/howto/daemonize
void storepid();

SDL_mutex *positionSetMutex, *ghostHitMutex;

bool firstPosition;//Anv�nds i startClient vid init av startposition
int client1Position;
int clientNr; //F�r at h�lla koll p� vilken klient som har vilken socket �ppen

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

SDL_Rect r3p1v;         // rad 3 platform 1 v�nstersida (finns 4 rader (0,1,2,3))
SDL_Rect r3p1h;
SDL_Rect r2p0v;
SDL_Rect r2p0h;
SDL_Rect r2p1v;
SDL_Rect r2p1h;
SDL_Rect r1p1v;
SDL_Rect r1p1h;
SDL_Rect r0p0v;
SDL_Rect r0p0h;

// ghostHitCount h�ller koll p� hur m�nga sp�ken som har blivit tr�ffade
int ghostHitCount;
bool ghostHitFlag[5];
bool gameOver;

TCPsocket sd, csd[2]; // Socket descriptor, Client socket descriptor

int main(int argc, char **argv)
{
    daemonize();
    storepid();//Lagra pid nummer f�r att kunna st�nga med stop-skript
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

	SDL_Thread *client1, *client2, *enemy1, *enemy2, *enemy3, *enemy4, *enemy5;

    positionSetMutex = SDL_CreateMutex();
    ghostHitMutex = SDL_CreateMutex();
    if(!positionSetMutex)
    {
        return 0;
    }
    if(!ghostHitMutex)
    {
        return 0;
    }
	initFunctions(&ip, &sd); //Initiera TCP f�r SDL

    enemy1 = SDL_CreateThread(nextMove, "ghost1", &ghostRect1);
    enemy2 = SDL_CreateThread(nextMove, "ghost1", &ghostRect2);
    enemy3 = SDL_CreateThread(nextMove, "ghost1", &ghostRect3);
    enemy4 = SDL_CreateThread(nextMove, "ghost1", &ghostRect4);
    enemy5 = SDL_CreateThread(nextMove, "ghost1", &ghostRect5);

    while(true)
    {
        if(gameOver == true)
        {
                waitForClients(&sd); // V�ntar p� 2 st klienter ska koppla upp sig
                resetVariables();
                gameOver = false;
                client1Position = 0;
                client1 = SDL_CreateThread(startClient, "Client1", (void *)NULL);
                client2 = SDL_CreateThread(startClient, "Client2", (void *)NULL);
                SDL_DetachThread(client1); // Förhindrar att tråden tar upp minne efter att den stänger ner
                SDL_DetachThread(client2);

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
    //printf("Waiting for connection\n");

    while (!quit)
	{

		//V�ntar p� klienter

		if ((csd[0] = SDLNet_TCP_Accept(*sd)))
		{
			quit = true;

			while(!quit2)
            {
                if((csd[1] = SDLNet_TCP_Accept(*sd)))
                {
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

// Baserat p� http://www.ics.uzh.ch/~dpotter/howto/daemonize
static void daemonize(void)
{
    pid_t pid, sid;

    /* already a daemon */
    if ( getppid() == 1 ) return;

    /* Fork off the parent process */
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    /* If we got a good PID, then we can exit the parent process. */
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    /* At this point we are executing as the child process */

    /* Change the file mode mask */
    umask(0);

    /* Create a new SID for the child process */
    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    /* Change the current working directory.  This prevents the current
       directory from being locked; hence not being able to remove it. */
    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }

    /* Redirect standard files to /dev/null */
    freopen( "/dev/null", "r", stdin);
    freopen( "/dev/null", "w", stdout);
    freopen( "/dev/null", "w", stderr);
}

// Lagrar pid nummret i h�rddisken f�r att senare kunna stoppa den med stopscript
void storepid()
{
    pid_t pid;
    pid = getpid();
    FILE *fp;
    fp = fopen(FILE_NAME, "w");
    if(fp == NULL)
    {
        perror("Open pidfile.");
        exit(1);
    }
    fprintf(fp, "%d", pid);
    fclose(fp);
}

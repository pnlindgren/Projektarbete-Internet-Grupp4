#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "initFunctions.h"
#include "close.h"
#include "keyInput.h"
#include "position.h"
#include "keyInput2.h"
#include "screenUpdater.h"
#include "wallDetector.h"
#include "dropFunction.h"
#include "tcp_socket.h"
#include "clientFunctions.h"

SDL_Surface* loadSurface(char path[100]);       // Beh�vs
SDL_Window*  gWindow = NULL;                    // Beh�vs
SDL_Surface* gScreenSurface = NULL;             // Beh�vs
SDL_Surface* gBackground = NULL;                // Beh�vs
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gCurrentSurface = NULL;

SDL_Surface* gEnemySurface = NULL;

// Nytt *******************************************************

SDL_Renderer* gRenderer = NULL;
SDL_Texture* mBlueCrocodile = NULL;
SDL_Texture* mBackground = NULL;
SDL_Texture* mGhost = NULL;
SDL_Texture* mWall = NULL;
SDL_Texture* mBubble = NULL;

SDL_Rect gSpriteClips[13];

SDL_Rect character_rect;
SDL_Rect background_rect;
SDL_Rect ghost_rect;
SDL_Rect wall_rect;
SDL_Rect left_wall;
SDL_Rect right_wall;
SDL_Rect bubble_rect;

SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

TCPsocket socket;

int frame = 3;  // vilken frame bl�a krokodilen b�rjar p�
bool characterCollision = false;
bool bubble_view = false;
int ghosthit = 0;

// Nytt *******************************************************

int main(int argc, char * argv[])
{
    TCPsocket *socketPekare;
    socketPekare = &socket;

   // tcp_socket_connect(socketPekare);

    SDL_Thread *enemy;
    SDL_Thread *updateScreen;
    SDL_Thread *dropGravitation;
    SDL_Thread *serverInformation;

    if(initBuild()) // Om init och loadmedia fungerar k�rs programmet
    {
       // serverInformation = SDL_CreateThread(clientConnection, "clientConnection", socketPekare);

        updateScreen = SDL_CreateThread(screenUpdateFunction, "updateThread", (void *)NULL);

        dropGravitation = SDL_CreateThread(dropFunction, "dropThread", (void*)NULL);

        enemy = SDL_CreateThread(nextMove, "enemyThread", (void *)NULL);

        keyInput2(); // Funktion f�r att ta hand om knapptryckningar
    }

    close1();       // funktion f�r att st�nga av programmet med r�da krysset

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "initFunctions.h"
#include "close.h"
#include "enemy.h"
#include "keyInput2.h"
#include "screenUpdater.h"
#include "dropFunction.h"
#include "tcp_socket.h"
#include "collisionHandler.h"

SDL_Window*  gWindow = NULL;

textures gameTextures;

SDL_Rect gSpriteClips[13];

game_objects gameVariables;

int main(int argc, char * argv[])
{
    int positionStart = 2;

    gameVariables.frame = 3;
    gameVariables.bubble_view = false;
    gameVariables.enemy_flip = SDL_FLIP_NONE;
    gameVariables.character_flip = SDL_FLIP_NONE;
    gameVariables.ghosthit = 0;
    gameVariables.characterCollision = false;

    SDL_Thread *enemy;
    SDL_Thread *updateScreen;
    SDL_Thread *dropGravitation;
    SDL_Thread *serverInformation;

    TCPsocket socket;
    TCPsocket *socketPekare;
    socketPekare = &socket;

    tcp_socket_connect(socketPekare);
    positionStart = position_start_function(socketPekare);

    if(initBuild(positionStart)) // Om init och loadmedia fungerar körs programmet
    {
        serverInformation   = SDL_CreateThread(clientConnection, "clientConnection", socketPekare);
        updateScreen        = SDL_CreateThread(screenUpdateFunction, "updateThread", (void *)NULL);
        dropGravitation     = SDL_CreateThread(dropFunction, "dropThread", (void*)NULL);
        enemy               = SDL_CreateThread(enemyCollision, "enemyCollision", (void*)NULL);

        keyInput2(); // Funktion för att ta hand om knapptryckningar
    }

    close1();       // funktion för att stänga av programmet med röda krysset

    return 0;
}

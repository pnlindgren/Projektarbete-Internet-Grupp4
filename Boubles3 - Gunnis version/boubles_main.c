#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "initFunctions.h"
#include "close.h"
#include "keyInput.h"
#include "screenUpdater.h"
#include "dropFunction.h"
#include "tcp_socket.h"
#include "collisionHandler.h"

SDL_Window*  gameWindow = NULL;

textures gameTextures;

SDL_Rect spriteClips[13];

game_objects gameVariables;
local_rect_objects localRects;

int main(int argc, char * argv[])
{
    int positionStart = -1;

    gameVariables.character_frame = 3;
    gameVariables.ghostHit = 0;
    gameVariables.enemy_flip = SDL_FLIP_NONE;
    gameVariables.character_flip = SDL_FLIP_NONE;
    gameVariables.character_collision = false;
    gameVariables.end_game = false;
    gameVariables.bubble_view = false;

    gameVariables.ghostFlag1 = false;
    gameVariables.ghostFlag2 = false;
    gameVariables.ghostFlag3 = false;
    gameVariables.ghostFlag4 = false;
    gameVariables.ghostFlag5 = false;

    SDL_Thread *enemyCThread;
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
        enemyCThread        = SDL_CreateThread(enemyCollision, "enemyCollision", (void*)NULL);

        backgroundMusic();
        keyInput(positionStart); // Funktion för att ta hand om knapptryckningar
    }

    closeProgram();       // funktion för att stänga av programmet med röda krysset

    return 0;
}

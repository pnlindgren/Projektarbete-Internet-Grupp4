#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "server_main.h"
#include "startClient.h"

int setPosition();

int startClient(void * pointer)
{
    //0 eller 1, slumpas och båda kan inte få samma
    int positionNr = setPosition();

    // Spelvariabler som ska uppdateras
    game_objects gameVariables;

    // längden på structen som sedan ska skickas (structens längd är samma som den serialiserade structen)
    int len = sizeof(gameVariables);

    // Serialiseradestructen kopierar varje bit med memcpy
    char serialiseradStruct[len];

    while(!gameOver)
    {
        SDLNet_TCP_Recv(csd[positionNr], &serialiseradStruct, len);
        memcpy(&gameVariables, &serialiseradStruct, len);

        SDL_LockMutex(ghostHitMutex);
        if(gameVariables.ghost_rect1.x == 0 && gameVariables.ghost_rect1.y == 600 && ghostHitFlag[0] == false)
        {
            ghostRect1.x = 0;
            ghostRect1.y = 600;
            ghostHitCount++;
            ghostHitFlag[0] = true;
        }

        else if(gameVariables.ghost_rect2.x == 0 && gameVariables.ghost_rect2.y == 600 && ghostHitFlag[1] == false)
        {
            ghostRect2.x = 0;
            ghostRect2.y = 600;
            ghostHitCount++;
            ghostHitFlag[1] = true;
        }

        else if(gameVariables.ghost_rect3.x == 0 && gameVariables.ghost_rect3.y == 600 && ghostHitFlag[2] == false)
        {
            ghostRect3.x = 0;
            ghostRect3.y = 600;
            ghostHitCount++;
            ghostHitFlag[2] = true;
        }

        else if(gameVariables.ghost_rect4.x == 0 && gameVariables.ghost_rect4.y == 600 && ghostHitFlag[3] == false)
        {
            ghostRect4.x = 0;
            ghostRect4.y = 600;
            ghostHitCount++;
            ghostHitFlag[3] = true;
        }

        else if(gameVariables.ghost_rect5.x == 0 && gameVariables.ghost_rect5.y == 600 && ghostHitFlag[4] == false)
        {
            ghostRect5.x = 0;
            ghostRect5.y = 600;
            ghostHitCount++;
            ghostHitFlag[4] = true;
        }

        gameVariables.ghost_rect1 = ghostRect1;
        gameVariables.ghost_rect2 = ghostRect2;
        gameVariables.ghost_rect3 = ghostRect3;
        gameVariables.ghost_rect4 = ghostRect4;
        gameVariables.ghost_rect5 = ghostRect5;

        gameVariables.ghosthit = ghostHitCount;

        SDL_UnlockMutex(ghostHitMutex);

        // Båda trådarna kommer nu ha uppdaterat sina bubblor vilket tillåter servern sedan
        // att ändra enemy_bubble
        bubble[positionNr] = gameVariables.bubble_rect;

        frame[positionNr] = gameVariables.frame;
        flip[positionNr] = gameVariables.character_flip;

        SDL_Delay(10);

        // klient 1
        if(positionNr == 0)
        {
            klientPositionX[0] = gameVariables.character_rect.x;
            klientPositionY[0] = gameVariables.character_rect.y;

            gameVariables.rival_rect.x = klientPositionX[1];
            gameVariables.rival_rect.y = klientPositionY[1];

            gameVariables.enemy_frame = frame[1];
            gameVariables.enemy_flip = flip[1];

            gameVariables.enemy_bubble = bubble[1];
        }
        // klient 2
        else
        {
            klientPositionX[1] = gameVariables.character_rect.x;
            klientPositionY[1] = gameVariables.character_rect.y;

            gameVariables.rival_rect.x = klientPositionX[0];
            gameVariables.rival_rect.y = klientPositionY[0];

            gameVariables.enemy_frame = frame[0];
            gameVariables.enemy_flip = flip[0];

            gameVariables.enemy_bubble = bubble[0];
        }

        memcpy(&serialiseradStruct, &gameVariables, len);
        SDLNet_TCP_Send(csd[positionNr],&serialiseradStruct,len);

        SDL_Delay(10);

        if(ghostHitCount == 5)
        {
            SDLNet_TCP_Recv(csd[positionNr], &serialiseradStruct, len);
            memcpy(&gameVariables, &serialiseradStruct, len);

            gameVariables.ghosthit = 5;
            ghostRect1.y = 600;
            ghostRect2.y = 600;
            ghostRect3.y = 600;
            ghostRect4.y = 600;
            ghostRect5.y = 600;

            memcpy(&serialiseradStruct, &gameVariables, len);
            SDLNet_TCP_Send(csd[positionNr],&serialiseradStruct,len);

            SDLNet_TCP_Close(csd[positionNr]);
            SDL_Delay(1000);
            gameOver = true;
        }
    }

    return 0;
}

/* Första klienten som nåt till mutexen får slumptal
0 eller 1, andra klienten får sin position baserat efter vad första klienten fick*/
int setPosition()
{
    int setNr;
    int x;
    SDL_LockMutex(positionSetMutex);

    if(!client1Position)//Flagga om det är första klienten som besöker den här
    {
        setNr = rand()%2;
        client1Position = setNr + 1;

        klientPositionX[0]=15;
        klientPositionY[0]=15;

        klientPositionX[1]= 300;
        klientPositionY[1]= 300;

        int sendInfo = 0;

        int len_int = sizeof(sendInfo)+1;

        SDLNet_TCP_Send(csd[0], &sendInfo, len_int);
    }
    else
    {
        //Andra klienten är igång, skickar även startpositioner till båda klienter
        setNr = client1Position % 2;//Motsatt till första klienten

        x = client1Position - 1;
        //SDLNet_TCP_Send(csd[0], &x, sizeof(int));

        x = client1Position % 2;
        //SDLNet_TCP_Send(csd[1], &x, sizeof(int));

        int sendInfo = 1;


        int len_int = sizeof(sendInfo)+1;
        SDLNet_TCP_Send(csd[1], &sendInfo, len_int);

    }

    SDL_UnlockMutex(positionSetMutex);

    return setNr;
}

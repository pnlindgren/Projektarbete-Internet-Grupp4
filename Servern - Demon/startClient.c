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
    client_send_information clientSendData;
    client_recieve_information clientRecieveData;

    // längden på structen som sedan ska skickas (structens längd är samma som den serialiserade structen)
    int len1 = sizeof(clientSendData);
    int len2 = sizeof(clientRecieveData);

    // Serialiseradestructen kopierar varje bit med memcpy
    char serialiseradStruct1[len1];
    char serialiseradStruct2[len2];

    while(!gameOver)
    {
        SDLNet_TCP_Recv(csd[positionNr], &serialiseradStruct1, len1);
        memcpy(&clientSendData, &serialiseradStruct1, len1);
        gameVariables = convertSend(&clientSendData, gameVariables);

        SDL_LockMutex(ghostHitMutex);
        if(gameVariables.ghostFlag1 == true && ghostHitFlag[0] == false)
        {
            ghostRect1.x = 0;
            ghostRect1.y = 600;
            ghostHitCount++;
            ghostHitFlag[0] = true;
        }

        else if(gameVariables.ghostFlag2 == true && ghostHitFlag[1] == false)
        {
            ghostRect2.x = 0;
            ghostRect2.y = 600;
            ghostHitCount++;
            ghostHitFlag[1] = true;
        }

        else if(gameVariables.ghostFlag3 == true && ghostHitFlag[2] == false)
        {
            ghostRect3.x = 0;
            ghostRect3.y = 600;
            ghostHitCount++;
            ghostHitFlag[2] = true;
        }

        else if(gameVariables.ghostFlag4 == true && ghostHitFlag[3] == false)
        {
            ghostRect4.x = 0;
            ghostRect4.y = 600;
            ghostHitCount++;
            ghostHitFlag[3] = true;
        }

        else if(gameVariables.ghostFlag5 == true && ghostHitFlag[4] == false)
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

        gameVariables.ghostHit = ghostHitCount;

        SDL_UnlockMutex(ghostHitMutex);

        // Båda trådarna kommer nu ha uppdaterat sina bubblor vilket tillåter servern sedan
        // att ändra enemy_bubble
        bubble[positionNr] = gameVariables.bubble_rect;

        frame[positionNr] = gameVariables.character_frame;
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

        if(gameVariables.character_collision == true)
        {
            ghostHitCount = 5;
        }

        convertRecieve(&clientRecieveData, gameVariables);
        memcpy(&serialiseradStruct2, &clientRecieveData, len2);
        SDLNet_TCP_Send(csd[positionNr],&serialiseradStruct2,len2);

        SDL_Delay(10);

        if(ghostHitCount == 5 || gameVariables.end_game == true)
        {
            SDLNet_TCP_Recv(csd[positionNr], &serialiseradStruct1, len1);
            memcpy(&clientSendData, &serialiseradStruct1, len1);
            gameVariables = convertSend(&clientSendData, gameVariables);

            gameVariables.ghostHit = 5;
            ghostRect1.y = 600;
            ghostRect2.y = 600;
            ghostRect3.y = 600;
            ghostRect4.y = 600;
            ghostRect5.y = 600;

            convertRecieve(&clientRecieveData, gameVariables);
            memcpy(&serialiseradStruct2, &clientRecieveData, len2);
            SDLNet_TCP_Send(csd[positionNr],&serialiseradStruct2,len2);

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

game_objects convertSend(client_send_information *clientSendData, game_objects gameVariables)
{
    gameVariables.character_rect.x = clientSendData->charX;
    gameVariables.character_rect.y = clientSendData->charY;
    gameVariables.bubble_rect.x = clientSendData->char_bubbleX;
    gameVariables.bubble_rect.y = clientSendData->char_bubbleY;
    gameVariables.character_frame = clientSendData->char_frame;
    gameVariables.character_collision = clientSendData->char_collision;
    gameVariables.ghostFlag1 = clientSendData->ghostFlag1;
    gameVariables.ghostFlag2 = clientSendData->ghostFlag2;
    gameVariables.ghostFlag3 = clientSendData->ghostFlag3;
    gameVariables.ghostFlag4 = clientSendData->ghostFlag4;
    gameVariables.ghostFlag5 = clientSendData->ghostFlag5;
    gameVariables.end_game = clientSendData->end_game;
    gameVariables.character_flip = clientSendData->char_flip;

    return gameVariables;
}

void convertRecieve(client_recieve_information *clientRecieveData, game_objects gameVariables)
{
    clientRecieveData->rivalX = gameVariables.rival_rect.x;
    clientRecieveData->rivalY = gameVariables.rival_rect.y;
    clientRecieveData->rival_bubbleX = gameVariables.enemy_bubble.x;
    clientRecieveData->rival_bubbleY = gameVariables.enemy_bubble.y;
    clientRecieveData->rival_frame = gameVariables.enemy_frame;
    clientRecieveData->rival_flip = gameVariables.enemy_flip;
    clientRecieveData->ghost1X = gameVariables.ghost_rect1.x;
    clientRecieveData->ghost1Y = gameVariables.ghost_rect1.y;
    clientRecieveData->ghost2X = gameVariables.ghost_rect2.x;
    clientRecieveData->ghost2Y = gameVariables.ghost_rect2.y;
    clientRecieveData->ghost3X = gameVariables.ghost_rect3.x;
    clientRecieveData->ghost3Y = gameVariables.ghost_rect3.y;
    clientRecieveData->ghost4X = gameVariables.ghost_rect4.x;
    clientRecieveData->ghost4Y = gameVariables.ghost_rect4.y;
    clientRecieveData->ghost5X = gameVariables.ghost_rect5.x;
    clientRecieveData->ghost5Y = gameVariables.ghost_rect5.y;
    clientRecieveData->ghostHit = gameVariables.ghostHit;
}

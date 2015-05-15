#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

#define serverMessages 1

struct sendInformation
{
    int position;
    char namn[20];
}; typedef struct sendInformation send_information;

int main(int argc, char **argv)
{
    TCPsocket socket;
    IPaddress ip;

    send_information skickningar;
    int len = sizeof(skickningar);
    char serialiseradStruct[len];

    skickningar.position = 20;
    strcpy(skickningar.namn, "Kalle Anka");

	SDLNet_Init();
	SDLNet_ResolveHost(&ip, "127.0.0.1", 2000);
	socket = SDLNet_TCP_Open(&ip);

	while(serverMessages)
    {
        memcpy(&serialiseradStruct, &skickningar, len);

        SDLNet_TCP_Send(socket, &serialiseradStruct, len);

        SDL_Delay(1000);
    }
}

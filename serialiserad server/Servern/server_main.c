#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "main.h"

#define serverMessages 1

struct sendInformation
{
    int position;
    char namn[20];
}; typedef struct sendInformation send_information;

int main(int argc, char **argv)
{
	TCPsocket sd, csd;
	IPaddress ip;
	send_information message;
	bool connected = false;
	int len = sizeof(message);
	char serialiseradStruct[len];

	SDLNet_Init();
	SDLNet_ResolveHost(&ip, NULL, 2000);
	sd = SDLNet_TCP_Open(&ip);
    csd = SDLNet_TCP_Accept(sd);

    // printf av saker innan recv
    printf("nr: \n");

    while(serverMessages)
    {
        while(connected == false){
            if(csd = SDLNet_TCP_Accept(sd))
                connected = true;
            SDL_Delay(100);
        }

        // Här ska kod skickas

        SDLNet_TCP_Recv(csd, &serialiseradStruct, len);

        memcpy(&message, &serialiseradStruct, len);

        printf("nr: %d\n", message.position);

        SDL_Delay(1000);
    }

    SDLNet_TCP_Close(csd);
	SDLNet_TCP_Close(sd);
	SDLNet_Quit();
	return EXIT_SUCCESS;
}

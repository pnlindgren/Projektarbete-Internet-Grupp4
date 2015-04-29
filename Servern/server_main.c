#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "server_main.h"

void main(){

    SDLNet_ResolveHost(*IPaddress, NULL, 4523);

    socket = SDLNet_TCP_Open(*IPaddress);

    while(1)
    {
        if(Klientsockets[1] = SDLNet_TCP_Accept(socket))
            break;
        else
            SDL_Delay(200);

    }
    return 0;


}

#include <stdio.h>
#include <stdlib.h>

#include "SDL_net.h"
#include "initiateTCP.h"

void initiateTCP(IPaddress *ip, TCPsocket *sd)
{
    if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
    // Resolving the host using NULL make network interface to listen
	if (SDLNet_ResolveHost(ip, NULL, 2000) < 0)
	{
		fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	// Open a connection with the IP provided (listen on the host's port)
	if (!(*sd = SDLNet_TCP_Open(ip)))
	{
		fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
}

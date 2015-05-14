#ifndef STARTCLIENT
#define STARTCLIENT

int startClient(recieved_Information *gameData);

extern SDL_mutex *positionSetMutex;
extern bool firstPosition;
extern int client1Position;
extern TCPsocket csd[];

#endif // STARTCLIENT

#ifndef TCP_SOCKET
#define TCP_SOCKET

void tcp_socket_connect(TCPsocket *socketPekare);
void clientConnection(TCPsocket *socketPekare);

extern TCPsocket socket;

// ska skickas fr�n klienten
extern SDL_Rect bubble_rect;
extern SDL_Rect character_rect;

// ska tas emot fr�n servern
extern SDL_Rect ghost_rect;

#endif

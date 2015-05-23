#ifndef TCP_SOCKET
#define TCP_SOCKET

void tcp_socket_connect(TCPsocket *socketPekare);
void clientConnection(TCPsocket *socketPekare);
int position_start_function(TCPsocket *socketPekare);

extern game_objects gameVariables;

#endif

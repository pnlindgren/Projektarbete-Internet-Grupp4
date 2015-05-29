#ifndef TCP_SOCKET
#define TCP_SOCKET

void tcp_socket_connect(TCPsocket *socketPekare);
void clientConnection(TCPsocket *socketPekare);
int position_start_function(TCPsocket *socketPekare);
void convertSend(client_send_information *clientSendData);
void convertRecieve(client_recieve_information *clientRecieveData);

extern game_objects gameVariables;
extern local_rect_objects localRects;

#endif

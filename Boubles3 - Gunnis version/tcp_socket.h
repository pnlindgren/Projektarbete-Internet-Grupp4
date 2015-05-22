#ifndef TCP_SOCKET
#define TCP_SOCKET

void tcp_socket_connect(TCPsocket *socketPekare);
void clientConnection(TCPsocket *socketPekare);
int position_start_function(TCPsocket *socketPekare);

/*struct sendInformation
{
    SDL_Rect the_bubble;
    SDL_Rect the_character;
}; typedef struct sendInformation send_information;*/

extern rect_objects gameRectangels;

extern recieved_Information recievedI;

#endif

#ifndef STARTCLIENT
#define STARTCLIENT

int startClient(recieved_Information *gameData);

extern SDL_mutex *positionSetMutex;
extern bool firstPosition;
extern int client1Position;
extern TCPsocket csd[];
extern klientPositionX[2];
extern klientPositionY[2];
extern bool bubble_view;
extern int bubbleX;
extern int bubbleY;


struct rect_struct
{
    SDL_Rect character_rect;
    SDL_Rect rival_rect;
    SDL_Rect background_rect;
    SDL_Rect ghost_rect;
    SDL_Rect left_wall;
    SDL_Rect right_wall;
    SDL_Rect bubble_rect;
    SDL_Rect game_over;
    bool bubble_view;

}; typedef struct rect_struct rect_objects;

#endif // STARTCLIENT

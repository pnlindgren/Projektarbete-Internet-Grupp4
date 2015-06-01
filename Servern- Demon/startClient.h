#ifndef STARTCLIENT
#define STARTCLIENT

extern SDL_mutex *positionSetMutex;
extern SDL_mutex *ghostHitMutex;
extern bool firstPosition;
extern int client1Position;
extern TCPsocket csd[2];
extern klientPositionX[2];
extern klientPositionY[2];
extern int frame[2];
extern SDL_RendererFlip flip[2];
extern SDL_Rect ghostRect1;
extern SDL_Rect ghostRect2;
extern SDL_Rect ghostRect3;
extern SDL_Rect ghostRect4;
extern SDL_Rect ghostRect5;
extern SDL_Rect bubble[2];
extern int ghostHitCount;
extern bool ghostHitFlag[5];
extern bool gameOver;

struct game_struct
{
    SDL_Rect character_rect;
    SDL_Rect rival_rect;
    SDL_Rect ghost_rect1;
    SDL_Rect ghost_rect2;
    SDL_Rect ghost_rect3;
    SDL_Rect ghost_rect4;
    SDL_Rect ghost_rect5;
    SDL_Rect bubble_rect;
    SDL_Rect enemy_bubble;

    bool bubble_view;
    bool character_collision;
    bool end_game;
    int character_frame;
    int enemy_frame;
    int ghostHit;
    SDL_RendererFlip character_flip;
    SDL_RendererFlip enemy_flip;

    bool ghostFlag1;
    bool ghostFlag2;
    bool ghostFlag3;
    bool ghostFlag4;
    bool ghostFlag5;

}; typedef struct game_struct game_objects;


struct client_send_struct
{
    int charX;
    int charY;
    int char_bubbleX;
    int char_bubbleY;
    int char_frame;
    bool char_collision;
    bool ghostFlag1;
    bool ghostFlag2;
    bool ghostFlag3;
    bool ghostFlag4;
    bool ghostFlag5;
    bool end_game;
    SDL_RendererFlip char_flip;

}; typedef struct client_send_struct client_send_information;

struct client_recieve_struct
{
    int rivalX;
    int rivalY;
    int rival_bubbleX;
    int rival_bubbleY;
    int rival_frame;
    SDL_RendererFlip rival_flip;
    int ghost1X;
    int ghost1Y;
    int ghost2X;
    int ghost2Y;
    int ghost3X;
    int ghost3Y;
    int ghost4X;
    int ghost4Y;
    int ghost5X;
    int ghost5Y;
    int ghostHit;

}; typedef struct client_recieve_struct client_recieve_information;

int startClient(void * pointer);
game_objects convertSend(client_send_information *clientSendData, game_objects gameVariables);
void convertRecieve(client_recieve_information *clientRecieveData, game_objects gameVariables);

#endif // STARTCLIENT

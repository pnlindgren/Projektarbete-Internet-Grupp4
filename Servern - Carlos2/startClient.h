#ifndef STARTCLIENT
#define STARTCLIENT

int startClient(void * pointer);

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
    SDL_Rect background_rect;
    SDL_Rect ghost_rect1;
    SDL_Rect ghost_rect2;
    SDL_Rect ghost_rect3;
    SDL_Rect ghost_rect4;
    SDL_Rect ghost_rect5;
    SDL_Rect left_wall;
    SDL_Rect right_wall;
    SDL_Rect bubble_rect;
    SDL_Rect enemy_bubble;
    SDL_Rect game_over;

    bool bubble_view;
    int frame;
    int enemy_frame;
    int ghosthit;
    SDL_RendererFlip character_flip;
    SDL_RendererFlip enemy_flip;

}; typedef struct game_struct game_objects;

#endif // STARTCLIENT

#ifdef _WIN32

#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


#endif // _WIN32

#ifdef __APPLE__

#include <SDL2/SDL.h>
#include <SDL2_net/SDL_net.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_image/SDL_mixer.h>

#endif // __APPLE__

#ifndef CONSTANTS
#define CONSTANTS

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <stdbool.h>

struct graphic_struct
{
    SDL_Renderer*   renderer;
    SDL_Texture*    blueCrocodile;
    SDL_Texture*    pinkCrocodile;
    SDL_Texture*    background;
    SDL_Texture*    ghost;
    SDL_Texture*    bubble;
    SDL_Texture*    gameOver;

}; typedef struct graphic_struct textures;

struct local_rect_struct
{
    SDL_Rect background_rect;
    SDL_Rect left_wall;
    SDL_Rect right_wall;
    SDL_Rect game_over;

}; typedef struct local_rect_struct local_rect_objects;

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

#endif

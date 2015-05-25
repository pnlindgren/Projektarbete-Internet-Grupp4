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
    SDL_Texture*    background;
    SDL_Texture*    ghost;
    SDL_Texture*    wall;
    SDL_Texture*    bubble;
    SDL_Texture*    gameOver;

}; typedef struct graphic_struct textures;

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
    bool characterCollision;
    bool end_game;
    int frame;
    int enemy_frame;
    int ghosthit;
    SDL_RendererFlip character_flip;
    SDL_RendererFlip enemy_flip;

}; typedef struct game_struct game_objects;

#endif

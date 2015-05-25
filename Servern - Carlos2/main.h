#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

#ifndef CONSTANTS
#define CONSTANTS

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <stdbool.h>

/*
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
*/

struct game_struct
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
    int frame;
    int enemy_frame;
    SDL_RendererFlip character_flip;
    SDL_RendererFlip enemy_flip;

}; typedef struct game_struct game_objects;

#endif

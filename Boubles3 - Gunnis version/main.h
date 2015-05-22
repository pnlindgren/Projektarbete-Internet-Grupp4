#ifdef _WIN32

#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_image.h>

#endif // _WIN32

#ifdef __APPLE__

#include <SDL2/SDL.h>
#include <SDL2_net/SDL_net.h>
#include <SDL2_image/SDL_image.h>

#endif // __APPLE__

#ifndef CONSTANTS
#define CONSTANTS

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

struct recievedInformation
{
    SDL_Rect character_rects[2];
    SDL_Rect ghostRect;

}; typedef struct recievedInformation recieved_Information;

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

}; typedef struct rect_struct rect_objects;

#endif

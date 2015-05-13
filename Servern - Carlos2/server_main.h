
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

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

struct recievedInformation
{
    SDL_Rect character_rects[2];
    SDL_Rect ghostRect;
}; typedef struct recievedInformation recieved_Information;

#endif

#if 0
#!/bin/sh
gcc -Wall `sdl-config --cflags` tcps.c -o tcps `sdl-config --libs` -lSDL_net

exit
#endif

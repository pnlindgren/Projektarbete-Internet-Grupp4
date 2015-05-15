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

#endif

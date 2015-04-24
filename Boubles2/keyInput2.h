#ifndef KEYINPUT
#define KEYINPUT
#define RIGHT 1
#define LEFT 0

void keyInput2();

extern SDL_Window* gWindow;

extern SDL_Surface* gScreenSurface;

extern SDL_Surface* gBackground;

extern SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

extern SDL_Surface* gCurrentSurface;

#endif


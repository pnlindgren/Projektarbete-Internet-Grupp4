#ifndef KEYINPUT
#define KEYINPUT

void keyInput();

extern SDL_Window* gWindow;

extern SDL_Surface* gScreenSurface;

extern SDL_Surface* gBackground;

extern SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

extern SDL_Surface* gCurrentSurface;

#endif

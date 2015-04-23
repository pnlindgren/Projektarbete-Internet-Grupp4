#ifndef INITFUNCTIONS
#define INITFUNCTIONS

bool initBuild();
bool init();
bool loadMedia();

extern SDL_Window* gWindow;

extern SDL_Surface* gScreenSurface;

extern SDL_Surface* gBackground;

extern SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

extern SDL_Surface* gCurrentSurface;

extern SCREEN_WIDTH;

extern SCREEN_HEIGHT;

#endif INITFUNCTIONS

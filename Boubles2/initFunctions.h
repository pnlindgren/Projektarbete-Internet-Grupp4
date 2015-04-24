#ifndef INITFUNCTIONS
#define INITFUNCTIONS

#define BACKGROUND "pictures/NewBackground.bmp"
#define GHOST_RIGHT "pictures/ghostR.png"
#define GHOST_LEFT "pictures/ghostL.png"
#define GHOST_UP "pictures/bluecrocL.png"

bool initBuild();
bool init();
bool loadMedia();
bool loadKeyImage(char path[100], int pressed_key);
SDL_Surface* loadSurface(char path[100]);

extern SDL_Window* gWindow;

extern SDL_Surface* gScreenSurface;

extern SDL_Surface* gBackground;

extern SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

extern SDL_Surface* gCurrentSurface;

#endif

#ifndef INITFUNCTIONS
#define INITFUNCTIONS

#define BACKGROUND "NewBackground.bmp"
#define GHOST_RIGHT "ghostR.png"
#define GHOST_LEFT "ghostL.png"

bool initBuild();
bool init();
bool loadMedia();

bool loadImage(char path[100], int pressed_key);

extern SDL_Window* gWindow;

extern SDL_Surface* gScreenSurface;

extern SDL_Surface* gBackground;

extern SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

extern SDL_Surface* gCurrentSurface;

/*extern const int SCREEN_WIDTH;

extern const int SCREEN_HEIGHT;*/

#endif

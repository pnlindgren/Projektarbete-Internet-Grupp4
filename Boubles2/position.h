#ifndef POSITION
#define POSITION

bool wallDetection();
int drop();
void collisionDetection(SDL_Rect enemy);
void updateSurface();   //lets find a better name
void nextMove(void * pointer);

extern SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

extern SDL_Surface* gScreenSurface;

extern SDL_Window* gWindow;

#endif

#ifndef SCREEN_UPDATES
#define SCREEN_UPDATES
#include <stdbool.h>

int screenUpdateFunction(void * pointer);

extern textures gameTextures;
extern SDL_Rect gSpriteClips[13];
extern rect_objects gameRectangels;
extern SDL_RendererFlip flip;
extern int frame;
extern bool characterCollision;
extern bool bubble_view;
extern int ghosthit;

extern recieved_Information recievedI;

#endif

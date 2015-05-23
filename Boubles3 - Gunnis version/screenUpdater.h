#ifndef SCREEN_UPDATES
#define SCREEN_UPDATES
#include <stdbool.h>

int screenUpdateFunction(void * pointer);

extern textures gameTextures;
extern SDL_Rect gSpriteClips[13];
extern game_objects gameVariables;
extern bool characterCollision;
extern int ghosthit;

#endif

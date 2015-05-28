#ifndef SCREEN_UPDATES
#define SCREEN_UPDATES
#include <stdbool.h>

int screenUpdateFunction(void * pointer);

extern textures gameTextures;
extern SDL_Rect spriteClips[13];
extern game_objects gameVariables;
extern local_rect_objects localRects;

#endif

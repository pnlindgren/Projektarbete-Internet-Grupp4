#ifndef SCREEN_UPDATES
#define SCREEN_UPDATES
#include <stdbool.h>

int screenUpdateFunction(void * pointer);

extern SDL_Renderer* gRenderer;
extern SDL_Texture* mBlueCrocodile;
extern SDL_Texture* mBackground;
extern SDL_Texture* mGhost;
extern SDL_Texture* mWall;
extern SDL_Texture* mBubble;
extern SDL_Rect gSpriteClips[13];
extern SDL_Rect character_rect;
extern SDL_Rect background_rect;
extern SDL_Rect ghost_rect;
extern SDL_Rect wall_rect;
extern SDL_Rect bubble_rect;
extern SDL_RendererFlip flip;
extern int frame;
extern bool characterCollision;
extern SDL_Rect bubble_rect;
extern bool bubble_view;

#endif

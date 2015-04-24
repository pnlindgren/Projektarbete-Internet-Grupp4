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
extern SDL_Renderer* gRenderer;
extern SDL_Texture* mBlueCrocodile;
extern SDL_Texture* mBackground;
extern SDL_Texture* mGhost;
extern SDL_Rect gSpriteClips[13];
extern SDL_Rect character_rect;
extern SDL_Rect background_rect;
extern SDL_Rect ghost_rect;

#endif


#ifndef INITFUNCTIONS
#define INITFUNCTIONS

#define BACKGROUND "pictures/NewBackground.bmp"
#define BLUE_CROCODILE "pictures/nykrok.png"
#define GHOST "pictures/ghost.png"
#define BUBBLE "pictures/bubble.png"
#define GAMEOVER "pictures/Game_Over.png"

bool initBuild(int positionStart);
bool init();
bool loadMedia();
bool loadKeyImage(char path[100], int pressed_key);
SDL_Surface* loadSurface(char path[100]);

extern SDL_Window* gWindow;
extern textures gameTextures;
extern SDL_Rect gSpriteClips[13];
extern game_objects gameVariables;
extern local_rect_objects localRects;

#endif

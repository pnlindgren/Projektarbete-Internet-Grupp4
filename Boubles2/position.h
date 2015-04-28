#ifndef POSITION
#define POSITION

int drop();
void collisionDetection(SDL_Rect enemy);
void nextMove(void * pointer);

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Texture* mGhost;
extern SDL_Rect gSpriteClips[13];
extern SDL_Rect ghost_rect;

#endif

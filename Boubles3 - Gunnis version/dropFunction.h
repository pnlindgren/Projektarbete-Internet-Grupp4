#ifndef DROPFUNCTION
#define DROPFUNCTION

#define RIGHT 1
#define LEFT 0

int dropFunction(void *pointer);
int enemyDrop(void *point);

extern SDL_Rect character_rect;
extern SDL_Rect ghost_rect;

#endif // DROPFUNCTION

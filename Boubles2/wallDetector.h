#ifndef COLLISION
#define COLLISION

bool collisions(SDL_Rect rectangle);

extern SDL_Rect ghost_rect;
extern SDL_Rect character_rect;
extern SDL_Rect left_wall;
extern SDL_Rect right_wall;
extern int frame;

#endif

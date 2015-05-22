#ifndef COLLISION
#define COLLISION

bool collisions(SDL_Rect rectangle);
int enemyCollision();

extern rect_objects gameRectangels;
extern int frame;
extern bool characterCollision;

extern recieved_Information recievedI;

#endif

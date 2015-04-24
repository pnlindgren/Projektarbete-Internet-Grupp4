#ifndef POSITION
#define POSITION

bool wallDetection();
int drop();
void collisionDetection(SDL_Rect enemy);
void updateSurface();   //lets find a better name
void nextMove(bool moved, int direction);
#endif

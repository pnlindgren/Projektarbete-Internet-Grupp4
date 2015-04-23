#ifndef POSITION
#define POSITION

bool wallDetection();
int drop();
void collisionDetection();
void updateSurface();   //lets find a better name
void nextMove(int x,int y, bool moved, int direction);
#endif POSITION

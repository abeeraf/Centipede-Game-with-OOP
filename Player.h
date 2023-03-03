#ifndef Player_h
#define Player_h
#include "MoveableObject.h"

class Player:public MoveableObject{
protected:

public:
Player();
Player(int a, int b, int c);
void draw();
void move(int a);

};
#endif

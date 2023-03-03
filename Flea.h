#ifndef Flea_h
#define Flea_h
#include "MoveableObject.h"
#include "Bomb.h"
#include "ScoreBoard.h"
#include "Player.h"
class Flea:public MoveableObject{

public:
Flea();
Flea(int a, int b, int c);
void draw();
void move(int a);
void callmove(int& a);
void checkplayer(Player& p,bool& die);
//void hit(Bomb& bull,ScoreBoard& s);
};
#endif

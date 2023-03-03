#ifndef Segment_h
#define Segment_h
#include "MoveableObject.h"
#include "Player.h"
#include "Bomb.h"
//#include "ScoreBoard.cpp"
class Segment :public MoveableObject{
protected:
int direction=1;

public:
Segment();
Segment(int a,int b,int c);
void draw();
void move(int a);
int getDirection();
void setDeirecton(int a);
virtual void checkcollimushrooms(int**array)=0;
virtual void checkcolliplayer(Player p,bool& die)=0;
virtual int diemagic(Bomb& bull,ScoreBoard s)=0;
};
#endif

#ifndef Lazyseg_h
#define Lazyseg_h
#include "Segment.h"
class LazySeg:public Segment{
protected:
int air=10;

public:
LazySeg();
LazySeg(int a,int b,int c);
void move(int a);
void draw();
void checkcollimushrooms(int**array);
void checkcolliplayer(Player p,bool& die);
int diemagic(Bomb& bull,ScoreBoard s);
};
#endif

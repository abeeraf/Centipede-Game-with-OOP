#ifndef MagicSeg_h
#define MagicSeg_h
#include "Segment.h"
class MagicSeg:public Segment{
protected:
//int direction=1;
int air=10;
public:
MagicSeg();
MagicSeg(int a,int b, int c);
void move(int a);
void draw();
int getDirection();
void setDeirecton();
void checkcollimushrooms(int**array);
void checkcolliplayer(Player p,bool& die);
int diemagic(Bomb& bull,ScoreBoard s);
};
#endif

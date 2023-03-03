#ifndef Bomb_h
#define Bomb_h
#include "MoveableObject.h"
#include "Mushroom.h"
#include "ScoreBoard.h"
#include "Flea.h"
class Bomb:public MoveableObject{
protected: 

public:
Bomb();
Bomb(int a, int b, int c);
void draw();
void move(int a);
void checkcollmush(int** arr,Mushroom* mushray,int& numush,ScoreBoard& );
void checkcollflea(Flea& fle,ScoreBoard& s);
};
#endif

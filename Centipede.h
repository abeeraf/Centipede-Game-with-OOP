#ifndef Centipede_h
#define Centipede_h
#include "Segment.h"
#include "MagicSeg.h"
#include "LazySeg.h"
#include "Player.h"
#include "ScoreBoard.h"
class Centipede{
protected:
int size=10;
Segment** centi;

public:
Centipede();
void draw();
void move(int a);
void collisions(int** arr);
void checkcolliplay(Player& p1,bool& check);
void killhead(Bomb& bull,ScoreBoard s);
};
#endif

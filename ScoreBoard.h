#ifndef ScoreBoard_h
#define ScoreBoard_h
#include "GameObject.h"

class ScoreBoard:public GameObject{
protected: 
int score;
int lives;
int level;

public: 
ScoreBoard();
void setScore(int x);
int getScore();
void setLives(int x);
int getLives();
void updatelives();
void updatelevels();
void draw();
int getLevel();
};
#endif

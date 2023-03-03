#ifndef Mushroom_h
#define Mushroom_h
#include "GameObject.h"

class Mushroom:public GameObject{
protected: 
int Health;
bool Poison; //is poisoned or not 

public: 
Mushroom();
Mushroom(float a, float b, int c, int d, bool e);
Mushroom(Mushroom &copy);
void setHealth(int a);
int getHealth();
void setPoison(bool a);
bool getPoison();
void draw();
};
#endif

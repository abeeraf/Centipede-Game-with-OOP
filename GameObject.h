#ifndef GameObject_h
#define GameObject_h
#include "Position.h"

class GameObject{

protected:
Position P;
int Type; //type will be the number on array

/*
background =0
player=1;
centi magic =2 (head)
centi lazy =3
mushroom=4;
bomb=5
*/

public:
GameObject();
GameObject(int a, int b, int c);
//GameObject(Position P, int c);
//GameObject(GameObject& obj);
void setType(int a);
int getType();
int getPxcor();
void setPxcor(int a);
int getPycor();
void setPycor(int a);
void setPosition(int a,int b);
Position getPosition();
virtual void draw()=0;


};
#endif

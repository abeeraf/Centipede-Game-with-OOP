#ifndef MoveableObject_h
#define MoveableObject_h
#include "GameObject.h"

class MoveableObject:public GameObject{
protected: 

public:
MoveableObject();
MoveableObject(int a, int b, int c);
virtual void draw();
virtual void move(int a)=0;

};
#endif

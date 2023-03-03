#ifndef Position_h
#define Position_h
#include "util.h"
class Position{

protected:
int xcor;
int ycor;

public:
Position();
Position(int a, int b);
Position(Position& P);
int getxcor();
void setxcor(int a);
int getycor();
void setycor(int a);
};
#endif

#include "Position.h"

Position::Position()
{
	xcor=1;
	ycor=1;
}
Position::Position(int a, int b)
{
	xcor=a;
	ycor=b;
}
Position::Position(Position& p)
{
	xcor=p.xcor;
	ycor=p.ycor;
}
int Position::getxcor()
{
	return xcor;
}
void Position::setxcor(int a)
{
	xcor=a;
}
int Position::getycor()
{
	return ycor;
}
void Position::setycor(int a)
{
	ycor=a;
}


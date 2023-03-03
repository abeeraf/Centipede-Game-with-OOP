#include "Mushroom.h"

Mushroom::Mushroom():GameObject()
{
	Health=2;
	Poison=0;
}
Mushroom::Mushroom(float a, float b, int c, int d, bool e):GameObject(a,b,c)
{
	Health=d;
	Poison=e;	
}
Mushroom::Mushroom(Mushroom &copy):GameObject(copy.getPxcor(),copy.getPycor(),copy.getType())
{
	Health=copy.Health;
	Poison=copy.Poison;
}
void Mushroom::setHealth(int a)
{
	Health=a;
}
int Mushroom::getHealth()
{
	return Health;
}
void Mushroom::setPoison(bool a)
{
	Poison=a;
}
bool Mushroom::getPoison()
{
	return Poison;
}
void Mushroom::draw()
{

	if(Poison)	
	DrawSquare(P.getxcor()*10 ,P.getycor()*10 ,10,colors[WHITE]);
	else 
	DrawSquare( P.getxcor()*10 ,P.getycor()*10 ,10,colors[GREEN]);
}

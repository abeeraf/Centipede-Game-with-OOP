#include "Segment.h"

Segment::Segment()
{
	direction=1;
}
Segment::Segment(int a,int b,int c):MoveableObject(a,b,c)
{

}
void Segment::draw()
{

}
void Segment::move(int a)
{

}
int Segment::getDirection()
{
	return direction;
}
void Segment::setDeirecton(int a)
{
	direction=a;
}


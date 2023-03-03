#include "Centipede.h"

Centipede::Centipede()
{
	centi= new Segment*[size];
	centi[0]=new MagicSeg(50,58,2);
	for(int x=1;x<size;x++)
	{
		centi[x]=new LazySeg(centi[x-1]->getPxcor()+1,centi[x-1]->getPycor(),3);

	}
}
void Centipede::draw()
{
	for(int x=0;x<size;x++)
	{
		centi[x]->draw();
	}
}
void Centipede::move(int a)
{
	for(int x=0;x<size;x++)
	{
		centi[x]->move(a);
	}
}
void Centipede::collisions(int** arr)
{
	for(int x=0;x<size;x++)
	{
		centi[x]->checkcollimushrooms(arr);
	}
}
void  Centipede::checkcolliplay(Player& p1,bool & check)
{
	centi[0]->checkcolliplayer(p1, check);
}
void Centipede::killhead(Bomb& bull,ScoreBoard s)
{
	size+=centi[0]->diemagic(bull,s);
}








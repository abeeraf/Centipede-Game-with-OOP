#include "Bomb.h"

Bomb::Bomb():MoveableObject()
{
	
}
Bomb::Bomb(int a, int b, int c):MoveableObject(a,b,c)
{

} 
void Bomb::draw()
{
	DrawSquare(getPxcor()*10,getPycor()*10,10,colors[RED]);
	setPycor(getPycor()+1);
	
}
void Bomb::move(int a)
{	
	draw();	
	setPycor(getPycor()+1);	
}
/*
background =0
player=1;
centi magic =2 (head)
centi lazy =3
mushroom=4;
bomb=5
*/
void Bomb::checkcollmush(int** arr,Mushroom* mushray,int& numush,ScoreBoard& s)
{
	//with mushroom
	if (arr[getPxcor()][getPycor()]==4)
	{
		for(int x=0;x<numush;x++)
		{
			if((mushray[x].getPxcor()==getPxcor())&&(mushray[x].getPycor()==getPycor()))
			{setPxcor(60);setPycor(0);
				if (mushray[x].getHealth()>0)
				{
					mushray[x].setHealth(mushray[x].getHealth()-1);
				}			
				if (mushray[x].getHealth()==0)

				{		s.setScore(s.getScore()+10);				
					for(int y=x;y<numush-1;y++)
					{
						mushray[y]=mushray[y+1];						
						
					}
				numush--;
				arr[getPxcor()][getPycor()]=0;
				}
			}
		}
	
	}
}
void Bomb::checkcollflea(Flea& fle,ScoreBoard& s)
{
	if((getPxcor()==fle.getPxcor()) && (getPycor()==fle.getPycor()))
	{
		setPxcor(60);
		setPycor(1);
		fle.setPxcor(60);
		fle.setPycor(0);
		s.setScore(s.getScore()+200);
	}
}













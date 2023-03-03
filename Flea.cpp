#include "Flea.h"

Flea::Flea():MoveableObject()
{

}
Flea::Flea(int a, int b, int c):MoveableObject(a,b,c)
{

} 
void Flea::draw()
{
	DrawSquare(getPxcor()*10,getPycor()*10,10,colors[RED]);
}
void Flea::move(int a)
{

	draw();	
	setPycor(getPycor()-1);
	
}
void Flea::callmove(int& a)
{
		move(1);
	
}
void Flea::checkplayer(Player& p,bool& die)
{	if((p.getPxcor()==getPxcor())&&(p.getPycor()==getPycor()))
	die=1;
}
/*void Flea::hit(Bomb& bull,ScoreBoard& s)
{
	if((getPxcor()==bull.getPxcor()) && (getPycor()==bull.getPycor()))
	{
		s.setScore(s.getScore()+200);
		bull.setPxcor(60);
		bull.setPycor(0);
		setPxcor(60);
		setPycor(2);
		cout<<"HIT"<<endl;
	}
}*/

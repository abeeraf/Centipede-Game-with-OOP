#include "LazySeg.h"

LazySeg::LazySeg():Segment()
{
	
}
LazySeg::LazySeg(int a,int b,int c):Segment(a,b,c)
{
	
}
void LazySeg::move(int a)
{
	int x=getPxcor();
	if(direction==1)//going left
	{
		if(x>0)
		{setPxcor(getPxcor()-1);}
		if(x==1)
		{
			if(getPycor()==1)
			{air=1;}
			if((1<=air)&&(air<10))
			{setPycor(getPycor()+1);
			air++;}
			if((getPycor()>=2)&&(air==10))
			{setPycor(getPycor()-1);}
			direction=0;
		}
	}
	if(direction==0)//going right 
	{
		if(x<60)
		{setPxcor(getPxcor()+1);}
		if(x==59)
		{
			if(getPycor()==1)
			{air=1;}
			if((1<=air)&&(air<10))
			{setPycor(getPycor()+1);
			air++;}
			if((getPycor()>=2)&&(air==10))
			{setPycor(getPycor()-1);}
			direction=1;
		}
	}
}
void LazySeg::draw()
{
	DrawCircle(getPxcor()*10,getPycor()*10,5,colors[ORANGE]);
	//DrawRoundRect(getPxcor()*10, getPycor()*10, 10, 10, 0, 0.0);
}
void LazySeg::checkcollimushrooms(int**arr)
{	int x=getPxcor();
	if((direction==0)&&(arr[getPxcor()-1][getPycor()]==4))
	{
		setPxcor(getPxcor()+1);
		if(getPycor()==1)
		{air=1;}
		if((1<=air)&&(air<10))
		{setPycor(getPycor()+1);
		air++;}
		if((getPycor()>=2)&&(air==10))
		{setPycor(getPycor()-1);}
		setPxcor(getPxcor()-1);
		direction=1;
		
	}
	if((direction==1)&&(arr[getPxcor()-1][getPycor()]==4))
	{
		setPxcor(getPxcor()+1);
		if(getPycor()==1)
		{air=1;}
		if((1<=air)&&(air<10))
		{setPycor(getPycor()+1);
		air++;}
		if((getPycor()>=2)&&(air==10))
		{setPycor(getPycor()-1);}
		setPxcor(getPxcor()-1);
		direction=1;
		
	}
}
void LazySeg::checkcolliplayer(Player p,bool& die)
{
	
}

int  LazySeg::diemagic(Bomb& bull,ScoreBoard s)
{

}




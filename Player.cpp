#include "Player.h"

Player::Player():MoveableObject()
{

}
Player::Player(int a, int b, int c):MoveableObject(a,b,c)
{

} 
void Player::draw()
{
	DrawSquare(getPxcor()*10,getPycor()*10,20,colors[BROWN]);	
	//DrawCircle(getPxcor()*10,getPycor()*10,10,colors[BROWN]);
}
void Player::move(int a)
{
	switch (a){
	case 1:setPxcor(getPxcor()+1);break;
	case 2:setPxcor(getPxcor()-1);break;
	case 3:setPycor(getPycor()+1);break;
	case 4:setPycor(getPycor()-1);break;}
}

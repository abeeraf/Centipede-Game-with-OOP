#include "GameObject.h"

GameObject::GameObject()
{
	P.setxcor(0);
	P.setycor(0);	
	Type=0;
}
GameObject::GameObject(int a, int b, int c)
{
	P.setxcor(a);
	P.setycor(b);
	Type=c;
}
/*GameObject::GameObject(Position P, int c):Position(P)
{
	
	Type=c;
}
GameObject::GameObject(GameObject& obj):Position(obj.P)
{
	Type=obj.Type;
}*/
void GameObject::setType(int a)
{
	Type=a;
}
int GameObject::getType()
{
	return Type;
}
int GameObject::getPxcor()
{
	return P.getxcor();
}
void GameObject::setPxcor(int a)
{
	P.setxcor(a);
}
int GameObject::getPycor()
{
	return P.getycor();
}
void GameObject::setPycor(int a)
{
	P.setycor(a);
}
void GameObject::setPosition(int a,int b)
{
	P.setxcor(a);
	P.setycor(b);
}
Position GameObject::getPosition()
{
	return P;
}








#include "ScoreBoard.h"

ScoreBoard::ScoreBoard():GameObject()
{
	score=0;
	lives=0;
	level=1;
}
void ScoreBoard::setScore(int x)
{
	score=x;
	if (lives<6)
	{updatelives();}
}
int ScoreBoard::getScore()
{
	return score;
}
void ScoreBoard::setLives(int x)
{
	lives=x;
}
int ScoreBoard::getLives()
{
	return lives;
}
void ScoreBoard::updatelives()
{
	if((score%10000==0)or(score%12000==0)or(score%15000==0)or(score%20000==0))
	lives++;
}
void ScoreBoard::updatelevels()
{
	level++;
}
int ScoreBoard::getLevel()
{
	return level;
}
void ScoreBoard::draw()
{
	DrawString( 270, 580, "Level="+to_string(getLevel()), colors[RED]);
	if (score<999999)
	{DrawString( 50, 580, "Score="+to_string(getScore()), colors[RED]);}
	else 
	{DrawString( 270, 300, "YOU WIN", colors[MISTY_ROSE]);}
}

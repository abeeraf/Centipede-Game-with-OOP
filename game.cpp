//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include <cstdlib>
#include "Board.h"
#include "util.h"
#include "Mushroom.cpp"
#include "MoveableObject.cpp"
#include "Position.cpp"
#include "GameObject.cpp"
#include "Bomb.cpp"
#include "Player.cpp"
#include "ScoreBoard.cpp"
#include "Flea.cpp"
#include <iostream>
#include<string>
#include<cmath> 
#include <vector>
#include "Centipede.cpp"
#include "Segment.cpp"
#include "LazySeg.cpp"
#include "MagicSeg.cpp"
using namespace std;


Player p1(30,1,3);
Mushroom* mush;
int** array=new int* [61];
Bomb bullet(60,1,5);
Flea flea(60,0,5);
int flea_timer=time(0);
bool fleaget=1;
int num_mush=25;
int fleaspeed=0;
ScoreBoard scorex;
Centipede train;
bool die=0;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
Board *b;
void GameDisplay()/**/{

	
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0, 0,0.0, 0 ); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Fire Gun
	/*DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Mushroom
	DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Spider
	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, int *color)
	DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	DrawCircle(600,,600,10,colors[RED]);*/

	if(die)
	{	for(int i=0 ; i<60 ; i++)
		{
			for(int j= 0 ; j<60 ; j++)
			{
				DrawSquare( j*10 , i*10 ,11,colors[WHITE]);
			}
		}
		DrawString( 240, 300, "YOU LOST", colors[RED]);
	}
	if (bullet.getPycor()<60)
	{
		bullet.draw();////remove bullet x and y cor and change baord number to zero
		bullet.checkcollmush(array,mush,num_mush,scorex);
		bullet.checkcollflea(flea,scorex);
	}

	for(int x=0;x<num_mush;x++)

	{
		mush[x].draw();
		
	}
	flea.checkplayer(p1,die);
	train.draw();
	train.move(1);
	train.collisions(array);
	train.checkcolliplay(p1,die);
	if((time(0)-flea_timer>9)&(time(0)-flea_timer<14))
	{	if(fleaget)
		{		
			flea.setPxcor(1+rand()%58);
			flea.setPycor(58);
			fleaget=0;
		}
		flea.move(1);
		//int a=rand()%15+5;
		/*if(flea.getPycor()%a==0)
		{	
			int b=num_mush;
			num_mush++;
			
				mush[a].setHealth(2);
				mush[a].setPoison(0);
				mush[a].setType(4);//mush number
				mush[a].setPxcor(flea.getPxcor());
				mush[a].setPycor(a);
				array[flea.getPxcor()][a]=4;
		}*/
		//flea.hit(bullet,scorex);
		if (time(0)-flea_timer>14)
		{	
			flea_timer=time(0);
			fleaget=1;
		}
	}
	p1.draw();
	scorex.draw();
	//glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..
	

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) 
{
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	 {
		// what to do when left key is pressed...
		if(p1.getPxcor()>0)	
		{
			int x=p1.getPxcor(),y=p1.getPycor();
			array[x][y]=0;
			p1.move(2);
			x=p1.getPxcor(),y=p1.getPycor();
			array[x][y]=1;
		}

	} 
	else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
	{
		if(p1.getPxcor()<58)	
		{
			int x=p1.getPxcor(),y=p1.getPycor();
			array[x][y]=0;
			p1.move(1);
			x=p1.getPxcor(),y=p1.getPycor();
			array[x][y]=1;
		}
	} 
	else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if(p1.getPycor()<10)	
		{
			int x=p1.getPxcor(),y=p1.getPycor();
			array[x][y]=0;
			p1.move(3);
			x=p1.getPxcor(),y=p1.getPycor();
			array[x][y]=1;
		}
	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	if(p1.getPycor()>1)	
	{
		int x=p1.getPxcor(),y=p1.getPycor();
		array[x][y]=0;
		p1.move(4);
		x=p1.getPxcor(),y=p1.getPycor();
		array[x][y]=1;
	}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	//glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
	{		
		bullet.setPosition(p1.getPxcor(),p1.getPycor()+1);

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0/20, Timer, 0);
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	//glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//train.draw();
	//train.move(1);
	for (int x=0;x<61;x++)
	{array[x]=new int [61];}

	for (int x=0;x<60;x++)
	{	for(int y=0;y<60;y++)
		{
			array[x][y]=0;//background
		}
	}

	srand(time(0));
	mush=new Mushroom[num_mush];
	int xpos=p1.getPxcor(),ypos=p1.getPycor();
	array[xpos][ypos]=1;
	int c=0;

	while(c<num_mush-5)
	{
		mush[c].setHealth(2);
		mush[c].setPoison(0);
		mush[c].setType(4);//mush number
		int a=1+rand()%58;
		int b=7+rand()%56;
	
		if ((array[a][b]==0)&&(a%2==0)&&(b%2==0))
		{
			mush[c].setPxcor(a);
			mush[c].setPycor(b);
			array[a][b]=4;
			c++;
		}
		
	}
	int num=2; int num2=1;
	while(c<num_mush)
	{
		mush[c].setHealth(2);
		mush[c].setPoison(0);
		mush[c].setType(4);//mush number
		int a=1+pow(num,2);
		int b=7+num2;
		
		if ((array[a][b]!=4))
		{
			mush[c].setPxcor(a);
			mush[c].setPycor(b);
			array[a][b]=4;
			c++;num++;num2*=2;
		}

	}

	b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 600, height = 600; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */

#include "Game.h"
#include <unistd.h>

using namespace std;

// Unreal coding standards
using int32 = int;


CharPosition::CharPosition(int32 col, int32 row)
{
	x = col;
	y = row;
}

CharPosition::CharPosition()
{
	x = 0;
	y = 0;
}

Game::Game()
{
	// variables initialisation:
	partchar = 'x'; // character to represent the snake
	edgechar = '.'; // full rectangle on the key table
	fruitchar = '*';
	poisonchar='p';
	fruit.x = 0;
	fruit.y = 0;
	poison.x=0;
	poison.y=0;
	score = 0;
	del = 110000;
	bool bEatsFruit = 0;
	bool bEatsPoison = 0;
	bool lastPoison= 0;

	direction = 'l';
	srand(time(NULL));

	InitGameWindow();
	PositionFruit();
	PositionPoison();
	DrawWindow();
	DrawSnake();
	PrintScore();

	refresh();
}

Game::~Game()
{
	nodelay(stdscr, false);
	getch();
	endwin();
}

void Game::GetRandom(){
	one=rand()%2+1;
	two=rand()%2+1;
	a=rand()%(maxwidth);
	b=rand()%(10)+1;

}
// initialise the game window
void Game::InitGameWindow()
{
	initscr(); // initialise the screen
	nodelay(stdscr,TRUE);
	keypad(stdscr, true); // initialise the keyboard: we can use arrows for directions
	noecho(); // user input is not displayed on the screen
	curs_set(0); // cursor symbol is not not displayed on the screen (Linux)
	getmaxyx(stdscr, maxheight, maxwidth); // define dimensions of game window
	return;
}

// draw the game window
void Game::DrawWindow()
{
  screen.text_attr((short)0x03);
	GetRandom();
	for (int32 i = 0; i < maxwidth; i++) // draws top
	{
		move(0, i);
		if(i==a){
			if(one==1){
				addch('_');
				w1=1;
				continue;
			}
		}

		addch(edgechar);
	}

	for (int32 i = 0; i < maxwidth; i++) // draws bottom
	{
		move(maxheight-2, i);
		if(i==a){
			if(one==2){
				addch('_');
				w1=2;
				continue;
			}
		}

		addch(edgechar);

	}

	for (int32 i = 0; i < maxheight-1; i++) // draws left side
	{
		move(i, 0);
		if(i==b){
			if(two==1){
				addch('|');
				w2=1;
				continue;
			}
}

		addch(edgechar);
	}

	for (int32 i = 0; i < maxheight-1; i++) // draws right side
	{
		move(i, maxwidth-1);
		if(i==b){
			if(two==2){
				addch('|');
				w2=2;
				continue;
			}
		}

		addch(edgechar);
	}

	return;
}

// draw snake's body
void Game::DrawSnake()
{
	for (int32 i = 0; i < 5; i++)
	{
		snake.push_back(CharPosition(30+i, 10));
	}

	for (int32 i = 0; i < snake.size(); i++)
	{
		move(snake[i].y, snake[i].x);
		addch(partchar);
	}
	return;
}

// print score at bottom of window
void Game::PrintScore()
{
	move(maxheight-1, 0);
	printw("Score: %d", score);
	return;
}

// position a new fruit in the game window
void Game::PositionFruit()
{
	screen.text_attr((short)0x02);
	while(1)
	{
		int32 tmpx = rand()%maxwidth+1; // +1 to avoid the 0
		int32 tmpy = rand()%maxheight+1;

		// check that the fruit is not positioned on the snake
		for (int32 i = 0; i < snake.size(); i++)
		{
			if (snake[i].x == tmpx && snake[i].y == tmpy)
			{
				continue; // if true, ignore the following and go back to the beginning of function
			}
		}

		// check that the fruit is positioned within the game window
		if (tmpx >= maxwidth-2 || tmpy >= maxheight-3)
		{
			continue; // if true, ignore the following and go back to the beginning of function
		}

		// if the coordinates are valid, add fruit in the window
		fruit.x = tmpx;
		fruit.y = tmpy;
		break;
	}

	move(fruit.y, fruit.x);
	addch(fruitchar);
	refresh();
}

// position a new poison in the game window
void Game::PositionPoison()
{
	screen.text_attr((short)0x01);
	while(1)
	{
		int32 tmpx = rand()%maxwidth+1; // +1 to avoid the 0
		int32 tmpy = rand()%maxheight+1;

		// check that the poison is not positioned on the snake
		for (int32 i = 0; i < snake.size(); i++)
		{
			if (snake[i].x == tmpx && snake[i].y == tmpy)
			{
				continue; // if true, ignore the following and go back to the beginning of function
			}
		}

		// check that the poison is positioned within the game window
		if (tmpx >= maxwidth-2 || tmpy >= maxheight-3)
		{
			continue; // if true, ignore the following and go back to the beginning of function
		}

		// if the coordinates are valid, add fruit in the window
		poison.x = tmpx;
		poison.y = tmpy;
		break;
	}

	move(poison.y, poison.x);
	addch(poisonchar);
	refresh();
}

// set game over situations
bool Game::FatalCollision()
{
	if(w1==1 && w2==1){//if gate is at top and left gate

		if(snake[0].y==0 && one==1){ //if snake touches the gate at the top side, come out of left side
	 		if (snake[0].x==a ){
	 		 	snake[0].y=b;
				snake[0].x=1;
				direction='r';//the direction of the snake will be right
	 			DrawWindow();
	 			refresh();
				checkedge=false;

	 	 }
	 }
		 else if(snake[0].x==0 && two==1){//if snake touches the gate at the left side, come out of top side
	 	 	 if (snake[0].y==b ){
    		 snake[0].x=a;
				 snake[0].y=1;
				 direction='d';//the direction of the snake will be down
	 	 		 DrawWindow();
	 	 		 refresh();
				 checkedge=false;

 	 	 }
	 }
	 }

	else if (w1==1 && w2==2){// if gate is at top and right side
		if(snake[0].y==0 && one==1){//if snake touches the gate at the top side, come out of right side
	 		if (snake[0].x==a ){
	 			snake[0].y=b;
				snake[0].x=maxwidth-2;
	 			direction='l'; //the direction of the snake will be left
	 			DrawWindow();
	 			refresh();
					checkedge=false;

	 	 }}
		 else if(snake[0].x==maxwidth-1 && two==2){//if snake touches the gate at the right side, come out of top side
	 	 	 if (snake[0].y==b ){
	 	 		 snake[0].x=a;
				 snake[0].y=1;
				 direction='d';//the direction of the snake will be down
	 	 		 DrawWindow();
	 	 		 refresh();
				 checkedge=false;

 	 	 }
	 }
}
	else if (w1==2 && w2==1){ //if gate is at bottom and left side

		if(snake[0].y==maxheight-2 && one ==2){//if snake touches the gate at the bottom side, come out of left side
	 	 if (snake[0].x==a){
 	 		 	snake[0].y=b;
 	 			snake[0].x=1;
				direction='r';//the direction of the snake will be right
 	 			DrawWindow();
 	 			refresh();
				checkedge=false;
			}}
			else if(snake[0].x==0 && two==1){//if snake touches the gate at the left side, come out of bottom side
 	 	 	 if (snake[0].y==b ){
 	 	 		 snake[0].x=a;
				 snake[0].y=maxheight-3;
				 direction='u';//the direction of the snake will be up
 	 	 		 DrawWindow();
 	 	 		 refresh();
				 checkedge=false;

  	 	 }}
		 }

	else if (w1==2 && w2==2){ //if gate is at bottom and right side
		if(snake[0].y==maxheight-2 && one ==2){//if snake touches the gate at the bottom side, come out of right side
		 if (snake[0].x==a){
			 	snake[0].y=b;
	 			 snake[0].x=maxwidth-2;
				 direction='l';//the direction of the snake will be left
	 			 DrawWindow();
	 			 refresh();
				 checkedge=false;
	}}

	else if(snake[0].x==maxwidth-1 && two==2){//if snake touches the gate at the right side, come out of bottom side
		if (snake[0].y==b ){
 		 snake[0].x=a;
 		 snake[0].y=maxheight-3;
 		 direction='u';//the direction of the snake will be up
		 DrawWindow();
		 refresh();
		 checkedge=false;

	 }}
 }

if(checkedge &&(snake[0].x == 0 || snake[0].x == maxwidth-1 || snake[0].y == 0 || snake[0].y == maxheight-2)){//if snake touches the wall
 	return true;
}
else{
	checkedge=true;
}

	// if the snake collides into itsself
	for (int32 i = 2; i < snake.size(); i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
		{
			return true;
		}
	}

	return false;
}


// define behaviour when snake eats the fruit
bool Game::GetsFruit()
{

	if (snake[0].x == fruit.x && snake[0].y == fruit.y)
	{
		PositionFruit();
		score +=10;
		PrintScore();

		// if score is a multiple of 100, increase snake speed
		if ((score%100) == 0)
		{
			del -= 1000;
		}
		return bEatsFruit = true;
	}
	else
	{
		return bEatsFruit = false;
	}
	return bEatsFruit;
}

bool Game::GetsPoison()
{
	if (snake[0].x == poison.x && snake[0].y == poison.y)
	{
	if(snake.size()==2){ // if snake eats the last poison, GAME OVER!!
		lastPoison=TRUE;
	}
	else{
	snake.pop_back(); // removes the last element in the vector
	PositionPoison();}
	return bEatsPoison = true;
}
else
{
	return bEatsPoison = false;
}
return bEatsPoison;
}

// define snake's movements
void Game::MoveSnake()
{
	KeyPressed = getch();
	switch(KeyPressed)
	{
		case KEY_LEFT:
			if (direction != 'r')
			{ direction = 'l'; }
			break;
		case KEY_RIGHT:
			if (direction != 'l')
			{ direction = 'r'; }
			break;
		case KEY_UP:
			if (direction != 'd')
			{ direction = 'u'; }
			break;
		case KEY_DOWN:
			if (direction != 'u')
			{ direction = 'd'; }
			break;
		case KEY_BACKSPACE:
			direction = 'q'; // key to quit the game
			break;
	}

	// the snake doesn't eat fruit, remains same size
	if (!bEatsFruit)
	{
		move(snake[snake.size()-1].y, snake[snake.size()-1].x); // moves at the end of the tail
		printw(" "); // add empty ch to remove last character
		refresh();
		snake.pop_back(); // removes the last element in the vector, reducing the container size by one
	}

	// the snake doesn't eat fruit, remains same size
	if (!bEatsPoison)
	{
		 move(snake[snake.size()-1].y, snake[snake.size()-1].x); // moves at the end of the tail
		 printw(" "); // add empty ch to remove last character
		 refresh();

	}
	// the snake moves and we add an extra character at the beginning of the vector
	// add a head and initialise new coordinates for CharPosition according to the direction input
	if (direction == 'l')
	{ snake.insert(snake.begin(), CharPosition(snake[0].x-1, snake[0].y)); }
	else if (direction == 'r')
	{ snake.insert(snake.begin(), CharPosition(snake[0].x+1, snake[0].y)); }
	else if (direction == 'u')
	{ snake.insert(snake.begin(), CharPosition(snake[0].x, snake[0].y-1)); }
	else if (direction == 'd')
	{ snake.insert(snake.begin(), CharPosition(snake[0].x, snake[0].y+1)); }

	// move to the new CharPosition coordinates
	move(snake[0].y, snake[0].x);
	addch(partchar); // add a new head
	refresh();
	return;
}

void Game::PlayGame()
{
	lastPoison=FALSE;

    while(1)
    {

        if (FatalCollision())
        {
            move((maxheight-2)/2,(maxwidth-5)/2);
            printw("GAME OVER");
            break;
        }


        GetsFruit();
				GetsPoison();

				if(lastPoison==TRUE){
					move((maxheight-2)/2,(maxwidth-5)/2);
					printw("GAME OVER");
					break;
				}

        MoveSnake();
        if (direction=='q') //exit
        {
        	break;
        }

        usleep(del); // delay
    }
}

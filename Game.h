#include <iostream>
#include <vector>
#include "Screen.h"

#ifndef GAME_H
#define GAME_H

// Unreal standards
using int32 = int;

struct CharPosition
{
	int32 x, y;
	CharPosition(int32 col, int32 row);
	CharPosition();
};

class Game
{
private:
	Screen screen;
	int32 score, del, maxwidth, maxheight,one,two,a,b,c,d,w1,w2,KeyPressed;
	char direction, partchar, edgechar, fruitchar,poisonchar;
	// partchar is the character representing the snake's body
	// edgechar is the character representing the edge of the game window
	// fruitchar is the character representing the fruit
	// del stands for delay
	bool bEatsFruit;
	bool bEatsPoison;
	bool checkedge;
	bool lastPoison;
	CharPosition fruit; // need to clarify this combination
	CharPosition poison;
	std::vector<CharPosition> snake; // represent the snake's body

	void InitGameWindow();
	void DrawWindow();
	void DrawSnake();
	void PrintScore();
	void PositionFruit();
	void PositionPoison();
	bool FatalCollision();
	void MoveSnake();
	bool GetsFruit();
	bool GetsPoison();
	void GetRandom();

public:
	Game();
	~Game(); // destructor for cleanup and memory deallocation
	void PlayGame();
};

#endif

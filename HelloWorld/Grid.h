#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Square.h"
using namespace std;


class Grid{
private:
	static const int gridWidth = 18;
	static const int gridHeight = 18;
	Square minefield[gridHeight][gridWidth];
public:
	int numMines;
	int clearSquares;
	Grid();
	~Grid();
	void Draw();
	void ChkAdjacent(int cordX, int cordY);
};

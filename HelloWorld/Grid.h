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
	int numMines;
	int clearSquares;
public:
	Grid();
	~Grid();
	int GetGridWidth();
	int GetGridHeight();
	void Draw();
	void PlantMines();
	int ChkAdjacent(int cordX, int cordY);
	void HoverSquare();
	void AssignNumbers();
};

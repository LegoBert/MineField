#pragma once
#include "Play.h"
using namespace std;

class Grid{
private:
	class Square;
	static constexpr int gridWidth = 18;
	static constexpr int gridHight = 18;
	Square minefield[gridWidth * gridHight];
public:
	int numMines;
	int clearSquares;
	Grid(int col, int row);
	~Grid();
	void Draw();
	void ChkAdjacent(int cordX, int cordY);
};

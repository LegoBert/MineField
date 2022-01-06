#include "Grid.h"
#include "Square.h"

Grid::Grid(int col, int row) {
	numMines = 40;
	clearSquares = 0;

	this->minefield = new Square * [row];
	for (int r = 0; r < row; ++r)
	{
		this->minefield[r] = new Square[col];
	}

	for (int x = 0; x < row; ++x)
	{
		for (int y = 0; y < col; ++y)
		{
			this->minefield[x][y] = new Square(y, x);
		}
	}
	// 
	//Set the pos for all sqaures
	for (int i = 0; i < gridWidth; i++)
	{
		for (int j = 0; j < gridHight; j++)
		{
			minefield[j][i].SetPos(i, j);
		}
	}
}

Grid::~Grid() {

}

void Grid::Draw() {
	for (int x = 0; x < gridWidth; x++)
	{
		for (int y = 0; y < gridHight; y++)
		{
			minefield[y][x].Draw();
		}
	}
}

void Grid::ChkAdjacent(int cordX, int cordY) {
	int mineCount = 0;
	for (int x = cordX - 1; x <= cordX + 1; x++) {
		for (int y = cordY - 1; y <= cordX + 1; y++) {
			if (minefield[y][x].HasMine()) mineCount++;
		}
	}


}




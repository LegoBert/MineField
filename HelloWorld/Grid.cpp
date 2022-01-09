#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Grid.h"

Grid::Grid() {
	numMines = 50;
	clearSquares = 0;
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			minefield[y][x].SetX(x);
			minefield[y][x].SetY(y);
			minefield[y][x].SetPos(x,y);
		}
	}
}

Grid::~Grid() {

}

void Grid::Draw() {
	for (int x = 0; x < gridWidth; x++)
	{
		for (int y = 0; y < gridHeight; y++)
		{
			minefield[y][x].Draw();
		}
	}
}

int Grid::GetGridWidth() { return gridWidth; }
int Grid::GetGridHeight() { return gridHeight; }

void Grid::PlantMines() {
	int minesLeft = numMines;
	while (minesLeft > 0) {
		int x = Play::RandomRollRange(0, gridWidth-1);
		int y = Play::RandomRollRange(0, gridHeight-1);
		if (minefield[y][x].HasMine()==false) {
			minefield[y][x].PlantMine();
			minesLeft--;
		}
	}
}

int Grid::ChkAdjacent(int cordX, int cordY) {
	int mineCount = 0;
	for (int x = cordX - 1; x <= cordX + 1; x++) {
		for (int y = cordY - 1; y <= cordY + 1; y++) {
			if (minefield[y][x].HasMine() && !(x == -1 || y ==-1 || x == gridWidth || y == gridHeight)) mineCount++;
		}
	}
	minefield[cordY][cordX].SetNeighborCount(mineCount);
	return mineCount;
}

void Grid::HoverSquare() {
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			minefield[y][x].Hover();
		}
	}
}

void Grid::AssignNumbers() {
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			ChkAdjacent(x, y);
		}
	}
}




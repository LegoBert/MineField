#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Grid.h"

Grid::Grid() {
	numMines = 50;
	clearSquares = 0;
	firstClick = true;

	minefield = new Square * [gridHeight];
	for (int i = 0; i < gridHeight; ++i) {
		minefield[i] = new Square[gridWidth];
	}

	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			minefield[y][x].SetX(x);
			minefield[y][x].SetY(y);
			minefield[y][x].SetPos(x,y);
		}
	}
}

Grid::~Grid() {
	delete[] minefield;
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

// Function for planting mines
void Grid::PlantMines() {
	int minesLeft = numMines;
	while (minesLeft > 0) {
		int x = Play::RandomRollRange(0, gridWidth-1);
		int y = Play::RandomRollRange(0, gridHeight-1);
		if (minefield[y][x].HasMine() == false) {
			minefield[y][x].SetMine(true);
			minesLeft--;
		}
	}
	AssignNumbers();	// Adding the adjacent mine count while I'm at it
}

// This function goes through the array and adds the number adjacent mine
void Grid::AssignNumbers() {
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			ChkAdjacent(x, y);
		}
	}
}

// This function counts and adds the adjacent number of mines
int Grid::ChkAdjacent(int cordX, int cordY) {
	int mineCount = 0;
	for (int x = cordX - 1; x <= cordX + 1; x++) {
		for (int y = cordY - 1; y <= cordY + 1; y++) {
			if (!(x < 0 || y < 0 || x >= gridWidth || y >= gridHeight)) {
				if (minefield[y][x].HasMine()) mineCount++;
			}
		}
	}
	minefield[cordY][cordX].SetNeighborCount(mineCount);
	return mineCount;
}

// This function checks which square the mouse is over
void Grid::Hover() {
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			minefield[y][x].Hover();
		}
	}
}

// This function clears the squares around a clear square
void Grid::ClearSquare() {
	for (int x = 0; x < gridWidth; x++)
	{
		for (int y = 0; y < gridHeight; y++)
		{
			Square mine = minefield[y][x];
			if (mine.GetNeighborCount() == 0 && !mine.GetHidden()) {
				for (int cordX = x  - 1; cordX <= x + 1; cordX++) {
					for (int cordY = y - 1; cordY <= y + 1; cordY++) {
						if(!(cordX < 0 || cordY < 0 || cordX >= gridWidth || cordY >= gridHeight)) {
							minefield[cordY][cordX].SetHidden(false);
						}
					}
				}
			}
		}
	}
}





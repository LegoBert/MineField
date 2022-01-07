#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Grid.h"

Grid::Grid() {
	numMines = 40;
	clearSquares = 0;
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			minefield[y][x].SetX(x);
			minefield[y][x].SetY(y);
			minefield[y][x].SetPos(x,y);
			minefield[y][x].SetState(SquareState::Hidden);
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

void Grid::ChkAdjacent(int cordX, int cordY) {
	int mineCount = 0;
	for (int x = cordX - 1; x <= cordX + 1; x++) {
		for (int y = cordY - 1; y <= cordX + 1; y++) {
			if (minefield[y][x].HasMine()) mineCount++;
		}
	}


}




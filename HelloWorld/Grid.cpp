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

void Grid::ChkAdjacent(int cordX, int cordY) {
	int mineCount = 0;
	for (int x = cordX - 1; x <= cordX + 1; x++) {
		for (int y = cordY - 1; y <= cordX + 1; y++) {
			if (minefield[y][x].HasMine()) mineCount++;
		}
	}


}




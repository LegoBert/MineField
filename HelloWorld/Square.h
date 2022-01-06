#pragma once
#include "Play.h"
using namespace std;

enum SquareState {
	Zero,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Hidden,
	Flag,
	Mine
};

class Square   {
private:
	Point2D pos;
	SquareState state;
	bool mine;
	int neighborCount = 0;				// how many mines does the neighbors have?
	int _col;
	int _row;
public:
	Square(int col, int row);
	void Draw();
	void SetPos(int cordX, int cordY);
	void SetState(SquareState s);
	void PlantMine();
	bool HasMine();
};
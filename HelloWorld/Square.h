#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
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
	Mine,
};

class Square   {
private:
	Point2D pos;
	SquareState state;
	bool mine;
	int neighborCount = 0;				// how many mines does the neighbors have?
	int cX;
	int cY;
public:
	Square();
	void Draw();
	void SetX(int);
	void SetY(int);
	int GetX();
	int GetY();
	void SetNeighborCount(int n);
	int GetNeighborCount();
	void SetPos(int,int);
	Point2D GetPos();
	void SetState(SquareState s);
	void PlantMine();
	bool HasMine();
	void Hover();
};
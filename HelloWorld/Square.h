#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
using namespace std;



class Square   {
private:
	Point2D pos;					// Position for drawing and checking if the mouse is over the square
	bool mine, hidden, flagged;		// Booleans for the state of the square
	int neighborCount = 0;			// Adjacent amount of mines
	int cX, cY;						// The Squares cordinates in the array for setting its draw position
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

	void SetMine(bool);
	bool HasMine();

	void SetFlagged(bool);
	bool GetFlagged();

	void SetHidden(bool);
	bool GetHidden();

	void Hover();
};
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Square.h"

Square::Square(){
	pos = { 0,0 };
	mine = false;
	flagged = false;
	hidden = true;
	cX = 0;
	cY = 0;
	neighborCount = 0;
	scale = 2;
}

void Square::Draw() {
	if (!hidden) {
		if (mine) Play::DrawSpriteRotated("mine", pos, 0, 0, scale, 1.0f);
		else if (neighborCount == 0) Play::DrawSpriteRotated("zero", pos, 0, 0, scale, 1.0f);
		else if (neighborCount == 1) Play::DrawSpriteRotated("one", pos, 0, 0, scale, 1.0f);
		else if (neighborCount == 2) Play::DrawSpriteRotated("two", pos, 0, 0, scale, 1.0f);
		else if (neighborCount == 3) Play::DrawSpriteRotated("three", pos, 0, 0, scale, 1.0f);
		else if (neighborCount == 4) Play::DrawSpriteRotated("four", pos, 0, 0, scale, 1.0f);
		else if (neighborCount == 5) Play::DrawSpriteRotated("five", pos, 0, 0, scale, 1.0f);
		else if (neighborCount == 6) Play::DrawSpriteRotated("six", pos, 0, 0, scale, 1.0f);
		else if (neighborCount == 7) Play::DrawSpriteRotated("seven", pos, 0, 0, scale, 1.0f);
		else if (neighborCount == 8) Play::DrawSpriteRotated("eight", pos, 0, 0, scale, 1.0f);
	}
	else if (flagged) {
		Play::DrawSpriteRotated("flag", pos, 0, 0, scale, 1.0f);
	}
	else {
		Play::DrawSpriteRotated("hidden", pos, 0, 0, scale, 1.0f);
	}
}

// Get/Set Functions
void Square::SetX(int x) { cX = x; }
void Square::SetY(int y) { cY = y; }
int Square::GetX() { return cX; }
int Square::GetY() { return cY; }
void Square::SetNeighborCount(int n) { neighborCount = n; }
int Square::GetNeighborCount() { return neighborCount; }
void Square::SetPos(int x, int y) { int offset = 14; pos = { x * offset,y * offset}; }
Point2D Square::GetPos() { return pos; }
void Square::SetMine(bool b) { mine = b; }
bool Square::HasMine() { return mine; }
void Square::SetFlagged(bool b) { flagged = b; }
bool Square::GetFlagged() { return flagged;  }
void Square::SetHidden(bool b) { hidden = b; }
bool Square::GetHidden() { return hidden; }

// Checks if the player clicks on a square
void Square::Hover() {
	if ((pos.x < Play::GetMousePos().x && Play::GetMousePos().x < pos.x + 15) && (pos.y < Play::GetMousePos().y && Play::GetMousePos().y < pos.y + 15)) {	// Is the mouse over the square?
		if (Play::KeyPressed(VK_LBUTTON) && !flagged) hidden = false;	// Sets hidden to false if the player left-clicks and the square isn't flagged 
		if (Play::KeyPressed(VK_RBUTTON) && (hidden || flagged)) {	
			if (!flagged) {
				flagged = true;		// Sets flagged to true if player right-clicks and the square isn't flagged 
			}
			else
			{
				flagged = false;	// Sets flagged to false if player right-clicks and the square is flagged 
			}
		}
	}
}
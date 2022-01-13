#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Mine.h"

Mine::Mine() {
	pos = { 0,0 };
	flagged = false;
	mine = true;
	hidden = true;
	cX = 0;
	cY = 0;
	neighborCount = 0;
	scale = 2;
}

void Mine::Draw() {
	if (flagged) {
		Play::DrawSpriteRotated("flag", pos, 0, 0, scale, 1.0f);
	}
	else if (hidden) 
	{
		Play::DrawSpriteRotated("hidden", pos, 0, 0, scale, 1.0f);
	}
	else 
	{
		Play::DrawSpriteRotated("mine", pos, 0, 0, scale, 1.0f);
	}
}


void Mine::Hover() {
	if ((pos.x < Play::GetMousePos().x && Play::GetMousePos().x < pos.x + 15) && (pos.y < Play::GetMousePos().y && Play::GetMousePos().y < pos.y + 15)) {	// Is the mouse over the square?
		if (Play::KeyPressed(VK_LBUTTON) && !flagged) {
			hidden = false;	// Sets hidden to false if the player left-clicks and the square isn't flagged 
		}
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
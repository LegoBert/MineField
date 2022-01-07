#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Square.h"

Square::Square(){
	pos = { 0,0 };
	mine = false;
	state = SquareState::Hidden;
	cX = 0;
	cY = 0;
	neighborCount = 0;
}

void Square::Draw() {
	if (state == SquareState::Hidden) Play::DrawRect(pos, { pos.x + 14, pos.y + 14 }, Play::cGreen, 1);
	if (mine) Play::DrawRect(pos, { pos.x + 14, pos.y + 14 }, Play::cRed, 1);
	/*float scale = 2.5;
	if(state == SquareState::Zero) Play::DrawSpriteRotated("zero", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::One) Play::DrawSpriteRotated("one", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Two) Play::DrawSpriteRotated("two", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Three) Play::DrawSpriteRotated("three", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Four) Play::DrawSpriteRotated("four", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Five) Play::DrawSpriteRotated("five", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Six) Play::DrawSpriteRotated("six", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Seven) Play::DrawSpriteRotated("seven", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Eight) Play::DrawSpriteRotated("eight", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Hidden) Play::DrawSpriteRotated("hidden", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Flag) Play::DrawSpriteRotated("flag", pos, 0, 0, scale, 1.0f);
	if (state == SquareState::Mine) Play::DrawSpriteRotated("mine", pos, 0, 0, scale, 1.0f);*/
	
}

void Square::SetX(int x) { cX = x; }
void Square::SetY(int y) { cY = y; }
int Square::GetX() { return cX; }
int Square::GetY() { return cY; }


void Square::SetPos(int x, int y) {
	int offset = 16;
	pos = { x * offset+10,y * offset +10};
}

void Square::SetState(SquareState s) {
	state = s;
}

void Square::PlantMine() { 
	mine = true; 
}

bool Square::HasMine()  {
	return mine;
}
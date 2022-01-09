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
	float scale = 2;
	if(state == SquareState::Zero) Play::DrawSpriteRotated("zero", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::One) Play::DrawSpriteRotated("one", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Two) Play::DrawSpriteRotated("two", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Three) Play::DrawSpriteRotated("three", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Four) Play::DrawSpriteRotated("four", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Flag) Play::DrawSpriteRotated("flag", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Mine) Play::DrawSpriteRotated("mine", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Five) Play::DrawSpriteRotated("five", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Six) Play::DrawSpriteRotated("six", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Seven) Play::DrawSpriteRotated("seven", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Eight) Play::DrawSpriteRotated("eight", pos, 0, 0, scale, 1.0f);
	else if (state == SquareState::Hidden) Play::DrawSpriteRotated("hidden", pos, 0, 0, scale, 1.0f);
}

void Square::SetX(int x) { cX = x; }
void Square::SetY(int y) { cY = y; }
int Square::GetX() { return cX; }
int Square::GetY() { return cY; }
void Square::SetNeighborCount(int n) { neighborCount = n; }
int Square::GetNeighborCount() { return neighborCount; }
void Square::SetPos(int x, int y) {
	int offset = 14;
	pos = { x * offset,y * offset};
}
Point2D Square::GetPos() { return pos; }
void Square::SetState(SquareState s) { state = s; }
SquareState Square::GetState() { return state; }
void Square::PlantMine() { mine = true; }
bool Square::HasMine()  { return mine; }

void Square::Hover() {
	if ((pos.x < Play::GetMousePos().x && Play::GetMousePos().x < pos.x + 15) && (pos.y < Play::GetMousePos().y&& Play::GetMousePos().y < pos.y + 15)) {
		if (Play::KeyPressed(VK_LBUTTON) && state != SquareState::Flag) UpdateSquare();
		if (Play::KeyPressed(VK_RBUTTON) && (state == SquareState::Hidden || state == SquareState::Flag)) {
			if (state != SquareState::Flag) {
				state = SquareState::Flag;
			}
			else
			{
				state = SquareState::Hidden;
			}
		}
	}
}

void Square::UpdateSquare() {
	if (neighborCount == 0) SetState(SquareState::Zero);
	if (neighborCount == 1) SetState(SquareState::One);
	if (neighborCount == 2) SetState(SquareState::Two);
	if (neighborCount == 3) SetState(SquareState::Three);
	if (neighborCount == 4) SetState(SquareState::Four);
	if (neighborCount == 5) SetState(SquareState::Five);
	if (neighborCount == 6) SetState(SquareState::Six);
	if (neighborCount == 7) SetState(SquareState::Seven);
	if (neighborCount == 8) SetState(SquareState::Eight);
	if (mine) SetState(SquareState::Mine);
}
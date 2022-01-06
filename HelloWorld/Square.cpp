#include "Square.h"
#include <assert.h>

Square::Square(int col, int row){
	pos = { 0,0 };
	mine = false;
	state = Hidden;
	this->_col = col;
	this->_row = row;
}

void Square::Draw() {
	float scale = 2.5;
	if(state == Zero) Play::DrawSpriteRotated("zero", pos, 0, 0, scale, 1.0f);
	if (state == One) Play::DrawSpriteRotated("one", pos, 0, 0, scale, 1.0f);
	if (state == Two) Play::DrawSpriteRotated("two", pos, 0, 0, scale, 1.0f);
	if (state == Three) Play::DrawSpriteRotated("three", pos, 0, 0, scale, 1.0f);
	if (state == Four) Play::DrawSpriteRotated("four", pos, 0, 0, scale, 1.0f);
	if (state == Five) Play::DrawSpriteRotated("five", pos, 0, 0, scale, 1.0f);
	if (state == Six) Play::DrawSpriteRotated("six", pos, 0, 0, scale, 1.0f);
	if (state == Seven) Play::DrawSpriteRotated("seven", pos, 0, 0, scale, 1.0f);
	if (state == Eight) Play::DrawSpriteRotated("eight", pos, 0, 0, scale, 1.0f);
	if (state == Hidden) Play::DrawSpriteRotated("hidden", pos, 0, 0, scale, 1.0f);
	if (state == Flag) Play::DrawSpriteRotated("flag", pos, 0, 0, scale, 1.0f);
	if (state == Mine) Play::DrawSpriteRotated("mine", pos, 0, 0, scale, 1.0f);
}

void Square::SetPos(int cordX, int cordY) {
	int offset = 16;
	pos = { cordX * offset,cordY * offset };
}

void Square::SetState(SquareState s) {
	state = s;
}

void Square::PlantMine() { 
	assert(!mine);
	mine = true; 
}

bool Square::HasMine()  {
	return mine;
}
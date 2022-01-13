#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Square.h"
using namespace std;



class Mine : public Square {
public:
	Mine();
	void Draw() override;
	void Hover() override;
};
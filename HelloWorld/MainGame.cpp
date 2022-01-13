#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Grid.h"
#include "Mine.h"
#include "Square.h"

Grid grid;
bool lost = false;
bool win = false;

int DISPLAY_WIDTH = grid.GetGridWidth()*14;
int DISPLAY_HEIGHT = grid.GetGridHeight() * 14;
int DISPLAY_SCALE = 2.5;

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
	grid.PlantMines();
	//Play::PlayAudio("music");
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::ClearDrawingBuffer( Play::cBlack );
	if(!lost && !win) grid.Hover();
	grid.ClearSquare();
	grid.Draw();

	lost = grid.Lose();
	win = grid.Win();
	if (win) {
		Play::DrawRect({ 0, DISPLAY_HEIGHT / 2 - 10 }, { DISPLAY_WIDTH, DISPLAY_HEIGHT / 2 + 10 }, Play::cBlack, true);
		Play::DrawDebugText({ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, "You Win!", Play::cWhite, true);
	}
	else if (lost) {
		Play::DrawRect({ 0, DISPLAY_HEIGHT / 2 - 10}, { DISPLAY_WIDTH, DISPLAY_HEIGHT / 2 + 10}, Play::cBlack, true);
		Play::DrawDebugText({ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, "You lose!", Play::cWhite, true);
	}

	Play::PresentDrawingBuffer();
	return Play::KeyDown( VK_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}

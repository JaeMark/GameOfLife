#pragma once
#include "CellGrid.h"

class GameMode {
public:
	enum class GameState{startScreen, playing, paused};
private:
	CellGrid myCellGrid;
	GameState myState{ GameState::startScreen };
public:
	GameMode(const CellGrid& grid)
		: myCellGrid{ grid } {}

};

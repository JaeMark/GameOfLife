#pragma once
#include "Coordinate.h"

class Cell {
public:
	enum class State{dead, alive};
private:
	const Coordinate myCoordinate;
	State myState;
public:
	Cell(const Coordinate& coords, const State& state)
		: myCoordinate{ coords }, myState{ state } {}
	
};

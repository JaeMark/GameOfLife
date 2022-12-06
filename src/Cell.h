#pragma once
#include "Coordinate.h"
#include "ofxColorPicker.h"

class Cell {
public:
	enum class State{dead, alive};
private:
	const Coordinate myCoordinate;
	double myWidth;
	double myHeight;
	State myState;
public:
	Cell(const Coordinate& coords, const double& width, const double& height, const State& state);

	void draw() const;

	void changeState();

	void giveLife();
	void kill();
	bool isAlive() const;
};

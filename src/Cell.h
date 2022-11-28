#pragma once
#include "Coordinate.h"
#include "ofxColorPicker.h"

class Cell {
public:
	enum class State{dead, alive};
private:
	const Coordinate myCoordinate;
	State myState;
public:
	Cell(const Coordinate& coords, const State& state)
		: myCoordinate{ coords }, myState{ state } {}

	void draw() {
		if(myState == State::alive) {
			ofSetColor(0);
		} else if (myState == State::dead) {
			ofSetColor(255);
		}
		ofDrawRectangle(myCoordinate.x, myCoordinate.y, 50, 50);
	}
};

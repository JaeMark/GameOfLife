#pragma once
#include "Coordinate.h"
#include "ofxColorPicker.h"

class Cell {
public:
	enum class State{dead, alive};
private:
	const Coordinate myCoordinate;
	const int mySize;
	State myState;
public:
	Cell(const Coordinate& coords, const int& size,const State& state)
		: myCoordinate{ coords }, mySize{ size }, myState {
		state
	} {}

	void draw() {
		if(myState == State::alive) {
			ofSetColor(0);
		} else if (myState == State::dead) {
			ofSetColor(255);
		}
		ofDrawRectangle(myCoordinate.x, myCoordinate.y, mySize, mySize);
	}
};

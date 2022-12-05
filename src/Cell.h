#pragma once
#include "Coordinate.h"
#include "ofxColorPicker.h"

class Cell {
public:
	enum class State{dead, alive};
private:
	const Coordinate myCoordinate;
	int myWidth;
	int myHeight;
	State myState;
public:
	Cell(const Coordinate& coords, const int& width, const int& height, const State& state)
		: myCoordinate{ coords }, myWidth{ width }, myHeight{ height }, myState {
		state
	} {}

	void draw() {
		if(myState == State::alive) {
			ofSetColor(0);
		} else if (myState == State::dead) {
			ofSetColor(255);
		}
		ofDrawRectangle(myCoordinate.x, myCoordinate.y, myWidth, myHeight);
	}

	void changeState() {
		if (myState == State::alive) {
			myState = State::dead;
		} else if (myState == State::dead) {
			myState = State::alive;
		}
	}

	void giveLife() {
		myState = State::alive;
	}

	void kill() {
		myState = State::dead;
	}

	bool isAlive() const {
		return myState == State::alive;
	}
};

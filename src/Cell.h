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

#include "Cell.h"

Cell::Cell(const Coordinate& coords, const double& width, const double& height, const State& state): myCoordinate{ coords }, myWidth{ width }, myHeight{ height }, myState {
	state
} {}

void Cell::draw() const {
	if(myState == State::alive) {
		ofSetColor(0);
	} else if (myState == State::dead) {
		ofSetColor(255);
	}
	ofDrawRectangle(myCoordinate.x, myCoordinate.y, myWidth, myHeight);
}

void Cell::changeState() {
	if (myState == State::alive) {
		myState = State::dead;
	} else if (myState == State::dead) {
		myState = State::alive;
	}
}

void Cell::giveLife() {
	myState = State::alive;
}

void Cell::kill() {
	myState = State::dead;
}

bool Cell::isAlive() const {
	return myState == State::alive;
}

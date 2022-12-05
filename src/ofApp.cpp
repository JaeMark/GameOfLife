#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(gameWindowSize + GUIOffset, gameWindowSize);
	ofSetRectMode(OF_RECTMODE_CENTER);

	// setup fonts
	ofTrueTypeFont::setGlobalDpi(72);
	// setup generation font
	generation.load("Fonts/LifeIsOkay.ttf", 20, true, true);
	generation.setLineHeight(lineHeight);
	generation.setLetterSpacing(letterSpacing);

	// setup listeners
	playButton.addListener(this, &ofApp::playButtonPressed);
	nextGenButton.addListener(this, &ofApp::nextGenButtonPressed);
	seedButton.addListener(this, &ofApp::seedButtonPressed);
	restartButton.addListener(this, &ofApp::restartButtonPressed);
	gridRow.addListener(this, &ofApp::rowSliderMoved);
	gridColumn.addListener(this, &ofApp::columnSliderMoved);

	// setup GUI
	gui.setup("Game of Life", ofxPanelDefaultFilename, gameWindowSize, 0);
	gui.add(playButton.setup("Play"));
	gui.add(nextGenButton.setup("Next Generation"));
	gui.add(seedButton.setup("Seed Grid"));
	gui.add(restartButton.setup("Restart"));
	gui.add(tickRate.setup("Tick Rate", 2, 1, 4));
	gui.add(gridRow.setup("Grid Row", defaultGridRow, 3, 50));
	gui.add(gridColumn.setup("Grid Column", defaultGridColumn, 3, 50));
}

void ofApp::playButtonPressed() {
	if(gameState == GameState::play) {
		gameState = GameState::pause;
		playButton.setName("Play");
	} else {
		gameState = GameState::play;
		playButton.setName("Pause");
	}
}

void ofApp::nextGenButtonPressed() {
	cellGrid.update();
	++currentGeneration;
}

void ofApp::seedButtonPressed() {

}

void ofApp::restartButtonPressed() {
	gameState = GameState::restart;
	playButton.setName("Play"); // reset play button name
}

void ofApp::rowSliderMoved(int& row) {
	isRowSliderMoved = true;
}

void ofApp::columnSliderMoved(int& column) {
	isColumnSliderMoved = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(frameRate);
	if (gameState == GameState::play && ofGetFrameNum() % (frameRate/tickRate) == 0) {
		cellGrid.update();
		++currentGeneration;
	} else if (gameState == GameState::pause) {
		// do nothing
	} else if (gameState == GameState::restart) {
		cellGrid.reset();
		currentGeneration = 1; // reset generation number
		gameState = GameState::setup;
	} else if (gameState == GameState::setup) {
		// do nothing
		if(isRowSliderMoved) {
			cellGrid.updateGridRow(gridRow);
			isRowSliderMoved = false;
		}
		if(isColumnSliderMoved) {
			cellGrid.updateGridColumn(gridColumn);
			isColumnSliderMoved = false;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw grid
	cellGrid.draw();

	// display current generation
	ofSetColor(225);
	generation.drawString("Generation: " + std::to_string(currentGeneration), gameWindowSize + 10, ofGetHeight() - 10);

	// draw GUI
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		gameState = GameState::play;
	}
	if (key == 'r') {
		gameState = GameState::restart;
	}
	if (key == 'p') {
		gameState = GameState::pause;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(gameState == GameState::setup) {
		cellGrid.changeStateOfCellAt(Coordinate{ static_cast<double>(x), static_cast<double>(y) });
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

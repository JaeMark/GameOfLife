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

	// setup GUI
	gui.setup("Game of Life", ofxPanelDefaultFilename, gameWindowSize, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(defaultFrameRate);
	if (gameState == GameState::play) {
		ofSetFrameRate(playingFrameRate);
		cellGrid.update();
		++currentGeneration;
	} else if (gameState == GameState::pause) {
		// do nothing
	} else if (gameState == GameState::restart) {
		cellGrid.reset();
		currentGeneration = 0; // reset generation number
		gameState = GameState::setup;
	} else if (gameState == GameState::setup) {
		// do nothing
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

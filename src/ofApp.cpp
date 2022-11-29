#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(windowSize, windowSize);
	ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
	if(gameState == GameState::playing) {
		ofSetFrameRate(playingFrameRate);
		/*
		if(!isUpdated) {
			cellGrid.update();
			isUpdated = true;
		}
		*/
		cellGrid.update();
	} else {
		ofSetFrameRate(defaultFrameRate);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	cellGrid.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		gameState = GameState::playing;
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
	if(gameState == GameState::initialization) {
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

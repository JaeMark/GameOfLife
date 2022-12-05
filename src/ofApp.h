#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "CellGrid.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void playButtonPressed();
		void nextGenButtonPressed();
		void seedButtonPressed();
		void restartButtonPressed();
		void rowSliderMoved(int& row);
		void columnSliderMoved(int& column);

private:
	const int gameWindowSize{ 800 };
	const int GUIOffset{ 200 };
	const int defaultGridRow{ 25 };
	const int defaultGridColumn{ 25 };
	const int frameRate{ 60 };
	CellGrid cellGrid{ defaultGridRow, defaultGridColumn, gameWindowSize};

	ofTrueTypeFont generation;
	const float lineHeight{ 34.0 };
	const float letterSpacing{ 1.035 };

	enum class GameState{setup, play, pause, restart};
	GameState gameState{ GameState::setup };

	int currentGeneration{ 1 };

	ofxPanel gui;
	ofxButton playButton;
	ofxButton nextGenButton;
	ofxButton seedButton;
	ofxButton restartButton;
	ofxIntSlider tickRate;
	ofxIntSlider gridRow;
	ofxIntSlider gridColumn;

	bool isRowSliderMoved = false;
	bool isColumnSliderMoved = false;

	const float aliveProbability = 0.25;
};

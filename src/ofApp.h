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

private:
	const int gameWindowSize{ 800 };
	const int GUIOffset{ 200 };
	const int gridRow{ 25 };
	const int gridColumn{ 25 };
	const int cellSize{ gameWindowSize/gridRow };
	const int defaultFrameRate{ 60 };
	const int playingFrameRate{ 1 };
	CellGrid cellGrid{gridRow, gridColumn, cellSize, gameWindowSize};

	ofTrueTypeFont generation;
	const float lineHeight{ 34.0 };
	const float letterSpacing{ 1.035 };

	enum class GameState{setup, play, pause, restart};
	GameState gameState{ GameState::setup };

	bool isUpdated = false;

	int currentGeneration{ 0 };

	ofxPanel gui;
	ofxButton playButton;
};

#pragma once

#include "Cell.h"
#include "CellGrid.h"
#include "ofMain.h"

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

private:
	const int windowSize{ 1000 };
	const int gridRow{ 5 };
	const int gridColumn{ 5 };
	const int gridSize{ windowSize/gridRow };
	const int defaultFrameRate{ 60 };
	const int playingFrameRate{ 1 };
	CellGrid cellGrid{gridRow, gridColumn, gridSize};

	enum class GameState{initialization, playing};
	GameState gameState{ GameState::initialization };

	bool isUpdated = false;
};

#pragma once
#include <vector>
#include "Cell.h"
#include "ofAppRunner.h"

class CellGrid {
	const int myRow;
	const int myColumn;
	const int myGridSize;
	std::vector<std::vector<Cell>> myCells;
public:
	CellGrid(const int& row, const int& column, const int& gridSize)
		: myRow{ row }, myColumn{ column }, myGridSize{ gridSize } {
		intializeGrid();
	}

	void draw() {
		for (auto& cells : myCells) {
			for (auto& cell : cells) {
				cell.draw();
			}
		}
		drawGrid();
		
	}

	void update() {
		
	}

	void changeStateOfCellAt(const Coordinate coord) {
		for (int n{ 0 }; n < myRow; n++) {
			for (int m{ 0 }; m < myColumn; m++) {
				const double lowerYBound = myGridSize * n;
				const double lowerXBound = myGridSize * m;
				const double upperYBound = lowerYBound + myGridSize;
				const double upperXBound = lowerXBound + myGridSize;

				if (coord.x > lowerXBound && coord.x < upperXBound &&
					coord.y > lowerYBound && coord.y < upperYBound) {
					myCells[n][m].changeState();
				}
			}
		}
	}

private:
	void intializeGrid() {
		const Cell::State cellState{ Cell::State::dead }; // initialize all cells as dead
		for (int n{ 0 }; n < myRow; n++) {
			std::vector<Cell> cells; // row of cells
			const double cellPosY = myGridSize * n + myGridSize / 2;
			for (int m{ 0 }; m < myColumn; m++) {
				const double cellPosX = myGridSize * m + myGridSize / 2;
				Coordinate cellCoord{ Coordinate{ cellPosX, cellPosY } };
				cells.emplace_back(Cell{ cellCoord, myGridSize, cellState});
			}
			myCells.push_back(cells);
		}
	}

	void drawGrid() const {
		// draw grid
		ofSetColor(100);
		for (int n{ 0 }; n < myRow; n++) {
			ofDrawLine(0, myGridSize * n, ofGetWidth(), myGridSize * n);
		}
		for (int m{ 0 }; m < myColumn; m++) {
			ofDrawLine(myGridSize * m, 0, myGridSize * m, ofGetHeight());
		}
	}

	void handleRulesOfLife(Coordinate coord) {
		// Any live cell with fewer than two live neighbours dies, as if by underpopulation.

		// Any live cell with two or three live neighbours lives on to the next generation.

		// Any live cell with more than three live neighbours dies, as if by overpopulation.

		// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction 

	}

	void handleEdgeCase() {}
};

#pragma once
#include <vector>
#include "Cell.h"
#include "ofAppRunner.h"

class CellGrid {
	const int myRow;
	const int myColumn;
	const int myGridSize;
	std::vector<std::vector<Cell>> myCells;
	std::vector<std::vector<Cell>> myNextGenCells;
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
		handleRulesOfLife();
		// copy next generation cell grid to the current cell grid
		myCells.clear();
		for (auto& cells : myNextGenCells) {
			myCells.push_back(cells);
		}
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
			myNextGenCells.push_back(cells);
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

	void handleRulesOfLife() {
		for (int n{ 0 }; n < myRow; n++) {
			for (int m{ 0 }; m < myColumn; m++) {
				const int neighborCount{ getNeighborCount(n, m) };
				const bool isCellAlive{ myCells[n][m].isAlive() };
				if (isCellAlive && (neighborCount < 2 || neighborCount > 3)) {
					// any live cell with fewer than two live neighbours dies, as if by underpopulation
					// any live cell with more than three live neighbours dies, as if by overpopulation
					myNextGenCells[n][m].kill();
				}
				else if (isCellAlive && (neighborCount == 2 || neighborCount == 3)) {
					// any live cell with two or three live neighbours lives on to the next generation
					myNextGenCells[n][m].giveLife();
				}
				else if (!isCellAlive && neighborCount == 3) {
					// any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction
					myNextGenCells[n][m].giveLife();
				}
			}
		}
	}

	int getNeighborCount(int row, int column) const {
		int neighborCount{ 0 };
		for (int n{ row - 1 }; n <= row + 1; n++) {
			for (int m{ column - 1 }; m <= column + 1; m++) {
				// skip cells outside of the grid and itself
				if(n > -1 && n < myRow && m > -1 && m < myColumn) {
					if (!(n == row && m == column) && myCells[n][m].isAlive()) {
						++neighborCount;
					}
				}
			}
		}
		return neighborCount;
	}
};

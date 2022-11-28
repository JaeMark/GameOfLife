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
	}

private:
	void intializeGrid() {
		// create cell grid
		double cellPosX = 0;
		double cellPosY = 0;
		const Cell::State cellState{ Cell::State::dead }; // initialize all cells as dead
		for (int n{ 0 }; n < myRow; n++) {
			std::vector<Cell> cells; // row of cells
			cellPosY = myGridSize * n;
			for (int m{ 0 }; m < myColumn; m++) {
				cellPosX = myGridSize * m;
				Coordinate cellCoord{ Coordinate{ cellPosX, cellPosY } };
				if(m % 2 == 0) {
					cells.emplace_back(Cell{ cellCoord, Cell::State::alive });
				} else {
					cells.emplace_back(Cell{ cellCoord, cellState });
				}
			}
			myCells.push_back(cells);
		}
	}
};

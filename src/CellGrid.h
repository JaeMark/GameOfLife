#pragma once
#include <vector>
#include "Cell.h"

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

private:
	void intializeGrid() {
		
	}
};

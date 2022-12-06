#pragma once
#include <vector>
#include "Cell.h"
#include "ofAppRunner.h"

class CellGrid {
	int myRow;
	int myColumn;
	int myGridSize;
	double myCellWidth{ 0 };
	double myCellHeight{ 0 };
	std::vector<std::vector<Cell>> myCells;
	std::vector<std::vector<Cell>> myNextGenCells;
public:
	CellGrid(const int& row, const int& column, const int& gridSize);

	void draw() const;

	void update();
	void updateGridRow(const int row);
	void updateGridColumn(const int column);

	void reset();

	void seed(const float lifeProbability);
	void changeStateOfCellAt(const Coordinate coord);

private:
	void initializeGrid();
	void drawGridLines() const;

	void handleRulesOfLife();
	int getNeighborCount(int row, int column) const;
};

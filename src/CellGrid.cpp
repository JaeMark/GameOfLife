#include "CellGrid.h"

CellGrid::CellGrid(const int& row, const int& column, const int& gridSize): myRow{ row }, myColumn{ column }, myGridSize{ gridSize } {
	initializeGrid();
}

void CellGrid::draw() const {
	for (auto& cells : myCells) {
		for (auto& cell : cells) {
			cell.draw();
		}
	}
	drawGridLines();
}

void CellGrid::update() {
	handleRulesOfLife();
	// copy next generation cell grid to the current cell grid
	myCells.clear();
	for (auto& cells : myNextGenCells) {
		myCells.push_back(cells);
	}
}

void CellGrid::updateGridRow(const int row) {
	myRow = row;
	reset();
}

void CellGrid::updateGridColumn(const int column) {
	myColumn = column;
	reset();
}

void CellGrid::reset() {
	myCells.clear();
	myNextGenCells.clear();
	initializeGrid();
}

void CellGrid::seed(const float lifeProbability) {
	for (auto& cells : myCells) {
		for (auto& cell : cells) {
			const float randomNum = ofRandom(0, 1);
			if (randomNum < lifeProbability) {
				cell.giveLife();
			}
		}
	}
}

void CellGrid::changeStateOfCellAt(const Coordinate coord) {
	for (int n{ 0 }; n < myRow; n++) {
		for (int m{ 0 }; m < myColumn; m++) {
			// find the boundaries of the current cell
			const double lowerYBound = myCellHeight * n;
			const double lowerXBound = myCellWidth * m;
			const double upperYBound = lowerYBound + myCellHeight;
			const double upperXBound = lowerXBound + myCellWidth;

			// check if coord is within the current cell's boundaries
			if (coord.x > lowerXBound && coord.x < upperXBound &&
				coord.y > lowerYBound && coord.y < upperYBound) {
				myCells[n][m].changeState();
			}
		}
	}
}

void CellGrid::initializeGrid() {
	// set the cell dimensions
	myCellWidth = static_cast<double>(myGridSize) / myColumn;
	myCellHeight = static_cast<double>(myGridSize) / myRow;
	const Cell::State cellState{ Cell::State::dead }; // initialize all cells as dead
	for (int n{ 0 }; n < myRow; n++) {
		std::vector<Cell> cells; // row of cells
		const double cellPosY = myCellHeight * n + myCellHeight / 2;
		for (int m{ 0 }; m < myColumn; m++) {
			const double cellPosX = myCellWidth * m + myCellWidth / 2;
			Coordinate cellCoord{ Coordinate{ cellPosX, cellPosY } };
			cells.emplace_back(Cell{ cellCoord, myCellWidth, myCellHeight, cellState});
		}
		myCells.push_back(cells);
		myNextGenCells.push_back(cells); 
	}
}

void CellGrid::drawGridLines() const {
	ofSetColor(100);
	for (int n{ 0 }; n < myRow; n++) {
		ofDrawLine(0, myCellHeight * n, myGridSize, myCellHeight * n);
	}
	for (int m{ 0 }; m < myColumn; m++) {
		ofDrawLine(myCellWidth * m, 0, myCellWidth * m, myGridSize);
	}
}

void CellGrid::handleRulesOfLife() {
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

int CellGrid::getNeighborCount(int row, int column) const {
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

#include "../include/Cell.h"
/*
class Cell {
private:
	int mRow;
	int mColumn;
	bool mIsMine;
	bool mIsRevelead;
	bool mIsFlag;
	int mAdjacentMines;
public:
	Cell(int row, int column);

        int getRow();
        int getColumn();

	void placeMine();
	bool hasMine();
	
	void placeFlag();
	bool hasFlagd();
	void removeFlag();
	
	void reveal();
	bool isReaveled();
	
	int getAdjacentMines();

~Cell();
*/

Cell::Cell(int row, int column) : 
    mRow(row), mColumn(column), mIsMine(false), mIsRevelead(false), mIsFlag(false), mAdjacentMines(0) {
}

int Cell::getRow() {
    return mRow;
}

int Cell::getColumn() {
    return mColumn;
}

void Cell::placeMine() {
    mIsMine = true;
}

bool Cell::hasMine() {
    return mIsMine;
}

void Cell::toggleFlag() {
    mIsFlag = !mIsFlag;
}

bool Cell::hasFlag() {
    return mIsFlag;
}


void Cell::reveal() {
    mIsRevelead = true;
}

bool Cell::isRevelead() {
    return mIsRevelead;
}


void Cell::setAdjacentMines(int nMines) {
    mAdjacentMines = nMines;
}

int Cell::getAdjacentMines() {
    return mAdjacentMines;
}

Cell::~Cell() {}

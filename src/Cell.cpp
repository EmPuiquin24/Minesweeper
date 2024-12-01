#include "../include/Cell.h"

Cell::Cell(int row, int column) :
    mRow(row), mColumn(column), mIsMine(false), mIsRevealed(false), mIsFlag(false), mAdjacentMines(0) {
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
    mIsRevealed = true;
}

bool Cell::isRevealed() {
    return mIsRevealed;
}


void Cell::setAdjacentMines(int nMines) {
    mAdjacentMines = nMines;
}

int Cell::getAdjacentMines() {
    return mAdjacentMines;
}

Cell::~Cell() {}

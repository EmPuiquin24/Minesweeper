#include "../include/Board.h"
#include <iostream>

Board::Board(std::string difficulty) {
    mDifficulty = difficulty;

    if (difficulty == "Fácil") {
        mRows = 6;
        mColumns = 6;
        mTotalMines =  rand() % 3 + 3; 

    } else if (difficulty == "Intermedio") {
        mRows = 8;
        mColumns = 8;
        mTotalMines =  rand() % 5 + 8;

    } else {
        mRows = 10;
        mColumns = 10;
        mTotalMines = rand() % 6 + 15;
    }
    mUnCells = mRows * mColumns - mTotalMines;
    mTotalFlags = 0;
}

int Board::getRows() {
    return mRows;
}

int Board::getColumns() {
    return mColumns;
}


void Board::GenerateBoard() {
    MainBoard.resize(mRows, std::vector<Cell>(mColumns, Cell(0,0)));
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mColumns; j++) {
            MainBoard[i][j] = Cell(i,j);
        }
    }
}


Cell& Board::getCell(int row, int column) {
    return MainBoard[row][column];
}


void Board::placeMines(Cell& cell) {
    int i = 0; 
    while (i < mTotalMines) {
        int rCellRow = rand() % mRows;
        int rCellColumn = rand() % mColumns;

        Cell& rCell = MainBoard[rCellRow][rCellColumn];
        if (abs(cell.getRow() - rCell.getRow()) > 1 && abs(cell.getColumn() - rCell.getColumn()) > 1 && !rCell.hasMine())  {
            rCell.placeMine();
            i++;
        }
    }

}

void Board::calculateAdjacentMines() { // Perdóname Dios por este bucle
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mColumns; j++) {
 
            int nMines = 0; 
            Cell& cCell = MainBoard[i][j];

            if (!cCell.hasMine()) {
                for (int m = -1; m <= 1;  m++) {
                    for (int n = -1; n <= 1; n++) {
                            int nearRow = i + m;
                            int nearColumn = j + n;
                        if (nearRow >= 0 && nearRow < mRows && nearColumn >= 0 && nearColumn < mColumns) {
                            if (MainBoard[nearRow][nearColumn].hasMine())  {
                                nMines++;
                            }
                        }
                    }
                }
                cCell.setAdjacentMines(nMines);
            }
        }
    }
}


void Board::decreaseUnCells() {
    mUnCells--;
}

int Board::getUnCells() {
    return mUnCells;
}

void Board::revealCell(int row, int column) {

    Cell& cell = MainBoard[row][column];

    if (!cell.isRevelead() && !cell.hasFlag()) {

        cell.reveal();

       // Esto revela todas las casillas adjacentes
        if (cell.getAdjacentMines() == 0) { // Recurvisidad :money_mouth:
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i != 0 || j != 0) {
                    revealCell(row + i, column + j); // Esto no debería fallar porque solo se ejecuta si la casilla es 0
                        // Y si una casilla es 0, siempre se garantiza que sus adjacentes no sean minas.
                    }
                }
            }
        }
    }

}

int Board::getMines() {
    return mTotalMines;
}


void Board::flagCell(int row, int column, int& totalflags) {
    Cell& cell = MainBoard[row][column];

    if (!cell.isRevelead()) {
        cell.toggleFlag();
        if (cell.hasFlag()) {
            totalflags++;
        }
        else {
            totalflags--;
        }
    }
}

int Board::getFlags() {
    return mTotalFlags;
}

    // InGame
void Board::printBoard(bool victory, bool gameOver) {
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mColumns; j++) {
            Cell& cell = MainBoard[i][j];

            if (gameOver && cell.hasMine()) {
                if (victory) {
                    std::cout << "F "; // F al ganar
                } else {
                    std::cout << "X "; // X al perder 
                }
            } else if (!cell.isRevelead()) {
                if (cell.hasFlag()) {
                    std::cout << "F "; // Bandera
                } else {
                    std::cout << "- "; // Celda no revelada
                }
            } else {
                 std::cout << cell.getAdjacentMines() << " "; // Número de minas adyacentes
            }
        }
        std::cout << std::endl;
    }
}

Board::~Board() {}

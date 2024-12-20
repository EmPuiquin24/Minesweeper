#ifndef BOARD_H
#define BOARD_H
// Esto debe contener informaciÃ³n de to_do el tablero: Cantidad de celdas, cantidad de minas.
#include <string>
#include <vector>
#include "Cell.h"

class Board {
private:
    std::string mDifficulty;

    int mRows;
    int mColumns;
    int mTotalMines;
    int mUnCells;
    int mTotalFlags;

    std::vector<std::vector<Cell>> MainBoard;

public:
    Board(std::string difficulty);

    int getRows();
    int getColumns();

    void GenerateBoard();

    Cell& getCell(int row, int column);

    void placeMines(Cell& cell);
    void calculateAdjacentMines();

    int getMines();

    void decreaseUnCells();
    int getUnCells();

    void revealCell(int row, int column);
    void flagCell(int row, int columns);

    void setFlags();
    int getFlags();

    void printBoard(bool victory, bool gameOver);
    ~Board();
};

#endif //BOARD_H

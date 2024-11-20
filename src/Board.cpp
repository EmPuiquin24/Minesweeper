#include "../include/Board.h"





Board::~Board() {}

void Board::generateBoard() {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            MainBoard[i][j] = "-";
        }
    }
}

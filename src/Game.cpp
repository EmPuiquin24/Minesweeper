#include "../include/Game.h"
#include "../include/Cell.h"
#include <iostream>

Game::Game(std::string difficulty) : mBoard(difficulty), mTurns(0), mVictory(false), mGameOver(false) {}

void Game::setVictory() {
    mVictory = true;
}

void Game::setGameOver() {
    mGameOver = true;
}

bool Game::hasWon() {
    return mVictory;
}

bool Game::hasEnd() {
    return mGameOver;
}

void Game::increaseTurns() {
    mTurns++;
}

int Game::getTurns() {
    return mTurns;
}

void Game::StartGame() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "¡El juego ha comenzado!" << std::endl;
    mBoard.GenerateBoard();
    mBoard.printBoard(mVictory, mGameOver);
}


void Game::OneRound() {

    int row, column;
    char mov;

    std::cout << "¡Selecciona una celda!" << std::endl;

    std::cout <<  "Ingresa la fila de la celda: "; 
    std::cin >> row;
    while (mBoard.getRows() < row || row < 0) {
        std::cout << "La fila no se encuentra en un rango válido, intentalo denuevo: ";
        std::cin >> row;
    }

    std::cout << "Ingresa la columna de la celda: ";
    std::cin >> column;
    while (mBoard.getColumns() < row || row < 0) {
        std::cout << "La columna no se encuentra en un rango válido, intentalo denuevo: ";
        std::cin >> column;
    }

    std::cout << "Ingrese la acción: 'D' para descubrir la celda y 'F' para marcarla con una bandera: ";
    std::cin >> mov;
    while (mov != 'D' && mov != 'F') {
        std::cout << "La acción no es válida, intentalo denuevo: ";
        std::cin >> mov;
    }

    Cell& cell = mBoard.getCell(row, column);

    if( mov == 'F') {
        cell.toggleFlag();

        std::cout << "Minas: " << mBoard.getMines() << " | Banderas: " << mBoard.getFlags() << std::endl;
        mBoard.printBoard(mVictory, mGameOver);
        increaseTurns();
    }
    else if(mov == 'D') {
        if (mBoard.getUnCells() + mBoard.getMines() == mBoard.getRows() * mBoard.getColumns()) {
            mBoard.placeMines(cell);
            mBoard.calculateAdjacentMines();
        }
        mBoard.revealCell(row, column);

        if(cell.hasMine()) {
            setGameOver();
            std::cout << "¡Has descubierto una mina!" << std::endl;
            std::cout << "Minas: " << mBoard.getMines() << " | Banderas: " << mBoard.getFlags() << std::endl;

            mBoard.printBoard(mVictory, mGameOver);
        }
        else {
            mBoard.decreaseUnCells();

            if(mBoard.getUnCells() == mBoard.getMines()) {

                setGameOver();
                setVictory();

                std::cout << "¡Felicidades! ¡Has descubierto todas las celdas sin mina!" << std::endl;
                std::cout << "Minas: " << mBoard.getMines() << " | Banderas: " << mBoard.getFlags() << std::endl;
                mBoard.printBoard(mVictory, mGameOver); 
            }
            else {
                std::cout << "Minas: " << mBoard.getMines() << " | Banderas: " << mBoard.getFlags() << std::endl;
                mBoard.printBoard(mVictory, mGameOver);
            }
            increaseTurns();
        }
    }

}





Game::~Game() {}

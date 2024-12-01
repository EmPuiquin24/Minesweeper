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

void Game::showInfo() {
    std::cout << "#Info - Minas: " << mBoard.getMines() << " | Banderas: " << mBoard.getFlags() << " | Turnos: " << mTurns  << std::endl;
    std::cout << std::endl;
}

void Game::StartGame() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "¡El juego ha comenzado!\n" << std::endl;
    mBoard.GenerateBoard();
    mBoard.printBoard(mVictory, mGameOver);
}


void Game::OneRound() {

    int row, column;
    char mov;
    
    std::cout << std::endl;
    std::cout << "Selecciona una celda:" << std::endl;

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

    std::cout << "Ingrese la acción: 'D' para descubrir la celda o 'F' para marcarla con una bandera: ";
    std::cin >> mov;
    while (mov != 'D' && mov != 'F') {
        std::cout << "La acción no es válida, intentalo denuevo: ";
        std::cin >> mov;
    }

    Cell& cell = mBoard.getCell(row, column);

    if( mov == 'F') {
        if (cell.isRevelead()) {
            std::cout << "Error: La celda está revelada, no se puede colocar una bandera." << std::endl;
            std::cout << "--------------------------------" << std::endl;
            showInfo();
            mBoard.printBoard(mVictory, mGameOver);
        }
        else {

            increaseTurns();
            mBoard.flagCell(row,column);
            std::cout << "\n--------------------------------" << std::endl;
            showInfo();
            mBoard.printBoard(mVictory, mGameOver);
        }
    }
    else if(mov == 'D') {
        if (cell.hasFlag() ) {
            std::cout << "Error: Retira la bandera de esta casilla para poder descubrirla" << std::endl;
        }
        else if (cell.isRevelead()) {
            std::cout << "Error: Esta celda ya está descubierta" << std::endl;
        }
        else {
            if (mBoard.getUnCells() == mBoard.getRows() * mBoard.getColumns()) {
                mBoard.placeMines(cell);
                mBoard.calculateAdjacentMines();
            }
            mBoard.revealCell(row, column);

            if(cell.hasMine()) {
                increaseTurns();
                setGameOver();

                std::cout << "-----------------------------------" << std::endl;
                std::cout << "¡Oh,no! Has descubierto una mina D:" << std::endl;

                showInfo();
                mBoard.printBoard(mVictory, mGameOver);
                std::cout << std::endl;
            }
            else {
                increaseTurns();
                if(mBoard.getUnCells() == mBoard.getMines()) {

                    setGameOver();
                    setVictory();

                    std::cout << "--------------------------------------------------------" << std::endl;
                    std::cout << "¡Felicidades, has descubierto todas las celdas sin minas!" << std::endl;
                    showInfo();
                    mBoard.printBoard(mVictory, mGameOver); 
                    std::cout << std::endl;
                }
                else {
                    std::cout << "--------------------------------" << std::endl;
                    showInfo();
                    mBoard.printBoard(mVictory, mGameOver);
                }
            }
        }
    }
}





Game::~Game() {}

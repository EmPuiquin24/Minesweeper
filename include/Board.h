#ifndef BOARD_H
#define BOARD_H 

// Esto debe contener información de todo el tablero: Cantidad de celdas, cantidad de minas.
#include <string>
#include <vector>
class Board {
private:
	int size;
	std::vector<std::vector<std::string>> MainBoard;
	int amountMines;
	int remainingMines;
	int remainingFlags;
	int reveleadCells;
public:
	Board();
	void generateBoard();
	int getRemainingMines();
	int getRemainingFlags();
	int getReavelaedCells();
	~Board();	
};

#endif

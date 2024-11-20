#ifndef CELL_H 
#define CELL_H

// Esto debe contener todas las caracteristicas que puede tener una celda: Con mina, flageada, sin minas y minas adyacentes

class Cell {
private:
	bool hasMine;
	bool isRevelead;
	bool hasFlag;
	int row;
	int column;
	int adjacentMines;
public:
	Cell(int row, int column);
	void placeMine();
	void placeFlag();
	void removeFlag();
	bool isMine();
	bool isFlagged();
	void reveal();
	int getAdjacentMines();
	~Cell();
};

#endif

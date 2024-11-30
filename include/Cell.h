#ifndef CELL_H 
#define CELL_H

// Esto debe contener todas las caracteristicas que puede tener una celda: Con mina, flageada, sin minas y minas adyacentes

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
	
	void toggleFlag();
	bool hasFlag();
		
	void reveal();
	bool isRevelead();

	void setAdjacentMines(int nMines);
	int getAdjacentMines();

~Cell();
};

#endif

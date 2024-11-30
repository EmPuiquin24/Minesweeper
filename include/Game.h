#ifndef GAME_H
#define GAME_H 

#include <string>
#include "Board.h"

class Game {
private:
	Board mBoard;
	int mTurns;
	bool mVictory;
	bool mGameOver; // false si está activo y true cuando pierde o no se esté ejecutando el juego
public:
	Game(std::string difficulty);
	
	void setVictory();
	void setGameOver();
	
	bool hasWon();
	bool hasEnd();
	
	void increaseTurns();
	int getTurns();

	void StartGame();
	void OneRound();

~Game();
};

#endif

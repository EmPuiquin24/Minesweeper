#ifndef GAME_H
#define GAME_H 

#include <string>
#include "Board.h"

class Game {
private:
	Board mBoard;
	int mTurns;
	bool mVictory;
	bool mGameOver;
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

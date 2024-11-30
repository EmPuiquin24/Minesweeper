#ifndef PLAYER_H 
#define	PLAYER_H 

#include <string>
#include <vector>
#include "Game.h"

class Player {
private:
	std::string mName;
	std::string mDifficulty;
	int mMoves;
public:
	Player(std::string name, std::string difficulty, int moves);	

	std::string getName();
	std::string getDifficulty();
	int getMoves() const;

~Player();
};

#endif

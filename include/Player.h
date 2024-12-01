#ifndef PLAYER_H 
#define	PLAYER_H 

#include <string>
#include <vector>
#include "Game.h"

class Player {
private:
	std::string mPlayerName;
	std::string mDifficulty;
	int mTurns;
public:
	Player(std::string playerName, std::string difficulty, int turns);	

	std::string getName();
	std::string getDifficulty();
	int getTurns() const;

~Player();
};

#endif

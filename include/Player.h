#ifndef PLAYER_H 
#define	PLAYER_H 

#include <string>
#include <vector>
#include "Game.h"

class Player {
private:
	std::string name;
	std::string difficulty;
	int moves;
public:
	Player(std::string name, std::string difficulty, int moves);	
	std::string getName();
	std::string getDifficulty();
	int getMoves() const;
	~Player();
};

#endif

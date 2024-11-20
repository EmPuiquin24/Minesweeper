#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "Player.h"

#include <string>

class Leaderboard {
private:
	std::string filename;
public:
	Leaderboard(std::string filename);
	void addPlayer(Player& player);
	void displayLeaderboard();
	~Leaderboard();
};

#endif

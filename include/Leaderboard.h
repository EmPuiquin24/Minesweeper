#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "Player.h"

#include <string>
#include <vector>

class Leaderboard {
private:
	std::string filename;
	std::vector<Player> player;
public:
	Leaderboard(std::string filename);
	void addPlayer(Player& player);
	void displayLeaderboard();
};

#endif

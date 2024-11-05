#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <nlohmann/json.hpp> // This is a external library. sudo pacman -S nlohmann-json
using json = nlohmann::json;

class Leaderboard {

private:



public:
	void save();
	void load();
	void add();

};

#endif

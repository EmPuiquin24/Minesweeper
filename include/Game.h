#ifndef GAME_H
#define GAME_H 

#include <string>

class Game {
protected:
	std::string status; // active, lose, neutral
	std::string difficulty;	 // fácil, intermedio, difícil
public:
	Game();
	void StartGame();
	std::string getStatus();
	std::string getDifficulty();
	~Game();
};

#endif

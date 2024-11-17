#include "../include/Player.h"

Player::Player(std::string name, std::string difficulty, int moves) : name(name), difficulty(difficulty), moves(moves) {}

std::string Player::getName() { return name; }

std::string Player::getDifficulty() { return difficulty; }

int Player::getMoves() const { return moves; }


Player::~Player() {}


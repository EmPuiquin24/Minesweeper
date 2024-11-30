#include "../include/Player.h"

Player::Player(std::string name, std::string difficulty, int moves) : 
    mName(name), mDifficulty(difficulty), mMoves(moves) {}

std::string Player::getName() { 
    return mName; 
}

std::string Player::getDifficulty() {
    return mDifficulty;
}

int Player::getMoves() const { 
    return mMoves;
}

Player::~Player() {}


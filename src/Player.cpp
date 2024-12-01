#include "../include/Player.h"

Player::Player(std::string playerName, std::string difficulty, int turns) : 
    mPlayerName(playerName), mDifficulty(difficulty), mTurns(turns) {}


std::string Player::getName() { 
    return mPlayerName; 
}

std::string Player::getDifficulty() {
    return mDifficulty;
}

int Player::getTurns() const { 
    return mTurns;
}


Player::~Player() {}


#include "../include/Leaderboard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void InsertPlayer(std::vector<Player>& lista, const Player& player) {

    auto it = std::lower_bound(lista.begin(), lista.end(), player, 
        [](const Player& a, const Player& b) {
            return a.getTurns() < b.getTurns();
        }
    );

    lista.insert(it, player);
}

Leaderboard::Leaderboard(std::string file) : mFilename(file) {}

void Leaderboard::addPlayer(Player &player) {
    // Abrir archivo en modo lectura
    std::ifstream inputFile(mFilename);

    std::string playerName, difficulty;
    int turns;

    std::vector<Player> easyScores;
    std::vector<Player> mediumScores;
    std::vector<Player> hardScores;

    while (inputFile >> playerName >> difficulty >> turns) {
        Player currentPlayer(playerName, difficulty, turns);
        if (difficulty == "Fácil") {
            easyScores.push_back(currentPlayer);
        } else if (difficulty == "Intermedio") {
            easyScores.push_back(currentPlayer);
        } else if (difficulty == "Difícil") {
            easyScores.push_back(currentPlayer);
        }
    }

    inputFile.close(); // Cerrar archivo de entrada

    // Insertar el nuevo jugador en la lista correspondiente
    difficulty = player.getDifficulty();
    if (difficulty == "Fácil") {
        InsertPlayer(easyScores, player);
    }
    else if (difficulty == "Intermedio") {
        InsertPlayer(mediumScores, player);
    }
    else if (difficulty == "Difícil") {
        InsertPlayer(hardScores, player);
    }

    std::ofstream outputFile(mFilename, std::ios::trunc);
    if (!outputFile.is_open()) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return;
    }

    // Escribir los datos en el archivo en orden
    for (Player& p : easyScores) {
        outputFile << p.getName() << " " << p.getDifficulty() << " " << p.getTurns() << std::endl;
    }
    for (Player& p : mediumScores) {
        outputFile << p.getName() << " " << p.getDifficulty() << " " << p.getTurns() << std::endl;
    }
    for (Player& p : hardScores) {
        outputFile << p.getName() << " " << p.getDifficulty() << " " << p.getTurns() << std::endl;
    }

    outputFile.close();
    std::cout << "¡Has sido añadido al salón de la fama!" << std::endl;
}


void Leaderboard::displayLeaderboard() {

        std::cout << "------------------------------" << std::endl;
	std::cout << "| Tabla de mejores jugadores |" << std::endl;
        std::cout << "------------------------------" << std::endl;	

        std::string line;
	std::ifstream file(mFilename);
	
        if (!file.is_open()) {
        std::cerr << "¡Error! No hay nada que mostrar" << std::endl;
        return;
    }

        std::vector<Player> easyPlayers;
	std::vector<Player> mediumPlayers;
	std::vector<Player> hardPlayers;

	std::string playerName, difficulty;
	int turns;
	
	while (file >> playerName >> difficulty >> turns) {

	    Player jugador(playerName, difficulty, turns);

            if (difficulty == "Fácil") {
                easyPlayers.push_back(jugador);
            } else if (difficulty== "Intermedio") {
                mediumPlayers.push_back(jugador);
            } else if (difficulty == "Difícil") {
                hardPlayers.push_back(jugador);
            }
        }

	file.close();

	if (!easyPlayers.empty()) {
        int i = 1;
        std::cout << "Fácil:\n";
        for (auto& jugador : easyPlayers) {
		std::cout << i << "." << jugador.Player::getName() << " - " << jugador.Player::getTurns() << " turnos" << std::endl;
        i++;	
        }
        std::cout << std::endl; 
    }

    if (!mediumPlayers.empty()) {
        int i = 1;
        std::cout << "Intermedio:\n";
        for (auto& jugador : mediumPlayers) {
		std::cout << i << "." << jugador.Player::getName() << " - " << jugador.Player::getTurns() << " turnos" << std::endl;
	i++;	
        }
        std::cout << std::endl;
    }

    if (!hardPlayers.empty()) {
        int i = 1;
        std::cout << "Difícil:\n";
        for (auto& jugador : hardPlayers) {
            std::cout << i << "." << jugador.Player::getName() << " - " << jugador.Player::getTurns() << " turnos" << std::endl;
        i++; 
        }
        std::cout << std::endl;
    }
}

Leaderboard::~Leaderboard() {}

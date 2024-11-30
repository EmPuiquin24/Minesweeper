#include "../include/Leaderboard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void InsertPlayer(std::vector<Player>& lista, const Player& player) {

    auto it = std::lower_bound(lista.begin(), lista.end(), player, 
        [](const Player& a, const Player& b) {
            return a.getMoves() < b.getMoves();
        }
    );

    lista.insert(it, player);
}

Leaderboard::Leaderboard(std::string file) : mFilename(file) {}

void Leaderboard::addPlayer(Player &player) {
    // Abrir archivo en modo lectura
    std::ifstream inputFile(mFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return;
    }

    std::string nombre, dificultad;
    int movimientos;

    std::vector<Player> PuntajesFacil;
    std::vector<Player> PuntajesIntermedio;
    std::vector<Player> PuntajesDificil;

    while (inputFile >> nombre >> dificultad >> movimientos) {
        Player jugador(nombre, dificultad, movimientos);
        if (dificultad == "Fácil") {
            PuntajesFacil.push_back(jugador);
        } else if (dificultad == "Intermedio") {
            PuntajesIntermedio.push_back(jugador);
        } else if (dificultad == "Difícil") {
            PuntajesDificil.push_back(jugador);
        }
    }

    inputFile.close(); // Cerrar archivo de entrada

    // Insertar el nuevo jugador en la lista correspondiente
    dificultad = player.getDifficulty();
    if (dificultad == "Fácil") {
        InsertPlayer(PuntajesFacil, player);
    } else if (dificultad == "Intermedio") {
        InsertPlayer(PuntajesIntermedio, player);
    } else if (dificultad == "Difícil") {
        InsertPlayer(PuntajesDificil, player);
    }

    std::ofstream outputFile(mFilename, std::ios::trunc);
    if (!outputFile.is_open()) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return;
    }

    // Escribir los datos en el archivo en orden
    for (Player& p : PuntajesFacil) {
        outputFile << p.getName() << " " << p.getDifficulty() << " " << p.getMoves() << std::endl;
    }
    for (Player& p : PuntajesIntermedio) {
        outputFile << p.getName() << " " << p.getDifficulty() << " " << p.getMoves() << std::endl;
    }
    for (Player& p : PuntajesDificil) {
        outputFile << p.getName() << " " << p.getDifficulty() << " " << p.getMoves() << std::endl;
    }

    outputFile.close();
    std::cout << "¡Has sido añadido al salón de la fama!" << std::endl;
}

void Leaderboard::displayLeaderboard() {

	std::cout << "Tabla de mejores jugadores:" << std::endl;
	
        std::string line;
	std::ifstream file(mFilename);
	
        std::vector<Player> jugadoresFacil;
	std::vector<Player> jugadoresIntermedio;
	std::vector<Player> jugadoresDificil;

	std::string nombre, dificultad;
	int movimientos;
	
	while (file >> nombre >> dificultad >> movimientos) {

	    Player jugador(nombre, dificultad, movimientos);

            if (dificultad == "Fácil") {
                jugadoresFacil.push_back(jugador);
            } else if (dificultad == "Intermedio") {
                jugadoresIntermedio.push_back(jugador);
            } else if (dificultad == "Difícil") {
                jugadoresDificil.push_back(jugador);
            }
        }

	file.close();

	if (!jugadoresFacil.empty()) {
        int i = 1;
        std::cout << "Fácil:\n";
        for (auto& jugador : jugadoresFacil) {
		std::cout << i << "." << jugador.Player::getName() << " - " << jugador.Player::getMoves() << " turnos" << std::endl;
        i++;	
        }
        std::cout << std::endl; 
    }

    if (!jugadoresIntermedio.empty()) {
        int i = 1;
        std::cout << "Intermedio:\n";
        for (auto& jugador : jugadoresIntermedio) {
		std::cout << i << "." << jugador.Player::getName() << " - " << jugador.Player::getMoves() << " turnos" << std::endl;
	i++;	
        }
        std::cout << std::endl;
    }

    if (!jugadoresDificil.empty()) {
        int i = 1;
        std::cout << "Difícil:\n";
        for (auto& jugador : jugadoresDificil) {
            std::cout << i << "." << jugador.Player::getName() << " - " << jugador.Player::getMoves() << " turnos" << std::endl;
        i++; 
        }
        std::cout << std::endl;
    }
}

Leaderboard::~Leaderboard() {}

#include "../include/Board.h"
#include "../include/Cell.h"
#include "../include/Game.h"
#include "../include/Leaderboard.h"
#include "../include/Player.h"

#include <iostream>

using namespace std;

int main() {

	int GameMode  = 0;
	cout << "$¿Qué quieres hacer?" << endl;
	cout << "1. Jugar" << endl;
	cout << "2. Salón de la fama" << endl;
	cout << "3. Salir" << endl;

	do  {
		cout << "\nIngresa tu opción: ";
		cin >> GameMode;
	} while(GameMode != 1 && GameMode != 2 && GameMode != 3);	
	
	if (GameMode == 1) {
		int difficulty;
		cout << "----------------------" << endl;
		cout << "Escoge la dificultad: " << endl;
		cout << "-Fácil: 1 \n-Intermedio: 2 \n-Difícil: 3 \n";
		cout << ": ";	
		cin >> difficulty;
	}
	else if (GameMode == 2) {

		Leaderboard Leaderboard("../data/leaderboard.txt");
		Leaderboard.displayLeaderboard();
	}
	return 0;
}

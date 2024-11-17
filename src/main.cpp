#include "../include/Leaderboard.h"
#include <iostream>

using namespace std;

int main() {

	int GameMode  = 0;
	cout << "Qué quieres hacer" << endl;
	cout << "1. Jugar" << endl;
	cout << "2. Salón de la fama" << endl;
	cout << "3. Salir" << endl;

	do  {
		cout << "Ingresa tu opción: ";
		cin >> GameMode;
	} while(GameMode != 1 && GameMode != 2 && GameMode != 3);	
	
	if (GameMode == 1) {
		cout << "Elige tu modo de juego" << endl;
	}
	else if (GameMode == 2) {
		Leaderboard Leaderboard("../data/leaderboard.txt");
		Leaderboard.displayLeaderboard();
	}
	return 0;
}

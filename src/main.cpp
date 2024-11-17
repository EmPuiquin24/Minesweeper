#include "../include/Leaderboard.h"

int main() {
	Player jugador("Hector", "Fácil", 15);
	Leaderboard Leaderboard("../data/leaderboard.txt");
	Leaderboard.addPlayer(jugador);
	Leaderboard.displayLeaderboard();

	return 0;
}

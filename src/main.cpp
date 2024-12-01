#include <iostream>
#include <string>

#include "../include/Game.h"
#include "../include/Leaderboard.h"
#include "../include/Player.h"

using namespace std;

int main() {
    // Semilla
    srand(time(nullptr));

    // Título en arte Ascii super necesario
    cout << R"(
___  ________ _   _  _____ _____  _    _ _____ ___________ ___________ 
|  \/  |_   _| \ | ||  ___/  ___|| |  | |  ___|  ___| ___ \  ___| ___ \
| .  . | | | |  \| || |__ \ `--. | |  | | |__ | |__ | |_/ / |__ | |_/ /
| |\/| | | | | . ` ||  __| `--. \| |/\| |  __||  __||  __/|  __||    / 
| |  | |_| |_| |\  || |___/\__/ /\  /\  / |___| |___| |   | |___| |\ \ 
\_|  |_/\___/\_| \_/\____/\____/  \/  \/\____/\____/\_|   \____/\_| \_|
)" << endl;
    cout << "--------------------------------" << endl;
    cout << "| ¡Bienvenido/a al Buscaminas! |" << endl;
    cout << "--------------------------------" << endl;

    // Control de selecciones
    cout << "Seleccione una opción: (Escribe el número de la opción)" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Mejores Jugadores" << endl;
    cout << "3. Salir" << endl;

    int seleccion = 0;
    cout << "Ingresa la opción: ";
    cin >> seleccion;
    while(seleccion > 3 || seleccion < 1) {
        cout << "La opción seleccionada no es válida. Por favor, intentelo otra vez: ";
        cin >> seleccion;
    }

    if (seleccion == 3) {
        cout << "--------------------------------" << endl;
        cout << "¿Tan rápido :( ?" << endl;
        cout << "Vuelve Pronto" << endl;
        cout << "--------------------------------" << endl;
    }
    else if (seleccion == 2) {
        Leaderboard LeaderboardTxT("../data/leaderboard.txt");
        cout << "--------------------------------" << endl;
        LeaderboardTxT.displayLeaderboard();
    }

    else {
        int n = 0;
        string difficulty;
        cout << "--------------------------------" << endl;
        cout << "¡Has elegido jugar! Selecciona la dificultad!" << endl;
        cout << "1. Fácil" << endl;
        cout << "2. Intermedio" << endl;
        cout << "3. Difícil" << endl;
        cout << "Ingresa la opción: ";
        cin >> n;

        while (n > 3 || n < 1) {
            cout << "El nivel de dificultad no existe. Vuelva a intentarlo: " << endl;
        }
        if (n == 1) {
            difficulty = "Fácil";
        }
        else if (n == 2) {
            difficulty = "Intermedio";
        }
        else {
            difficulty = "Difícil";
        }

        Game game(difficulty);

        game.StartGame();
        while (!game.hasEnd()) {
            game.OneRound();
        }
        if (game.hasWon()) {
            string playerName;
            int turns = game.getTurns();

            cout << "Ingresa tu nombre para ser añadido al salón de la fama: ";
            cin >> playerName;

            Player jugador(playerName, difficulty, turns);
            Leaderboard leaderboard("../data/leaderboard.txt");
            leaderboard.addPlayer(jugador);

            cout << "Regresa pronto :)" << endl;
            leaderboard.displayLeaderboard();
        }
    }
    return 0;
}

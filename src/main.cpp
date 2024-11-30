#include <iostream>
#include <string>

#include "../include/Board.h"
#include "../include/Cell.h"
#include "../include/Game.h"
#include "../include/Leaderboard.h"
#include "../include/Player.h"

using namespace std;

int main() {
    // Semilla
    srand(time(nullptr));

    cout << "¡Bienvenido/a al Buscaminas!" << std::endl;

    cout << "Seleccione una opción: (Escribe el número de la opción)" << std::endl;
    cout << "1. Jugar" << std::endl;
    cout << "2. Mejores Jugadores" << std::endl;
    cout << "3. Salir" << std::endl;

    // Control de selecciones
    int seleccion = 0;
    cin >> seleccion;
    while(seleccion > 3 || seleccion < 1) {
        std::cout << "La opción seleccionada no es válida. Por favor, intentelo otra vez" << std::endl;
        cin >> seleccion;
    }

    if (seleccion == 3) {
        cout << "¿Tan rápido :( ?" << endl;
        cout << "Vuelve Pronto" << endl;
    }
    if (seleccion == 2) {
        Leaderboard LeaderboardTxT("../data/leaderboard.txt");
        LeaderboardTxT.displayLeaderboard();
    }

    else {
        int n = 0;
        string difficulty;
        cout << "¡Has elegido jugar! Selecciona la dificultad!" << endl;
        cout << "1. Fácil" << endl;
        cout << "2. Intermedio" << endl;
        cout << "3. Difícil" << endl;
        cout << "Ingresa la opción: " << endl;

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

        while (!game.hasEnd()) {

            game.StartGame();
            game.OneRound();
        }
    }
    return 0;
}

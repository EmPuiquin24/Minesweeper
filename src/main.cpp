#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../include/Leaderboard.h"

void matriz_abierta(std::string** m, int f) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < f; j++) {
            m[i][j] = "-";
        }
    }
}
void gen_matriz_oculta(std::string** m, int f, int* minas) {

    // Empieza morir
    std::vector<int> filas;
    std::vector<int> columnas;
    if(f == 6) {
        *minas = rand() % 3 + 3;
    }
    else if(f == 8) {
        *minas = rand() % 5 + 8;
    }
    else if(f == 10) {
        *minas = rand() % 6 + 15;
    }
    for(int i = 0; i < *minas; i++) {
        int fila = rand() % f;
        int col = rand() % f;
        filas.push_back(fila);
        columnas.push_back(col);
    }
    // Muerto hasta aquí
    for(int i = 0; i < *minas; i++) {
        int fila = filas[i];
        int col = columnas[i];
        m[fila][col] = "X";
    }
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < f; j++) {
            if(m[i][j] != "X") {
                int contm = 0;
                if(i - 1 > -1 && j - 1 > -1 && m[i-1][j-1] == "X") {
                    contm += 1;
                }
                if(i - 1 > -1 && m[i-1][j] == "X") {
                    contm += 1;
                }
                if(i - 1 > -1 && j + 1 < f && m[i-1][j+1] == "X") {
                    contm += 1;
                }
                if(j - 1 > -1 && m[i][j-1] == "X") {
                    contm += 1;
                }
                if(j + 1 < f && m[i][j+1] == "X") {
                    contm += 1;
                }
                if(i + 1 < f && j - 1 > -1 && m[i+1][j-1] == "X") {
                    contm += 1;
                }
                if(i + 1 < f && m[i+1][j] == "X") {
                    contm += 1;
                }
                if(i + 1 < f && j + 1 < f && m[i+1][j+1] == "X") {
                    contm += 1;
                }
                switch(contm) {
                    case 0:
                        m[i][j] = "0";
                        break;
                    case 1:
                        m[i][j] = "1";
                        break;
                    case 2:
                        m[i][j] = "2";
                        break;
                    case 3:
                        m[i][j] = "3";
                        break;
                    case 4:
                        m[i][j] = "4";
                        break;
                    case 5:
                        m[i][j] = "5";
                        break;
                    case 6:
                        m[i][j] = "6";
                        break;
                    case 7:
                        m[i][j] = "7";
                        break;
                    case 8:
                        m[i][j] = "8";
                        break;
                    default:
                        m[i][j] = "0";
                }
            }
        }
    }
}

void imprimir_matriz(std::string** m, int f) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < f; j++) {
            std::cout << std::setw(3) << m[i][j];
        }
        std::cout << std::endl;
    }
}

void una_ronda(std::string** abierta, std::string** cerrada, int f, int* minas ,int* banderas, bool* exito, bool* fin, int* rondas) {
    int fila = 0;
    int columna = 0;
    char accion;
    int descubiertas;
    std::cout << "Seleccione una celda:" << std::endl;
    std::cout << "Fila:" << std::endl;
    std::cin >> fila;
    while(fila < 0 || fila > f) {
        std::cout << "La fila ingresada no esta en el rango elegido. Ingresela de nuevo:" << std::endl;
        std::cin >> fila;
    }
    std::cout << "Columna:" << std::endl;
    std::cin >> columna;
    while(fila < 0 || fila > f) {
        std::cout << "La columna ingresada no esta en el rango elegido. Ingresela de nuevo:" << std::endl;
        std::cin >> columna;
    }
    std::cout << "Ingrese 'F' para marcar con bandera y 'D' para descubrir:" << std::endl;
    std::cin >> accion;
    if(accion == 'F' && abierta[fila][columna] == "F") {
        std::cout << "Advertencia: la celda seleccionada ya tiene una bandera." << std::endl;
    }
    if(accion == 'D' && abierta[fila][columna] != "-") {
        std::cout << "Advertencia: la celda seleccionada ya ha sido descubierta." << std::endl;
    }
    if(accion == 'F') {
        abierta[fila][columna] = "F";
        *banderas = *banderas + 1;
        std::cout << "Minas: " << *minas << " | Banderas: " << *banderas << std::endl;
        imprimir_matriz(abierta, f);
        *rondas = *rondas + 1;
    }
    else if(accion == 'D') {
        if(cerrada[fila][columna] == "X") {
            std::cout << "¡Has descubierto una mina!" << std::endl;
            std::cout << "Minas: " << *minas << " | Banderas: " << *banderas << std::endl;
            for(int i = 0; i < f; i++) {
                for(int j = 0; j < f; j++) {
                    if(cerrada[i][j] == "X") {
                        abierta[i][j] = "X";
                    }
                }
            }
            imprimir_matriz(abierta, f);
            *exito = false;
        }
        else {
            abierta[fila][columna] = cerrada[fila][columna];
            *exito = true;
            descubiertas = descubiertas + 1;
            if(descubiertas == f*f - *minas) {
                std::cout << "¡Felicidades! ¡Has descubierto todas las celdas sin mina!" << std::endl;
                std::cout << "Minas: " << *minas << " | Banderas: " << *banderas << std::endl;
                imprimir_matriz(abierta, f);
                *rondas = *rondas + 1;
                *fin = true;
            }
            else {
                std::cout << "Minas: " << *minas << " | Banderas: " << *banderas << std::endl;
                imprimir_matriz(abierta, f);
                *rondas = *rondas + 1;
            }
        }
    }
}

int main() {
    std::string nombre;
    std::cout << "Bienvenido/a al buscaminas, ¿cómo debería llamarte?" << std::endl;
    std::cin >> nombre;
    std::fstream myFile;
    srand(time(nullptr));
    int opcion = 0;
    std::cout << "Seleccione una opcion:" << std::endl;
    std::cout << "1: Jugar" << std::endl;
    std::cout << "2: Mejores jugadores" << std::endl;
    std::cout << "3: Salir" << std::endl;
    std::cin >> opcion;
    while(opcion > 3 || opcion < 1) {
        std::cout << "La opcion seleccionada no existe. Seleccione otra opcion:" << std::endl;
        std::cin >> opcion;
    }
    if(opcion == 1) {
        int n = 0;
        std::cout << "Seleccione la dificultad:" << std::endl;
        std::cout << "1: Facil" << std::endl;
        std::cout << "2: Intermedio" << std::endl;
        std::cout << "3: Dificil" << std::endl;
        std::cin >> n;
        while(n > 3 || n < 1) {
            std::cout << "El nivel de dificultad seleccionado no existe. Seleccione otra opcion:" << std::endl;
            std::cin >> n;
        }
        int filas = 0;
        if(n == 1) {
            filas = 6;
        }
        else if(n == 2) {
            filas = 8;
        }
        else if(n == 3) {
            filas = 10;
        }
        std::string** mat_s = new std::string* [filas];
        std::string** mat_h = new std::string* [filas];
        for(int i = 0; i < filas; i++) {
            mat_s[i] = new std::string[filas];
            mat_h[i] = new std::string[filas];
        }
        matriz_abierta(mat_s, filas);
        int* minas = new int(0);

        // Instrucciones
        gen_matriz_oculta(mat_h, filas, minas);
        int* banderas = new int(0);
        std::cout << "Minas: " << *minas << " | Banderas: " << *banderas << std::endl;
        imprimir_matriz(mat_s, filas);
        bool* fin = new bool(false);
        bool* exito = new bool(true);
        int* rondas = new int(0);
        while(*exito == true && *fin == false) {
            una_ronda(mat_s, mat_h, filas, minas, banderas, exito, fin, rondas);
        }
        for(int i = 0; i < filas; i++) {
            delete[] mat_s[i];
            delete[] mat_h[i];
        }
        delete[] mat_s;
        delete[] mat_h;
        delete minas;
        delete banderas;
        delete fin;
        delete exito;
        std::string dif;
        if(n == 1) {
            dif = "Fácil";
        }
        else if(n == 2) {
            dif = "Intermedio";
        }
        else {
            dif = "Difícil";
        }
        Player jugador(nombre, dif, *rondas);
        Leaderboard Leaderboard("../data/leaderboard.txt");
        Leaderboard.addPlayer(jugador);
        Leaderboard.displayLeaderboard();
        delete rondas;
    }
    else if(opcion == 2) {
        Leaderboard Leaderboard("../leaderboard.txt");
        Leaderboard.displayLeaderboard();
    }
    else if(opcion == 3) {
        std::cout << "¿Tan rápido, " << nombre << "? Regresa pronto" << std::endl;
    }
    return 0;
}

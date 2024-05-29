#include "Tablero.h"
#include <iostream>

Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
    // Inicializar las celdas
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            celdas.push_back(Celda(i, j));
        }
    }
}

bool Tablero::colocarBarco(Barco& barco, int x, int y, char orientacion) {
    // Implementar la lógica para colocar el barco
    return true;
}

std::string Tablero::recibirDisparo(int x, int y) {
    // Implementar la lógica para recibir un disparo
    return "Miss"; // O "Hit", según el resultado
}

void Tablero::mostrar() {
    // Implementar la lógica para mostrar el tablero
}

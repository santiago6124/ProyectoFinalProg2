#include "Tablero.h"
#include <iostream>

// Constructor
Tablero::Tablero(int size) : size(size), coordenadas(size, std::vector<Coordenada>(size)) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            coordenadas[i][j] = Coordenada(std::to_string(i + 1), j + 1);
        }
    }
}

// Método para obtener el tamaño del tablero
int Tablero::getSize() const {
    return size;
}

// Mostrar el tablero
void Tablero::mostrarTablero() {
    for (const auto& row : coordenadas) {
        for (const auto& coord : row) {
            if (coord.getBarco() != nullptr && coord.isTocado() && coord.getBarco()->isHundido()) {
                std::cout << '#' << " ";
            } else if (coord.getBarco() != nullptr && coord.isTocado()) {
                std::cout << 'X' << " ";
            } else if (coord.getBarco() != nullptr) {
                std::cout << 'B' << " ";
            } else if (coord.isTocado()) {
                std::cout << 'O' << " ";
            } else {
                std::cout << '.' << " ";
            }
        }
        std::cout << std::endl;
    }
}

// Colocar un barco en el tablero
bool Tablero::colocarBarco(int x, int y, Barco& barco) {
    if (barco.isHorizontal()) {
        if (x + barco.getLongitud() > size) return false;
        for (int i = 0; i < barco.getLongitud(); i++) {
            if (coordenadas[y][x + i].getBarco() != nullptr) return false;
        }
        for (int i = 0; i < barco.getLongitud(); i++) {
            coordenadas[y][x + i].setBarco(&barco);
        }
    } else {
        if (y + barco.getLongitud() > size) return false;
        for (int i = 0; i < barco.getLongitud(); i++) {
            if (coordenadas[y + i][x].getBarco() != nullptr) return false;
        }
        for (int i = 0; i < barco.getLongitud(); i++) {
            coordenadas[y + i][x].setBarco(&barco);
        }
    }
    return true;
}

// Atacar una posición
bool Tablero::atacar(int x, int y) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        Coordenada& coord = coordenadas[y][x];
        if (coord.getBarco() != nullptr) {
            coord.setTocado(true);
            coord.getBarco()->recibirGolpe();
            return true;
        } else {
            coord.setTocado(true);
        }
    }
    return false;
}

// Verificar si todos los barcos están hundidos
bool Tablero::todosBarcosHundidos() const {
    for (const auto& row : coordenadas) {
        for (const auto& coord : row) {
            if (coord.getBarco() != nullptr && !coord.getBarco()->isHundido()) {
                return false;
            }
        }
    }
    return true;
}

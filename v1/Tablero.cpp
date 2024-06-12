#include "Tablero.h"
#include <iostream>

Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas), celdas(filas, std::vector<Celda>(columnas)) {}

void Tablero::colocarBarco(Barco &barco, int filaInicio, int columnaInicio, bool horizontal) {
    int size = barco.getSize();
    for (int i = 0; i < size; ++i) {
        if (horizontal) {
            celdas[filaInicio][columnaInicio + i].setEstado(BARCO);
            barco.addPosicion(filaInicio, columnaInicio + i);
        } else {
            celdas[filaInicio + i][columnaInicio].setEstado(BARCO);
            barco.addPosicion(filaInicio + i, columnaInicio);
        }
    }
    barcos.push_back(barco);
}

bool Tablero::recibirAtaque(int fila, int columna) {
    if (celdas[fila][columna].getEstado() == BARCO) {
        celdas[fila][columna].setEstado(TOCADO);
        return true;
    } else {
        celdas[fila][columna].setEstado(AGUA);
        return false;
    }
}

void Tablero::mostrarTablero() const {
    for (const auto &fila : celdas) {
        for (const auto &celda : fila) {
            switch (celda.getEstado()) {
                case VACIO: std::cout << '.'; break;
                case BARCO: std::cout << 'B'; break;
                case AGUA: std::cout << '~'; break;
                case TOCADO: std::cout << 'X'; break;
                case HUNDIDO: std::cout << '#'; break;
            }
        }
        std::cout << std::endl;
    }
}

bool Tablero::todosBarcosHundidos() const {
    for (const auto &barco : barcos) {
        for (const auto &pos : barco.getPosiciones()) {
            if (celdas[pos.first][pos.second].getEstado() != TOCADO) {
                return false;
            }
        }
    }
    return true;
}

int Tablero::getFilas() const {
    return filas;
}

int Tablero::getColumnas() const {
    return columnas;
}

bool Tablero::puedeColocarBarco(const Barco &barco, int filaInicio, int columnaInicio, bool horizontal) const {
    int size = barco.getSize();
    if (horizontal) {
        if (columnaInicio + size > columnas) return false;
        for (int i = 0; i < size; ++i) {
            if (celdas[filaInicio][columnaInicio + i].getEstado() != VACIO) {
                return false;
            }
        }
    } else {
        if (filaInicio + size > filas) return false;
        for (int i = 0; i < size; ++i) {
            if (celdas[filaInicio + i][columnaInicio].getEstado() != VACIO) {
                return false;
            }
        }
    }
    return true;
}

const std::vector<std::vector<Celda>>& Tablero::getCeldas() const {
    return celdas;
}

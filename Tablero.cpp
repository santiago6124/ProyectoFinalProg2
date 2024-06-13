#include "Tablero.h"
#include <iostream>
#include <iomanip>

Tablero::Tablero(int filas, int columnas)
    : filas(filas), columnas(columnas), celdas(filas, std::vector<Celda>(columnas)) {}

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

EstadoCelda Tablero::recibirAtaque(int fila, int columna) {
    if (celdas[fila][columna].getEstado() == BARCO) {
        if (verificarHundimiento(fila, columna)) {
            celdas[fila][columna].setEstado(HUNDIDO);
            return HUNDIDO;
        }
        celdas[fila][columna].setEstado(TOCADO);
        return TOCADO;
    } else {
        celdas[fila][columna].setEstado(AGUA);
        return AGUA;
    }
}

bool Tablero::verificarHundimiento(int fila, int columna) {
    for (auto& barco : barcos) {
        if (barco.contienePosicion(fila, columna)) {
            for (const auto& pos : barco.getPosiciones()) {
                if (celdas[pos.first][pos.second].getEstado() != TOCADO && !(pos.first == fila && pos.second == columna)) {
                    std::cout<<pos.first<<" "<<pos.second<<" "<<celdas[pos.first][pos.second].getEstado()<<std::endl;
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

void Tablero::hundirBarco(int fila, int columna){
    for (auto& barco : barcos) {
        if (barco.contienePosicion(fila, columna)) {
            for (const auto& pos : barco.getPosiciones()) {
                celdas[pos.first][pos.second].setEstado(HUNDIDO);
            }
        }
    }
}


void Tablero::mostrarTablero() const {
    std::cout << "   ";
    for (int i = 1; i <= columnas; ++i) {
        std::cout << std::setw(2) << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < filas; ++i) {
        std::cout << static_cast<char>('A' + i) << "  ";
        for (int j = 0; j < columnas; ++j) {
            switch (celdas[i][j].getEstado()) {
                case VACIO: std::cout << '.'; break;
                case BARCO: std::cout << 'B'; break;
                case AGUA: std::cout << '~'; break;
                case TOCADO: std::cout << 'X'; break;
                case HUNDIDO: std::cout << '#'; break;
            }
            std::cout << "  ";
        }
        std::cout << std::endl;
    }
}

bool Tablero::todosBarcosHundidos() const {
    for (const auto &barco : barcos) {
        for (const auto &pos : barco.getPosiciones()) {
            if (celdas[pos.first][pos.second].getEstado() != TOCADO && celdas[pos.first][pos.second].getEstado() != HUNDIDO) {
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

std::vector<std::vector<Celda>>& Tablero::getCeldas() {
    return celdas;
}

const std::vector<std::vector<Celda>>& Tablero::getCeldas() const {
    return celdas;
}

int Tablero::convertirFila(char letra) {
    return letra - 'A';
}

int Tablero::convertirColumna(int numero) {
    return numero - 1;
}

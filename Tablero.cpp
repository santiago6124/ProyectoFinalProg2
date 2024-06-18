#include "Tablero.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

std::vector<std::pair<int, int>> Tablero::recibirAtaque(int fila, int columna) {
    std::vector<std::pair<int, int>> celdasAfectadas;
    if (celdas[fila][columna].getEstado() == BARCO) {
        if (verificarHundimiento(fila, columna)) {
            hundirBarco(fila, columna, celdasAfectadas);
        } else {
            celdas[fila][columna].setEstado(TOCADO);
            celdasAfectadas.push_back({fila, columna});
        }
    } else {
        celdas[fila][columna].setEstado(AGUA);
        celdasAfectadas.push_back({fila, columna});
    }
    return celdasAfectadas;
}

bool Tablero::verificarHundimiento(int fila, int columna) {
    for (auto& barco : barcos) {
        if (barco.contienePosicion(fila, columna)) {
            for (const auto& pos : barco.getPosiciones()) {
                if (celdas[pos.first][pos.second].getEstado() != TOCADO && !(pos.first == fila && pos.second == columna)) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

void Tablero::hundirBarco(int fila, int columna, std::vector<std::pair<int, int>>& celdasAfectadas) {
    for (auto& barco : barcos) {
        if (barco.contienePosicion(fila, columna)) {
            for (const auto& pos : barco.getPosiciones()) {
                celdas[pos.first][pos.second].setEstado(HUNDIDO);
                celdasAfectadas.push_back({pos.first, pos.second});
                std::cout << "Hundiendo celda en: (" << pos.first << ", " << pos.second << ")\n";  // Depuración
            }
            break; // Salir del bucle una vez que hemos encontrado y hundido el barco correspondiente
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

vector<vector<int>> Tablero::getDatos() const {
    vector<vector<int>> datos(filas, vector<int>(columnas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            datos[i][j] = static_cast<int>(celdas[i][j].getEstado());
        }
    }
    return datos;
}

void Tablero::setDatos(const vector<vector<int>> &nuevosDatos) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            celdas[i][j].setEstado(static_cast<EstadoCelda>(nuevosDatos[i][j]));
        }
    }

    // Mostrar el tablero después de cargar los datos para depuración
    std::cout << "Tablero después de cargar los datos:" << std::endl;
    mostrarTablero();
}

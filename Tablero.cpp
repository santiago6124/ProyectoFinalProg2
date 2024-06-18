#include "Tablero.h"
#include <iostream>
#include <iomanip>

Tablero::Tablero(int filas, int columnas)
    : filas(filas), columnas(columnas), celdas(filas, vector<Celda>(columnas)) {}

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
            hundirBarco(fila, columna);
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
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}


void Tablero::hundirBarco(int fila, int columna) {
    for (auto& barco : barcos) {
        if (barco.contienePosicion(fila, columna)) {
            for (const auto& pos : barco.getPosiciones()) {
                celdas[pos.first][pos.second].setEstado(HUNDIDO);
                cout << "Hundiendo celda en: (" << pos.first << ", " << pos.second << ")\n";  // Depuración
            }
            break; // Salir del bucle una vez que hemos encontrado y hundido el barco correspondiente
        }
    }
}

void Tablero::mostrarTablero() const {
    cout << "   ";
    for (int i = 1; i <= columnas; ++i) {
        cout << setw(2) << i << " ";
    }
    cout << endl;

    for (int i = 0; i < filas; ++i) {
        cout << static_cast<char>('A' + i) << "  ";
        for (int j = 0; j < columnas; ++j) {
            switch (celdas[i][j].getEstado()) {
                case VACIO: cout << '.'; break;
                case BARCO: cout << 'B'; break;
                case AGUA: cout << '~'; break;
                case TOCADO: cout << 'X'; break;
                case HUNDIDO: cout << '#'; break;
            }
            cout << "  ";
        }
        cout << endl;
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

vector<vector<Celda>>& Tablero::getCeldas() {
    return celdas;
}

const vector<vector<Celda>>& Tablero::getCeldas() const {
    return celdas;
}

int Tablero::convertirFila(char letra) {
    return letra - 'A';
}

int Tablero::convertirColumna(int numero) {
    return numero - 1;
}

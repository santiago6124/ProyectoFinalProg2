#include "Tablero.h"

Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            celdas.push_back(Celda(i, j));
        }
    }
}

bool Tablero::colocarBarco(Barco& barco, int x, int y, char orientacion) {
    Celda& celdaInicial = celdas[x * columnas + y];
    barco.colocar(celdaInicial, orientacion);
    barcos.push_back(barco);
    return true;
}

std::string Tablero::recibirDisparo(int x, int y) {
    Celda& celda = celdas[x * columnas + y];
    if (celda.recibirDisparo()) {
        for (auto& barco : barcos) {
            if (barco.recibirDisparo(celda)) {
                return barco.isHundido() ? "¡Hundido!" : "¡Tocado!";
            }
        }
    }
    return "¡Agua!";
}

void Tablero::mostrar() const {
    std::cout << "  ";
    for (int j = 0; j < columnas; ++j) {
        std::cout << j + 1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < filas; ++i) {
        std::cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < columnas; ++j) {
            const Celda& celda = celdas[i * columnas + j];
            if (celda.estaVacia()) {
                std::cout << "~ ";
            } else if (celda.isGolpeado()) {
                std::cout << "X ";
            } else {
                std::cout << "O ";
            }
        }
        std::cout << std::endl;
    }
}

std::string Tablero::coordenadaATexto(int x, int y) const {
    return std::string(1, 'A' + x) + std::to_string(y + 1);
}
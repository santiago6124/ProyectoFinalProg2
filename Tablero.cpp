#include "Tablero.h"

Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            celdas.push_back(Celda(i, j));
        }
    }
}

bool Tablero::colocarBarco(Barco& barco, int x, int y, char orientacion) {
    std::vector<Celda*> celdasParaBarco;

    for (int i = 0; i < barco.getTamaño(); ++i) {
        int newX = (orientacion == 'H') ? x : x + i;
        int newY = (orientacion == 'H') ? y + i : y;
        
        if (newX >= filas || newY >= columnas || !celdas[newX * columnas + newY].estaVacia()) {
            return false; // No se puede colocar el barco aquí
        }
        
        celdasParaBarco.push_back(&celdas[newX * columnas + newY]);
    }

    for (Celda* celda : celdasParaBarco) {
        celda->setBarco(&barco);
    }

    barco.colocar(celdasParaBarco);
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
            if (celda.isGolpeado()) {
                if (celda.estaVacia()) {
                    std::cout << "~ ";
                } else {
                    std::cout << "X ";
                }
            } else {
                std::cout << "~ ";
            }
        }
        std::cout << std::endl;
    }
}
void Tablero::mostrarPropio() const {
    std::cout << "  ";
    for (int j = 0; j < columnas; ++j) {
        std::cout << j + 1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < filas; ++i) {
        std::cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < columnas; ++j) {
            const Celda& celda = celdas[i * columnas + j];
            if (celda.isGolpeado()) {
                std::cout << "X ";
            } else if (celda.tieneBarco()) {
                std::cout << "B ";
            } else {
                std::cout << "~ ";
            }
        }
        std::cout << std::endl;
    }
}

std::string Tablero::coordenadaATexto(int x, int y) const {
    return std::string(1, 'A' + x) + std::to_string(y + 1);
}
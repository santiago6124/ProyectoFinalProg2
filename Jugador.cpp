#include "Jugador.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Jugador::Jugador(const std::string& nombre, int filas, int columnas) 
    : nombre(nombre), tableroPropio(filas, columnas), tableroRival(filas, columnas) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Jugador::colocarBarcos() {
    for (int i = 0; i < 10; ++i) {
        int tamaño = i < 4 ? 1 : (i < 7 ? 2 : (i < 9 ? 3 : 4));
        char orientacion;
        std::string coord;
        int x, y;
        std::cout << nombre << ", introduce la coordenada inicial y orientación (H/V) para el barco de tamaño " << tamaño << ": ";
        std::cin >> coord >> orientacion;
        x = coord[0] - 'A';
        y = std::stoi(coord.substr(1)) - 1;
        Barco barco(tamaño);
        while (!tableroPropio.colocarBarco(barco, x, y, orientacion)) {
            std::cout << "No se puede colocar el barco aquí. Intenta de nuevo: ";
            std::cin >> coord >> orientacion;
            x = coord[0] - 'A';
            y = std::stoi(coord.substr(1)) - 1;
        }
        barcos.push_back(barco);
        tableroPropio.mostrarPropio();  // Mostrar el tablero después de cada colocación
    }
}


void Jugador::colocarBarcosAleatoriamente() {
    // Método para colocar barcos aleatoriamente
    for (int i = 0; i < 10; ++i) {
        int tamaño = i < 4 ? 1 : (i < 7 ? 2 : (i < 9 ? 3 : 4));
        char orientacion = std::rand() % 2 == 0 ? 'H' : 'V';
        int x, y;
        Barco barco(tamaño);
        do {
            x = std::rand() % tableroPropio.getFilas();
            y = std::rand() % tableroPropio.getColumnas();
        } while (!tableroPropio.colocarBarco(barco, x, y, orientacion));
        barcos.push_back(barco);
    }
}


std::string Jugador::realizarDisparo(int x, int y) {
    return tableroRival.recibirDisparo(x, y);
}

std::pair<int, int> Jugador::dispararAleatoriamente() {
    int x = std::rand() % tableroRival.getFilas();
    int y = std::rand() % tableroRival.getColumnas();
    return {x, y};
}

bool Jugador::todosBarcosHundidos() const {
    for (const auto& barco : barcos) {
        if (!barco.isHundido()) {
            return false;
        }
    }
    return true;
}

std::string Jugador::getNombre() const {
    return nombre;
}

Tablero& Jugador::getTableroPropio() {
    return tableroPropio;
}
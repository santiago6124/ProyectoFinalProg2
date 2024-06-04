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
        int tamanio = i < 4 ? 1 : (i < 7 ? 2 : (i < 9 ? 3 : 4));
        char orientacion;
        std::string coord;
        int x, y;
        std::cout << nombre << ", introduce la coordenada inicial y orientacion (H/V) para el barco de tamanio " << tamanio << ": ";
        std::cin >> coord >> orientacion;
        x = coord[0] - 'A';
        y = std::stoi(coord.substr(1)) - 1;
        Barco barco(tamanio);
        while (!tableroPropio.colocarBarco(barco, x, y, orientacion)) {
            std::cout << "No se puede colocar el barco aqui. Intenta de nuevo: ";
            std::cin >> coord >> orientacion;
            x = coord[0] - 'A';
            y = std::stoi(coord.substr(1)) - 1;
        }
        barcos.push_back(barco);
        tableroPropio.mostrarPropio();  // Mostrar el tablero despues de cada colocacion
    }
}

void Jugador::colocarBarcosAleatoriamente() {
    int barcosPorTamanio[] = {1, 2, 3, 4};
    for (int tamanio = 4; tamanio >= 1; --tamanio) {
        for (int i = 0; i < barcosPorTamanio[tamanio - 1]; ++i) {
            char orientacion = std::rand() % 2 == 0 ? 'H' : 'V';
            int x, y;
            Barco barco(tamanio);
            do {
                x = std::rand() % tableroPropio.getFilas();
                y = std::rand() % tableroPropio.getColumnas();
            } while (!tableroPropio.colocarBarco(barco, x, y, orientacion));
            barcos.push_back(barco);
        }
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
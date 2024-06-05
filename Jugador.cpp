#include "Jugador.h"
#include <ctime>
#include <cstdlib>

#include <iostream>

Jugador::Jugador(const std::string& nombre, int filas, int columnas) 
    : nombre(nombre), tableroPropio(filas, columnas), tableroRival(filas, columnas) {
    srand(static_cast<unsigned int>(time(0)));  // Inicializar el generador de números aleatorios
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
    std::srand(std::time(0));  // Inicializar la semilla de aleatoriedad

    int barcosPorTamanio[] = {4, 3, 2, 1};
    int cantidadBarcos[] = {1, 2, 3, 4};

    for (int idx = 0; idx < 4; ++idx) {
        int tamanio = barcosPorTamanio[idx];
        for (int i = 0; i < cantidadBarcos[idx]; ++i) {
            char orientacion = std::rand() % 2 == 0 ? 'H' : 'V';
            int x, y;
            Barco barco(tamanio);
            bool colocado = false;

            while (!colocado) {
                x = std::rand() % tableroPropio.getFilas();
                y = std::rand() % tableroPropio.getColumnas();
                if (tableroPropio.colocarBarco(barco, x, y, orientacion)) {
                    barcos.push_back(barco);
                    colocado = true;
                }
            }
        }
    }
}




std::string Jugador::realizarDisparo(int x, int y) {
    return tableroRival.recibirDisparo(x, y);
}

std::pair<int, int> Jugador::dispararAleatoriamente() {
    int x = rand() % tableroPropio.getFilas();
    int y = rand() % tableroPropio.getColumnas();
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
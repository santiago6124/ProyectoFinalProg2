#include "Juego.h"
#include "Archivo.h"
#include <iostream>
#include <limits>

Juego::Juego(Jugador& j1, Jugador& j2) : jugador1(j1), jugador2(j2) {}

void Juego::iniciar() {
    jugador1.colocarBarcos();
    jugador2.colocarBarcos();

    Jugador *turnoActual = &jugador1;
    Jugador *oponente = &jugador2;

    while (true) {
        std::cout << "Turno de " << turnoActual->getNombre() << "\n";
        turnoActual->mostrarTableros();
        
        int fila, columna;
        std::cout << "Ingrese la fila a atacar: ";
        std::cin >> fila;
        std::cout << "Ingrese la columna a atacar: ";
        std::cin >> columna;
        
        if (turnoActual->realizarAtaque(*oponente, fila, columna)) {
            std::cout << "¡Tocado!\n";
        } else {
            std::cout << "Agua.\n";
        }

        if (oponente->todosBarcosHundidos()) {
            std::cout << "¡" << turnoActual->getNombre() << " ha ganado!\n";
            break;
        }

        std::swap(turnoActual, oponente);
    }
}

void Juego::guardarRanking(const std::string &filename, const std::vector<std::pair<std::string, int>> &ranking) {
    Archivo::guardarRanking(filename, ranking);
}

std::vector<std::pair<std::string, int>> Juego::cargarRanking(const std::string &filename) {
    return Archivo::cargarRanking(filename);
}

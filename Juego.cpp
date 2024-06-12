#include "Juego.h"
#include "Maquina.h"
#include <iostream>
#include <limits>
#include <algorithm>

Juego::Juego(Jugador& j1, Jugador& j2) : jugador1(j1), jugador2(j2) {}

void Juego::iniciar() {
    jugador1.colocarBarcos();
    jugador2.colocarBarcos();

    Jugador *turnoActual = &jugador1;
    Jugador *oponente = &jugador2;

    while (true) {
        std::cout << "Turno de " << turnoActual->getNombre() << "\n";
        turnoActual->mostrarTableroOponente();

        if (dynamic_cast<Maquina*>(turnoActual)) {
            dynamic_cast<Maquina*>(turnoActual)->realizarAtaque(*oponente);
        } else {
            int fila, columna;
            std::cout << "Ingrese la fila a atacar: ";
            std::cin >> fila;
            std::cout << "Ingrese la columna a atacar: ";
            std::cin >> columna;

            turnoActual->realizarAtaque(*oponente, fila, columna);
        }

        if (oponente->todosBarcosHundidos()) {
            std::cout << "¡" << turnoActual->getNombre() << " ha ganado!\n";
            break;
        }

        std::swap(turnoActual, oponente);
    }
}

void Juego::guardarRanking(const std::string &filename, const std::vector<std::pair<std::string, int>> &ranking) {
    // Archivo::guardarRanking(filename, ranking); // Implementar según sea necesario
}

std::vector<std::pair<std::string, int>> Juego::cargarRanking(const std::string &filename) {
    // return Archivo::cargarRanking(filename); // Implementar según sea necesario
    return {};
}

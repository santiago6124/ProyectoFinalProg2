#include "Juego.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <tuple>

Juego::Juego(Jugador& j1, Jugador& j2) : jugador1(&j1), jugador2(&j2), turnoActual(&j1), estado("iniciado") {}

void Juego::iniciar() {
    std::cout << jugador1->getNombre() << ", coloca tus barcos:" << std::endl;
    jugador1->colocarBarcos();
    
    std::cout << jugador2->getNombre() << ", coloca tus barcos:" << std::endl;
    jugador2->colocarBarcos();
}


void Juego::turno() {
    int x, y;
    std::string resultado;
    if (turnoActual == jugador1) {
        std::string coord;
        std::cout << "Turno de " << turnoActual->getNombre() << ". Ingresa las coordenadas para disparar (Ej: A1): ";
        std::cin >> coord;
        x = coord[0] - 'A';
        y = std::stoi(coord.substr(1)) - 1;
        resultado = turnoActual->realizarDisparo(x, y);
    } else {
        std::tie(x, y) = jugador2->dispararAleatoriamente();
        std::cout << "La máquina dispara a " << jugador2->getTableroPropio().coordenadaATexto(x, y) << std::endl;
        resultado = turnoActual->realizarDisparo(x, y);
    }

    std::cout << resultado << std::endl;

    std::cout << jugador1->getNombre() << "'s Tablero Propio:" << std::endl;
    jugador1->getTableroPropio().mostrarPropio();
    std::cout << jugador2->getNombre() << "'s Tablero Propio:" << std::endl;
    jugador2->getTableroPropio().mostrarPropio();

    turnoActual = (turnoActual == jugador1) ? jugador2 : jugador1;
}

Jugador* Juego::comprobarVictoria() {
    if (jugador1->todosBarcosHundidos()) {
        estado = "terminado";
        return jugador2;
    } else if (jugador2->todosBarcosHundidos()) {
        estado = "terminado";
        return jugador1;
    }
    return nullptr;
}

void Juego::guardarRanking(const std::string& filename, const std::vector<std::pair<std::string, int>>& ranking) {
    std::ofstream archivo(filename);
    for (const auto& entry : ranking) {
        archivo << entry.first << " " << entry.second << std::endl;
    }
}

std::vector<std::pair<std::string, int>> Juego::cargarRanking(const std::string& filename) {
    std::vector<std::pair<std::string, int>> ranking;
    std::ifstream archivo(filename);
    std::string nombre;
    int puntaje;
    while (archivo >> nombre >> puntaje) {
        ranking.emplace_back(nombre, puntaje);
    }
    return ranking;
}
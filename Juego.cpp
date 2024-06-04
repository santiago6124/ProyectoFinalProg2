#include "Juego.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Juego::Juego(Jugador& j1, Jugador& j2) : jugador1(&j1), jugador2(&j2), turnoActual(&j1), estado("iniciado") {}

void Juego::iniciar() {
    jugador1->colocarBarcos();
    jugador2->colocarBarcos();
}

void Juego::turno() {
    int x, y;
    std::cout << "Turno de " << turnoActual->getNombre() << ". Ingresa las coordenadas para disparar (x y): ";
    std::cin >> x >> y;
    std::string resultado = turnoActual->realizarDisparo(x, y);
    std::cout << resultado << std::endl;
    if (resultado == "¡Hundido!") {
        if (turnoActual->todosBarcosHundidos()) {
            estado = "terminado";
        }
    }
    turnoActual = (turnoActual == jugador1) ? jugador2 : jugador1;
}

Jugador* Juego::comprobarVictoria() {
    if (estado == "terminado") {
        return turnoActual;
    }
    return nullptr;
}

void Juego::guardarRanking(const std::string& filename, const std::vector<std::pair<std::string, int>>& ranking) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : ranking) {
            file << entry.first << " " << entry.second << std::endl;
        }
        file.close();
    }
}

std::vector<std::pair<std::string, int>> Juego::cargarRanking(const std::string& filename) {
    std::vector<std::pair<std::string, int>> ranking;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string nombre;
        int puntaje;
        while (file >> nombre >> puntaje) {
            ranking.emplace_back(nombre, puntaje);
        }
        file.close();
    }
    return ranking;
}

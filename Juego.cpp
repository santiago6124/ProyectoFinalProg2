#include "Juego.h"
#include <iostream>

Juego::Juego(Jugador& j1, Jugador& j2) : jugador1(j1), jugador2(j2) {}

void Juego::iniciar() {
    // Implementar la lógica del juego
}

void Juego::guardarRanking(const std::string &filename, const std::vector<std::pair<std::string, int>> &ranking) {
    Archivo::guardarRanking(filename, ranking);
}

std::vector<std::pair<std::string, int>> Juego::cargarRanking(const std::string &filename) {
    return Archivo::cargarRanking(filename);
}

// Ranking.cpp
#include "Ranking.h"
#include <fstream>
#include <algorithm>
#include <iostream>

Ranking::Ranking(const std::string& archivo) : archivo(archivo) {
    cargar();
}

void Ranking::agregarJugador(const std::string& nombre, int ataques) {
    jugadores.emplace_back(nombre, ataques);
    std::sort(jugadores.begin(), jugadores.end(), comparar);
}

void Ranking::guardar() const {
    std::ofstream archivoSalida(archivo);
    for (const auto& jugador : jugadores) {
        archivoSalida << jugador.nombre << " " << jugador.ataques << "\n";
    }
}

void Ranking::cargar() {
    std::ifstream archivoEntrada(archivo);
    std::string nombre;
    int ataques;
    while (archivoEntrada >> nombre >> ataques) {
        jugadores.emplace_back(nombre, ataques);
    }
    std::sort(jugadores.begin(), jugadores.end(), comparar);
}

void Ranking::mostrar() const {
    std::cout << "Ranking de jugadores:\n";
    for (const auto& jugador : jugadores) {
        std::cout << jugador.nombre << ": " << jugador.ataques << " ataques\n";
    }
}

bool Ranking::comparar(const JugadorRanking& a, const JugadorRanking& b) {
    return a.ataques < b.ataques;
}

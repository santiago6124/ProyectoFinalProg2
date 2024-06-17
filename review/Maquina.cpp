#include "Maquina.h"
#include <iostream>
#include <ctime>

Maquina::Maquina(std::string nombre, int sizeTablero) : Jugador(nombre, sizeTablero) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Inicializar generador de números aleatorios
    barcos = {Barco(3, true), Barco(4, true)}; // Añadido: inicialización de barcos
}

void Maquina::colocarBarcos() {
    for (auto& barco : barcos) {
        bool colocado = false;
        while (!colocado) {
            int x = generarNumeroAleatorio(0, tablero.getSize() - 1);
            int y = generarNumeroAleatorio(0, tablero.getSize() - 1);
            bool horizontal = generarNumeroAleatorio(0, 1) == 0;
            barco = Barco(barco.getLongitud(), horizontal);
            colocado = tablero.colocarBarco(x, y, barco);
        }
    }
}

bool Maquina::realizarAtaque(Jugador& oponente) {
    int x = generarNumeroAleatorio(0, oponente.getTablero().getSize() - 1);
    int y = generarNumeroAleatorio(0, oponente.getTablero().getSize() - 1);
    bool golpe = oponente.getTablero().atacar(x, y);
    std::cout << nombre << " ataca (" << x << ", " << y << "): " << (golpe ? "Golpe!" : "Fallo!") << std::endl;
    return golpe;
}

int Maquina::generarNumeroAleatorio(int min, int max) {
    return min + std::rand() / ((RAND_MAX + 1u) / (max - min + 1));
}

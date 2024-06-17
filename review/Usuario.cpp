#include "Usuario.h"
#include <iostream>

Usuario::Usuario(std::string nombre, int sizeTablero) : Jugador(nombre, sizeTablero) {
    barcos = {Barco(3, true), Barco(4, true)}; // Añadido: inicialización de barcos
}

void Usuario::colocarBarcos() {
    for (auto& barco : barcos) {
        bool colocado = false;
        while (!colocado) {
            int x, y;
            char orientacion;
            std::cout << nombre << ", ingresa las coordenadas para colocar tu barco de longitud "
                      << barco.getLongitud() << " (x y) y la orientación (H/V): ";
            std::cin >> x >> y >> orientacion;
            if (orientacion == 'H' || orientacion == 'h') {
                barco = Barco(barco.getLongitud(), true);
            } else if (orientacion == 'V' || orientacion == 'v') {
                barco = Barco(barco.getLongitud(), false);
            } else {
                std::cout << "Orientación no válida. Intenta de nuevo." << std::endl;
                continue;
            }
            colocado = tablero.colocarBarco(x, y, barco);
            if (!colocado) {
                std::cout << "No se pudo colocar el barco. Intenta de nuevo." << std::endl;
            }
            tablero.mostrarTablero();
        }
    }
}

bool Usuario::realizarAtaque(Jugador& oponente) {
    int x, y;
    std::cout << nombre << ", ingresa las coordenadas para atacar (x y): ";
    std::cin >> x >> y;
    bool golpe = oponente.getTablero().atacar(x, y);
    std::cout << nombre << " ataca (" << x << ", " << y << "): " << (golpe ? "Golpe!" : "Fallo!") << std::endl;
    oponente.getTablero().mostrarTablero();
    return golpe;
}

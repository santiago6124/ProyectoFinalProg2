#include "Usuario.h"
#include <iostream>

// Constructor
Usuario::Usuario(string nombre, int sizeTablero) : Jugador(nombre, sizeTablero) {}

// Sobreescribir métodos para interactuar con el tablero
bool Usuario::colocarBarco(int x, int y, Barco& barco) {
    std::cout << getNombre() << ", ingresa las coordenadas para colocar tu barco de longitud "
              << barco.getLongitud() << " (x y) y la orientación (H/V): ";
    char orientacion;
    std::cin >> x >> y >> orientacion;
    if (orientacion == 'H' || orientacion == 'h') {
        barco = Barco(barco.getLongitud(), true);
    } else if (orientacion == 'V' || orientacion == 'v') {
        barco = Barco(barco.getLongitud(), false);
    } else {
        std::cout << "Orientación no válida. Intenta de nuevo." << std::endl;
        return false;
    }
    return Jugador::colocarBarco(x, y, barco);
}

bool Usuario::atacar(int x, int y) {
    std::cout << getNombre() << ", ingresa las coordenadas para atacar (x y): ";
    std::cin >> x >> y;
    return Jugador::atacar(x, y);
}

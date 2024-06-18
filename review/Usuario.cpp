#include "Usuario.h"
#include <iostream>
#include "util.h" // Incluye el archivo de utilidades

// Constructor
Usuario::Usuario(std::string nombre, int sizeTablero) : Jugador(nombre, sizeTablero) {}



// Sobreescribir métodos para interactuar con el tablero
bool Usuario::colocarBarco(int x, int y, Barco& barco) {
    bool colocado = false;
    while (!colocado) {
        std::string entrada;
        char orientacion;

        std::cout << getNombre() << ", ingresa las coordenadas para colocar tu barco de longitud "
                  << barco.getLongitud() << " (Ej. A1 H o B3 V): ";
        std::cin >> entrada >> orientacion;

        if (parsearEntrada(entrada, x, y)) {
            if (orientacion == 'H' || orientacion == 'h') {
                barco = Barco(barco.getLongitud(), true);
            } else if (orientacion == 'V' || orientacion == 'v') {
                barco = Barco(barco.getLongitud(), false);
            } else {
                std::cout << "Orientación no válida. Intenta de nuevo." << std::endl;
                continue;
            }

            if (Jugador::colocarBarco(x, y, barco)) {
                colocado = true;
            } else {
                std::cout << "No se pudo colocar el barco en las coordenadas proporcionadas. Intenta de nuevo." << std::endl;
            }
        } else {
            std::cout << "Formato de entrada no válido. Intenta de nuevo." << std::endl;
        }
    }
    return true;
}

bool Usuario::atacar(Tablero& tableroOponente) {
    int x, y;
    std::cout << getNombre() << ", ingresa las coordenadas para atacar (x y): ";
    std::cin >> x >> y;
    return Jugador::atacar(tableroOponente, x, y);
}

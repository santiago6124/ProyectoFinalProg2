#include "Juego.h"
#include <iostream>
using namespace std;

void Juego::jugar() {
    // Crear barcos para los jugadores
    vector<Barco> barcosJugador1 = {Barco(3, true), Barco(4, false)};
    vector<Barco> barcosJugador2 = {Barco(3, true), Barco(4, false)};

    // Colocar barcos para el jugador 1
    for (Barco& barco : barcosJugador1) {
        bool colocado = false;
        while (!colocado) {
            int x, y;
            char orientacion;
            std::cout << jugador1.getNombre() << ", ingresa las coordenadas para colocar tu barco de longitud "
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
            colocado = jugador1.getTablero().colocarBarco(x, y, barco);
            if (!colocado) {
                std::cout << "No se pudo colocar el barco. Intenta de nuevo." << std::endl;
            } else {
                jugador1.agregarBarco(&barco);
            }
        }
    }

    // Colocar barcos para el jugador 2
    for (Barco& barco : barcosJugador2) {
        bool colocado = false;
        while (!colocado) {
            int x, y;
            char orientacion;
            std::cout << jugador2.getNombre() << ", ingresa las coordenadas para colocar tu barco de longitud "
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
            colocado = jugador2.getTablero().colocarBarco(x, y, barco);
            if (!colocado) {
                std::cout << "No se pudo colocar el barco. Intenta de nuevo." << std::endl;
            } else {
                jugador2.agregarBarco(&barco);
            }
        }
    }

    // Mostrar tableros iniciales
    std::cout << "Tablero " << jugador1.getNombre() << ":" << std::endl;
    jugador1.getTablero().mostrarTablero();
    std::cout << std::endl;

    std::cout << "Tablero " << jugador2.getNombre() << ":" << std::endl;
    jugador2.getTablero().mostrarTablero();
    std::cout << std::endl;

    bool juegoTerminado = false;
    while (!juegoTerminado) {
        int x, y;

        // Turno del jugador 1
        std::cout << jugador1.getNombre() << ", ingresa las coordenadas para atacar (x y): ";
        std::cin >> x >> y;
        std::cout << jugador1.getNombre() << " ataca (" << x << ", " << y << "): "
                  << (jugador2.getTablero().atacar(x, y) ? "Golpe!" : "Fallo!") << std::endl;
        std::cout << "Tablero " << jugador2.getNombre() << " después del ataque:" << std::endl;
        jugador2.getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador2 están hundidos
        if (jugador2.todosBarcosHundidos()) {
            std::cout << jugador1.getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }

        // Turno del jugador 2
        std::cout << jugador2.getNombre() << ", ingresa las coordenadas para atacar (x y): ";
        std::cin >> x >> y;
        std::cout << jugador2.getNombre() << " ataca (" << x << ", " << y << "): "
                  << (jugador1.getTablero().atacar(x, y) ? "Golpe!" : "Fallo!") << std::endl;
        std::cout << "Tablero " << jugador1.getNombre() << " después del ataque:" << std::endl;
        jugador1.getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador1 están hundidos
        if (jugador1.todosBarcosHundidos()) {
            std::cout << jugador2.getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }
    }
}

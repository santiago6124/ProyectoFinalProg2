#include "Juego.h"
#include <iostream>
using namespace std;

void Juego::jugar() {
    // Crear barcos para los jugadores
    Barco barco1(3, true);
    Barco barco2(4, false);

    // Agregar barcos a los jugadores
    jugador1.agregarBarco(&barco1);
    jugador2.agregarBarco(&barco2);

    // Colocar barcos en los tableros
    jugador1.getTablero().colocarBarco(0, 0, barco1);
    jugador2.getTablero().colocarBarco(2, 2, barco2);

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

#include "Juego.h"
#include "Barco.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


void Juego::jugar() {
    // Crear barcos para los jugadores
    Barco barco1(3, true);
    Barco barco2(4, false);

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

    // Realizar ataques
    std::cout << jugador1.getNombre() << " ataca (2, 2): "
              << (jugador2.getTablero().atacar(2, 2) ? "Golpe!" : "Fallo!") << std::endl;

    std::cout << jugador2.getNombre() << " ataca (0, 0): "
              << (jugador1.getTablero().atacar(0, 0) ? "Golpe!" : "Fallo!") << std::endl;

    // Mostrar tableros después de los ataques
    std::cout << "Tablero " << jugador1.getNombre() << ":" << std::endl;
    jugador1.getTablero().mostrarTablero();
    std::cout << std::endl;

    std::cout << "Tablero " << jugador2.getNombre() << ":" << std::endl;
    jugador2.getTablero().mostrarTablero();
    std::cout << std::endl;
}

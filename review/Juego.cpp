#include "Juego.h"
#include "Tablero.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


void Juego::jugar() {
    // Ejemplo de juego: Colocar barcos y realizar ataques
    Barco barco1(3, true);
    Barco barco2(4, false);

    tableroJugador1.colocarBarco(0, 0, barco1);
    tableroJugador2.colocarBarco(2, 2, barco2);

    tableroJugador1.mostrarTablero();
    std::cout << std::endl;
    tableroJugador2.mostrarTablero();

    std::cout << "Jugador 1 ataca (2, 2): " << (tableroJugador2.atacar(2, 2) ? "Golpe!" : "Fallo!") << std::endl;
    std::cout << "Jugador 2 ataca (0, 0): " << (tableroJugador1.atacar(0, 0) ? "Golpe!" : "Fallo!") << std::endl;

    tableroJugador1.mostrarTablero();
    std::cout << std::endl;
    tableroJugador2.mostrarTablero();
}

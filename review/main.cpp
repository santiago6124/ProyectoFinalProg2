#include <iostream>
#include "Juego.h"

int main() {
    std::string nombreJugador1, nombreJugador2;
    int sizeTablero;
    bool contraMaquina;

    std::cout << "Ingresa el nombre del Jugador 1: ";
    std::cin >> nombreJugador1;

    std::cout << "¿Quieres jugar contra otro jugador o contra la máquina? (1: Jugador, 2: Máquina): ";
    int opcion;
    std::cin >> opcion;
    contraMaquina = (opcion == 2);

    if (!contraMaquina) {
        std::cout << "Ingresa el nombre del Jugador 2: ";
        std::cin >> nombreJugador2;
    } else {
        nombreJugador2 = "Máquina";
    }

    std::cout << "Ingresa el tamaño del tablero (mínimo 10x10): ";
    std::cin >> sizeTablero;
    while (sizeTablero < 10) {
        std::cout << "El tamaño del tablero debe ser al menos 10x10. Inténtalo de nuevo: ";
        std::cin >> sizeTablero;
    }

    Juego juego(nombreJugador1, nombreJugador2, sizeTablero, contraMaquina);
    juego.jugar();

    return 0;
}

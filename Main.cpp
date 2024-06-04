#include <iostream>
#include "Juego.h"

int main() {
    Jugador jugador1("Jugador 1", 10, 10);
    Jugador jugador2("Jugador 2", 10, 10);
    Juego juego(jugador1, jugador2);

    juego.iniciar();

    while (true) {
        juego.turno();
        Jugador* ganador = juego.comprobarVictoria();
        if (ganador != nullptr) {
            std::cout << "¡" << ganador->getNombre() << " ha ganado!" << std::endl;
            break;
        }
    }

    return 0;
}

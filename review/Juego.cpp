#include "Juego.h"
#include <iostream>

Juego::Juego(const std::string& nombreJugador1, const std::string& nombreJugador2, int sizeTablero, bool contraMaquina)
    : jugador1(nombreJugador1, sizeTablero), contraMaquina(contraMaquina) {
    if (contraMaquina) {
        jugador2 = new Maquina("Máquina", sizeTablero);
    } else {
        jugador2 = new Usuario(nombreJugador2, sizeTablero);
    }
}

void Juego::jugar() {
    jugador1.colocarBarcos();
    jugador2->colocarBarcos();

    bool juegoTerminado = false;
    while (!juegoTerminado) {
        // Turno del jugador 1
        jugador1.realizarAtaque(*jugador2);

        // Verificar si todos los barcos del jugador 2 están hundidos
        if (jugador2->todosBarcosHundidos()) {
            std::cout << jugador1.getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }

        // Turno del jugador 2
        jugador2->realizarAtaque(jugador1);

        // Verificar si todos los barcos del jugador 1 están hundidos
        if (jugador1.todosBarcosHundidos()) {
            std::cout << jugador2->getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }
    }
}

Juego::~Juego() {
    delete jugador2;
}

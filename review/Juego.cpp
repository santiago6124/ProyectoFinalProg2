#include "Juego.h"
#include "Usuario.h"
#include "Maquina.h"
#include <iostream>

void Juego::jugar() {
    int modo;
    std::cout << "Selecciona el modo de juego: (1) Usuario vs Usuario (2) Usuario vs Maquina: ";
    std::cin >> modo;

    Jugador* jugador1;
    Jugador* jugador2;

    if (modo == 1) {
        jugador1 = new Usuario("Jugador 1", 10);
        jugador2 = new Usuario("Jugador 2", 10);
    } else if (modo == 2) {
        jugador1 = new Usuario("Jugador", 10);
        jugador2 = new Maquina("Maquina", 10);
    } else {
        std::cout << "Modo de juego no válido." << std::endl;
        return;
    }

    // Aquí seguirías con la lógica del juego, utilizando jugador1 y jugador2
    // Crear barcos para los jugadores
    std::vector<Barco> barcosJugador1 = {Barco(3, true)};
    std::vector<Barco> barcosJugador2 = {Barco(3, true)};

    // Colocar barcos para los jugadores
    for (Barco& barco : barcosJugador1) {
        while (!jugador1->colocarBarco(0, 0, barco));
    }
    for (Barco& barco : barcosJugador2) {
        while (!jugador2->colocarBarco(0, 0, barco));
    }

    // Mostrar tableros iniciales
    std::cout << "Tablero " << jugador1->getNombre() << ":" << std::endl;
    jugador1->getTablero().mostrarTablero();
    std::cout << std::endl;

    std::cout << "Tablero " << jugador2->getNombre() << ":" << std::endl;
    jugador2->getTablero().mostrarTablero();
    std::cout << std::endl;

    bool juegoTerminado = false;
    while (!juegoTerminado) {
        int x, y;

        // Turno del jugador 1
        std::cout << jugador1->getNombre() << ", Ataca (x y): ";
        jugador2->atacar(x, y);
        std::cout << "Tablero " << jugador2->getNombre() << " después del ataque:" << std::endl;
        jugador2->getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador2 están hundidos
        if (jugador2->todosBarcosHundidos()) {
            std::cout << jugador1->getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }

        // Turno del jugador 2
        std::cout << jugador2->getNombre() << ", Ataca (x y): ";
        jugador1->atacar(x, y);
        std::cout << "Tablero " << jugador1->getNombre() << " después del ataque:" << std::endl;
        jugador1->getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador1 están hundidos
        if (jugador1->todosBarcosHundidos()) {
            std::cout << jugador2->getNombre() << " ha ganado!" << std::endl;
            juegoTerminado = true;
            break;
        }
    }

    delete jugador1;
    delete jugador2;
}

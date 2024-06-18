#include "Juego.h"
#include "Usuario.h"
#include "Maquina.h"
#include <iostream>
#include <string>

int main() {
    int filas, columnas, opcion;
    std::string nombreJugador1, nombreJugador2, nombreJugador;

    std::cout << "Seleccione el modo de juego:\n1. Jugador vs Maquina\n2. Jugador vs Jugador\n";
    std::cin >> opcion;

    std::cout << "Ingrese el tamanio del tablero (minimo 10x10): ";
    std::cin >> filas >> columnas;
    if (filas < 10 || columnas < 10) {
        std::cout << "El tamanio minimo del tablero es 10x10. Usando tamanio por defecto 10x10.\n";
        filas = 10;
        columnas = 10;
    }

    if (opcion == 1) {
        std::cout << "Ingrese el nombre del jugador.\n";
        std::cin >> nombreJugador;
        Usuario jugador1(nombreJugador, filas, columnas);
        Maquina maquina("Maquina", filas, columnas);
        Juego juego(jugador1, maquina);
        juego.iniciar();
    } else if (opcion == 2) {
        std::cout << "Ingrese el nombre del jugador 1.\n";
        std::cin >> nombreJugador1;
        Usuario jugador1(nombreJugador1, filas, columnas);
        std::cout << "Ingrese el nombre del jugador 2.\n";
        std::cin >> nombreJugador2;
        Usuario jugador2(nombreJugador2, filas, columnas);
        Juego juego(jugador1, jugador2);
        juego.iniciar();
    } else {
        std::cout << "Opcion no valida.\n";
    }

    return 0;
}

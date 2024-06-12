#include "Juego.h"
#include "Usuario.h"
#include "Maquina.h"
#include <iostream>

int main() {
    int filas, columnas, opcion;

    std::cout << "Seleccione el modo de juego:\n1. Jugador vs Máquina\n2. Jugador vs Jugador\n";
    std::cin >> opcion;

    std::cout << "Ingrese el tamaño del tablero (mínimo 10x10): ";
    std::cin >> filas >> columnas;
    if (filas < 10 || columnas < 10) {
        std::cout << "El tamaño mínimo del tablero es 10x10. Usando tamaño por defecto 10x10.\n";
        filas = 10;
        columnas = 10;
    }

    if (opcion == 1) {
        Usuario jugador1("Jugador 1", filas, columnas);
        Maquina maquina("Maquina", filas, columnas);
        Juego juego(jugador1, maquina);
        juego.iniciar();
    } else if (opcion == 2) {
        Usuario jugador1("Jugador 1", filas, columnas);
        Usuario jugador2("Jugador 2", filas, columnas);
        Juego juego(jugador1, jugador2);
        juego.iniciar();
    } else {
        std::cout << "Opción no válida.\n";
    }

    return 0;
}

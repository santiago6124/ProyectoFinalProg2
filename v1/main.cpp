#include "Juego.h"
#include "Usuario.h"
#include "Maquina.h"
#include <iostream>

int main() {
    int filas = 10;
    int columnas = 10;
    int opcion;

    std::cout << "Seleccione el modo de juego:\n1. Jugador vs Máquina\n2. Jugador vs Jugador\n";
    std::cin >> opcion;

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

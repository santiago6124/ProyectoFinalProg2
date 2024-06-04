#include <iostream>
#include "Juego.h"

void mostrarMenu() {
    std::cout << "1. Jugar contra la máquina" << std::endl;
    std::cout << "2. Jugar contra otro jugador" << std::endl;
    std::cout << "3. Ver ranking" << std::endl;
    std::cout << "4. Salir" << std::endl;
}

int main() {
    int opcion;
    mostrarMenu();
    std::cin >> opcion;

    int filas, columnas;
    std::cout << "Ingrese el tamaño del tablero (mínimo 10x10): ";
    std::cin >> filas >> columnas;
    if (filas < 10 || columnas < 10) {
        std::cout << "Tamaño mínimo del tablero es 10x10." << std::endl;
        return 1;
    }

    if (opcion == 1) {
        Jugador jugador1("Jugador 1", filas, columnas);
        Jugador maquina("Máquina", filas, columnas);
        Juego juego(jugador1, maquina);
        juego.iniciar();
        while (true) {
            juego.turno();
            Jugador* ganador = juego.comprobarVictoria();
            if (ganador != nullptr) {
                std::cout << "¡" << ganador->getNombre() << " ha ganado la partida!" << std::endl;
                break;
            }
        }
    } else if (opcion == 2) {
        Jugador jugador1("Jugador 1", filas, columnas);
        Jugador jugador2("Jugador 2", filas, columnas);
        Juego juego(jugador1, jugador2);
        juego.iniciar();
        while (true) {
            juego.turno();
            Jugador* ganador = juego.comprobarVictoria();
            if (ganador != nullptr) {
                std::cout << "¡" << ganador->getNombre() << " ha ganado la partida!" << std::endl;
                break;
            }
        }
    } else if (opcion == 3) {
        Jugador temp1("temp1", filas, columnas);
        Jugador temp2("temp2", filas, columnas);
        Juego juego(temp1, temp2);
        auto ranking = juego.cargarRanking("ranking.txt");
        std::cout << "Ranking de jugadores:" << std::endl;
        for (const auto& entry : ranking) {
            std::cout << entry.first << ": " << entry.second << std::endl;
        }
    } else if (opcion == 4) {
        std::cout << "Gracias por jugar!" << std::endl;
    }

    return 0;
}
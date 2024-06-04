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

    if (opcion == 1) {
        Jugador jugador1("Jugador 1", 10, 10);
        Jugador maquina("Máquina", 10, 10);
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
        Jugador jugador1("Jugador 1", 10, 10);
        Jugador jugador2("Jugador 2", 10, 10);
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
        // Cargar y mostrar ranking
        Juego juego(Jugador("temp1", 10, 10), Jugador("temp2", 10, 10)); // Crear una instancia temporal de Juego
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

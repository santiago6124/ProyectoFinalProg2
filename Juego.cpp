#include "Juego.h"
#include "Maquina.h"
#include <iostream>
#include <limits>
#include <algorithm>

Juego::Juego(Jugador& j1, Jugador& j2) : jugador1(j1), jugador2(j2) {}

void Juego::iniciar() {
    jugador1.colocarBarcos();
    jugador2.colocarBarcos();

    Jugador *turnoActual = &jugador1;
    Jugador *oponente = &jugador2;

    while (true) {
        std::cout << "Turno de " << turnoActual->getNombre() << "\n";

        if (dynamic_cast<Maquina*>(turnoActual)) {
            dynamic_cast<Maquina*>(turnoActual)->realizarAtaque(*oponente);
        } else {
            int fila, columna;
            bool ataqueExitoso = false;

            while (!ataqueExitoso) {
                // Validar fila
                while (true) {
                    std::cout << "Ingrese la fila a atacar (A-" << static_cast<char>('A' + oponente->getFilasTablero() - 1) << "): ";
                    std::string inputFila;
                    std::cin >> inputFila;
                    if (inputFila.length() == 1 && isalpha(inputFila[0])) {
                        fila = Tablero::convertirFila(toupper(inputFila[0]));
                        if (fila >= 0 && fila < oponente->getFilasTablero()) {
                            break;
                        }
                    }
                    std::cout << "Entrada inválida. Intente de nuevo.\n";
                }

                // Validar columna
                while (true) {
                    std::cout << "Ingrese la columna a atacar (1-" << oponente->getColumnasTablero() << "): ";
                    std::cin >> columna;
                    if (std::cin.fail() || columna < 1 || columna > oponente->getColumnasTablero()) {
                        std::cin.clear(); // Clear the error flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar entrada inválida
                        std::cout << "Entrada inválida. Intente de nuevo.\n";
                    } else {
                        columna = Tablero::convertirColumna(columna);
                        break;
                    }
                }

                // Realizar ataque y verificar si las coordenadas son válidas
                ataqueExitoso = turnoActual->realizarAtaque(*oponente, fila, columna);
                if (!ataqueExitoso) {
                    std::cout << "Coordenadas de ataque inválidas o repetidas. Intente de nuevo.\n";
                }
            }
        }

        // Mostrar el tablero del oponente actualizado después del ataque
        turnoActual->mostrarTableroOponente();

        // Verificar si todos los barcos del oponente están hundidos
        if (oponente->todosBarcosHundidos()) {
            std::cout << turnoActual->getNombre() << " ha ganado!\n";
            break;
        }

        std::swap(turnoActual, oponente);
    }
}

void Juego::guardarRanking(const std::string &filename, const std::vector<std::pair<std::string, int>> &ranking) {
    // Archivo::guardarRanking(filename, ranking); // Implementar según sea necesario
}

std::vector<std::pair<std::string, int>> Juego::cargarRanking(const std::string &filename) {
    // return Archivo::cargarRanking(filename); // Implementar según sea necesario
    return {};
}

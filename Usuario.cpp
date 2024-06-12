#include "Usuario.h"
#include <iostream>
#include <cctype> // Para toupper
#include <limits> // Para std::numeric_limits

Usuario::Usuario(const std::string& nombre, int filas, int columnas)
    : Jugador(nombre, filas, columnas) {}

void Usuario::colocarBarcos() {
    int tamanios[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    for (int size : tamanios) {
        bool colocado = false;
        while (!colocado) {
            std::cout << "Colocando barco de tamaño " << size << "\n";

            int fila;
            int columna;
            bool horizontal;

            // Validar fila
            while (true) {
                std::string inputFila;
                std::cout << "Ingrese la fila inicial (A-" << static_cast<char>('A' + tableroPropio.getFilas() - 1) << "): ";
                std::cin >> inputFila;
                if (inputFila.length() == 1 && isalpha(inputFila[0])) {
                    fila = Tablero::convertirFila(toupper(inputFila[0]));
                    if (fila >= 0 && fila < tableroPropio.getFilas()) {
                        break;
                    }
                }
                std::cout << "Entrada inválida. Intente de nuevo.\n";
            }

            // Validar columna
            while (true) {
                std::cout << "Ingrese la columna inicial (1-" << tableroPropio.getColumnas() << "): ";
                std::cin >> columna;
                if (std::cin.fail() || columna < 1 || columna > tableroPropio.getColumnas()) {
                    std::cin.clear(); // Clear the error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    std::cout << "Entrada inválida. Intente de nuevo.\n";
                } else {
                    columna = Tablero::convertirColumna(columna);
                    break;
                }
            }

            // Validar orientación
            while (true) {
                std::string orientacion;
                std::cout << "Ingrese la orientación (H para horizontal, V para vertical): ";
                std::cin >> orientacion;
                if (orientacion.length() == 1) {
                    char dir = toupper(orientacion[0]);
                    if (dir == 'H' || dir == 'V') {
                        horizontal = (dir == 'H');
                        break;
                    }
                }
                std::cout << "Entrada inválida. Intente de nuevo.\n";
            }

            Barco barco(size);
            if (tableroPropio.puedeColocarBarco(barco, fila, columna, horizontal)) {
                tableroPropio.colocarBarco(barco, fila, columna, horizontal);
                tableroPropio.mostrarTablero();  // Mostrar el tablero después de colocar el barco
                colocado = true;
            } else {
                std::cout << "No se puede colocar el barco aquí, intente de nuevo.\n";
            }
        }
    }
}

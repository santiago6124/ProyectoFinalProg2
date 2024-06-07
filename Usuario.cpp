#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre, int filas, int columnas)
    : Jugador(nombre, filas, columnas) {}

void Usuario::colocarBarcos() {
    int tamanios[] = {5, 4, 3, 3, 2};
    for (int size : tamanios) {
        bool colocado = false;
        while (!colocado) {
            std::cout << "Colocando barco de tamaño " << size << "\n";
            std::cout << "Ingrese la fila inicial: ";
            int fila;
            std::cin >> fila;
            std::cout << "Ingrese la columna inicial: ";
            int columna;
            std::cin >> columna;
            std::cout << "Ingrese la orientación (h para horizontal, v para vertical): ";
            char orientacion;
            std::cin >> orientacion;
            bool horizontal = (orientacion == 'h');

            Barco barco(size);
            if (tableroPropio.puedeColocarBarco(barco, fila, columna, horizontal)) {
                tableroPropio.colocarBarco(barco, fila, columna, horizontal);
                colocado = true;
            } else {
                std::cout << "No se puede colocar el barco aquí, intente de nuevo.\n";
            }
        }
    }
}

#include "Maquina.h"
#include <cstdlib>
#include <ctime>

Maquina::Maquina(const std::string& nombre, int filas, int columnas)
    : Jugador(nombre, filas, columnas) {
    srand(time(0));
}

void Maquina::colocarBarcos() {
    int tamanios[] = {5, 4, 3, 3, 2};
    for (int size : tamanios) {
        bool colocado = false;
        while (!colocado) {
            int fila = rand() % tableroPropio.getFilas();
            int columna = rand() % tableroPropio.getColumnas();
            bool horizontal = rand() % 2;

            Barco barco(size);
            if (tableroPropio.puedeColocarBarco(barco, fila, columna, horizontal)) {
                tableroPropio.colocarBarco(barco, fila, columna, horizontal);
                colocado = true;
            }
        }
    }
}

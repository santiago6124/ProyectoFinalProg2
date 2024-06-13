#include "Maquina.h"
#include <cstdlib>
#include <ctime>

Maquina::Maquina(const std::string& nombre, int filas, int columnas)
    : Jugador(nombre, filas, columnas) {
    srand(time(0));
}

void Maquina::colocarBarcos() {
    int tamanios[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    for (int size : tamanios) {
        bool colocado = false;
        while (!colocado) {
            int fila = generarFila();
            int columna = generarColumna();
            bool horizontal = generarOrientacion();

            Barco barco(size);
            if (tableroPropio.puedeColocarBarco(barco, fila, columna, horizontal)) {
                tableroPropio.colocarBarco(barco, fila, columna, horizontal);
                colocado = true;
            }
        }
    }
}

int Maquina::generarFila() {
    return rand() % tableroPropio.getFilas();
}

int Maquina::generarColumna() {
    return rand() % tableroPropio.getColumnas();
}

bool Maquina::generarOrientacion() {
    return rand() % 2;
}

bool Maquina::realizarAtaque(Jugador &oponente) {
    int fila, columna;
    bool ataqueExitoso = false;

    while (!ataqueExitoso) {
        fila = generarFila();
        columna = generarColumna();

        // Verificar si la celda ya ha sido atacada
        if (tableroOponente.getCeldas()[fila][columna].getEstado() == VACIO) {
            ataqueExitoso = Jugador::realizarAtaque(oponente, fila, columna);
        }
    }
    
    return ataqueExitoso;
}

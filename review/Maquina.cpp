#include "Maquina.h"

// Constructor
Maquina::Maquina(string nombre, int sizeTablero) : Jugador(nombre, sizeTablero) {
    srand(time(0)); // Inicializar semilla para random
}

// Sobreescribir métodos para interactuar con el tablero
bool Maquina::colocarBarco(int x, int y, Barco& barco) {
    bool colocado = false;
    while (!colocado) {
        x = rand() % getTablero().getSize();
        y = rand() % getTablero().getSize();
        bool horizontal = rand() % 2;
        barco = Barco(barco.getLongitud(), horizontal);
        colocado = Jugador::colocarBarco(x, y, barco);
    }
    return true;
}

bool Maquina::atacar(int x, int y) {
    x = rand() % getTablero().getSize();
    y = rand() % getTablero().getSize();
    return Jugador::atacar(x, y);
}

#include "Maquina.h"
#include <ctime>
#include <cstdlib>

// Constructor
Maquina::Maquina(std::string nombre, int sizeTablero) : Jugador(nombre, sizeTablero) {
    srand(time(0)); // Inicializar semilla para random
}

// Sobreescribir metodos para interactuar con el tablero
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

bool Maquina::atacar(Tablero& tableroOponente, int x, int y) {
    x = rand() % tableroOponente.getSize();
    y = rand() % tableroOponente.getSize();
    return tableroOponente.atacar(x, y);
}

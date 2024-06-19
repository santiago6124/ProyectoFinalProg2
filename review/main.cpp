#include <iostream>
#include <vector>
#include <string>
#include "Juego.h"

int main() {
    int sizeTablero;
    std::cout << "Selecciona el tamanio del tablero: ";
    std::cin >> sizeTablero;
    Juego juego("Jugador 1", "Jugador 2", sizeTablero);
    juego.jugar();
    return 0;
}
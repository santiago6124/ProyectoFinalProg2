#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Juego.h"

int main() {
    int sizeTablero = 10;
    std::string input;

    std::cout << "Selecciona el tamanio del tablero: ";
    std::cin >> input;

    try {
        sizeTablero = std::stoi(input);
        if (sizeTablero < 10) {
            std::cout << "Tamanio de tablero no valido (muy pequenio), se usara el tamanio por defecto de 10." << std::endl;
            sizeTablero = 10;
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Entrada no valida, se usara el tamanio por defecto de 10." << std::endl;
    }

    Juego juego("Jugador 1", "Jugador 2", sizeTablero);
    juego.jugar();
    return 0;
}

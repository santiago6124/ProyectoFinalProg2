#include <iostream>
#include <vector>
#include <string>
#include "Juego.h"

int main() {
    Juego juego("Jugador 1", "Jugador 2", 10);
    juego.jugar();
    return 0;
}
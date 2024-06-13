#pragma once

#include <string>
#include "Jugador.h"

#ifndef JUEGO_H
#define JUEGO_H

class Juego {
private:
    Jugador jugador1;
    Jugador jugador2;

public:
    // Constructor
    Juego(const std::string& nombreJugador1, const std::string& nombreJugador2, int size)
        : jugador1(nombreJugador1, size), jugador2(nombreJugador2, size) {}

    void jugar();
};

#endif

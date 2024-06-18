#pragma once

#include <string>
#include "Jugador.h"
using namespace std;
#include <memory>
#ifndef Juego_H
#define Juego_H

class Juego {
private:
    std::unique_ptr<Jugador> jugador1;
    std::unique_ptr<Jugador> jugador2;

public:
    // Constructor
    Juego(const std::string& nombreJugador1, const std::string& nombreJugador2, int size);

    void jugar();
};

#endif

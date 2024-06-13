#pragma once

#include <string>
#include "Tablero.h"

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {
private:
    std::string nombre;
    Tablero tablero;

public:
    // Constructor
    Jugador(std::string nombre, int sizeTablero);

    // Métodos de acceso
    std::string getNombre() const;
    Tablero& getTablero();

    // Métodos para interactuar con el tablero
    bool colocarBarco(int x, int y, Barco& barco);
    bool atacar(int x, int y);

    // Verificar si todos los barcos están hundidos
    bool todosBarcosHundidos() const;
};

#endif // JUGADOR_H

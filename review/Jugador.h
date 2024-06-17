#pragma once

#include <string>
#include "Tablero.h"
using namespace std;

#ifndef Jugador_H
#define Jugador_H

class Jugador {
private:
    string nombre;
    Tablero tablero;

public:
    // Constructor
    Jugador(string nombre, int sizeTablero);

    // Métodos de acceso
    string getNombre() const;
    Tablero& getTablero();

    // Métodos para interactuar con el tablero
    bool colocarBarco(int x, int y, Barco& barco);
    bool atacar(int x, int y);

    // Verificar si todos los barcos están hundidos
    bool todosBarcosHundidos() const;
};

#endif

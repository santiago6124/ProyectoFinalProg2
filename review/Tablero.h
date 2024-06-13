#pragma once

#include <vector>
#include "Coordenada.h"
#include "Barco.h"

#ifndef TABLERO_H
#define TABLERO_H

class Tablero {
private:
    std::vector<std::vector<Coordenada>> coordenadas;
    int size;

public:
    // Constructor
    Tablero(int size);

    void mostrarTablero();

    // Colocar un barco en el tablero
    bool colocarBarco(int x, int y, Barco& barco);

    // Atacar una posición
    bool atacar(int x, int y);

    // Verificar si todos los barcos están hundidos
    bool todosBarcosHundidos() const;
};

#endif

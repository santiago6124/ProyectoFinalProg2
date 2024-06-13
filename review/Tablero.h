#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Barco.h"
#include "Coordenada.h"
using namespace std;

#ifndef Tablero_H
#define Tablero_H

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
};

#endif

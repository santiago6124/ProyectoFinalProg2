#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Coordenada.h"

class Tablero {
public:
    Tablero(int size);

    int getSize() const;
    void mostrarTablero();
    bool colocarBarco(int x, int y, Barco& barco);
    bool atacar(int x, int y);
    bool todosBarcosHundidos() const;

private:
    int size;
    std::vector<std::vector<Coordenada>> coordenadas;
};

#endif

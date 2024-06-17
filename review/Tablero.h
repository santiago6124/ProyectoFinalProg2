#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Coordenada.h"

class Tablero {
private:
    int size;
    std::vector<std::vector<Coordenada>> coordenadas;

public:
    Tablero(int size);
    void mostrarTablero() const;
    bool colocarBarco(int x, int y, Barco& barco);
    bool atacar(int x, int y);
    bool todosBarcosHundidos() const;
    int getSize() const { return size; }
};

#endif // TABLERO_H

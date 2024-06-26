#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Celda.h"
#include "Barco.h"
#include <iostream>

class Tablero {
private:
    int filas;
    int columnas;
    std::vector<Celda> celdas;
    std::vector<Barco> barcos;

public:
    Tablero(int filas, int columnas);

    bool colocarBarco(Barco& barco, int x, int y, char orientacion);
    std::string recibirDisparo(int x, int y);
    void mostrar();
};

#endif
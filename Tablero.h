// Tablero.h
#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <string>
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
    void mostrar() const;
    void mostrarPropio() const;
    std::string coordenadaATexto(int x, int y) const;
    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
    Celda& getCelda(int fila, int columna);
};

#endif

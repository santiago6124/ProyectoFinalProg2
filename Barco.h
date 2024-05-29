#ifndef BARCO_H
#define BARCO_H

#include <vector>
#include "Celda.h"

class Barco {
private:
    int tamaño;
    std::vector<Celda> celdas;
    bool hundido;

public:
    Barco(int tamaño) : tamaño(tamaño), hundido(false) {}

    void colocar(Celda& celda, char orientacion);
    bool recibirDisparo(Celda& celda);
};

#endif 

#ifndef BARCO_H
#define BARCO_H

#include <vector>
#include "Celda.h"

class Barco {
private:
    int tamaño;
    std::vector<Celda*> celdas;
    bool hundido;

public:
    Barco(int tamaño);

    void colocar(Celda& celda, char orientacion);
    bool recibirDisparo(Celda& celda);
    bool isHundido() const;
    int getTamaño() const;
};

#endif

#ifndef BARCO_H
#define BARCO_H

#include <vector>
#include "Celda.h"

class Barco {
private:
    int tamanio;
    std::vector<Celda*> celdas;
    bool hundido;

public:
    Barco(int tamanio);

    void colocar(const std::vector<Celda*>& celdas);
    bool recibirDisparo(Celda& celda);
    bool isHundido() const;
    int getTamanio() const;
};

#endif

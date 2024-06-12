#include "Barco.h"

Barco::Barco(int size) : size(size) {}

int Barco::getSize() const {
    return size;
}

const std::vector<std::pair<int, int>>& Barco::getPosiciones() const {
    return posiciones;
}

void Barco::addPosicion(int fila, int columna) {
    posiciones.emplace_back(fila, columna);
}

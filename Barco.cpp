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

bool Barco::contienePosicion(int fila, int columna) const {
    for (const auto& pos : posiciones) {
        if (pos.first == fila && pos.second == columna) {
            return true;
        }
    }
    return false;
}
#include "Celda.h"
#include "Barco.h"

Celda::Celda(int x, int y) : x(x), y(y), barco(nullptr), golpeado(false) {}

bool Celda::recibirDisparo() {
    golpeado = true;
    if (barco != nullptr) {
        return barco->recibirDisparo(*this);
    }
    return false;
}

bool Celda::estaVacia() const {
    return barco == nullptr;
}

int Celda::getX() const {
    return x;
}

int Celda::getY() const {
    return y;
}

bool Celda::isGolpeado() const {
    return golpeado;
}

void Celda::setBarco(Barco* barco) {
    this->barco = barco;
}

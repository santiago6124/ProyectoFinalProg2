#include "Celda.h"

Celda::Celda() {
    estado = EstadoCelda::unknown;
    orientation = Orientation::unknown;
    barco = false;
}

EstadoCelda Celda::getEstado() {
    return estado;
}

void Celda::setEstado(EstadoCelda estado) {
    this->estado = estado;
}

Orientation Celda::getOrientation() {
    return orientation;
}

void Celda::setOrientation(Orientation orientation) {
    this->orientation = orientation;
}

bool Celda::getBarco() {
    return barco;
}

void Celda::setBarco(bool barco) {
    this->barco = barco;
}
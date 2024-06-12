#include "Celda.h"

Celda::Celda() {
    estado = EstadoCelda::unknown;
    orientacion = Orientacion::unknown;
    barco = false;
}

EstadoCelda Celda::getEstado() {
    return estado;
}

void Celda::setEstado(EstadoCelda estado) {
    this->estado = estado;
}

Orientacion Celda::getOrientacion() {
    return orientacion;
}

void Celda::setOrientacion(Orientacion orientacion) {
    this->orientacion = orientacion;
}

bool Celda::getBarco() {
    return barco;
}

void Celda::setBarco(bool barco) {
    this->barco = barco;
}
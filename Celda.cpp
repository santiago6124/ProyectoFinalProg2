#include "Celda.h"

Celda::Celda(int fila, int columna) : fila(fila), columna(columna), golpeado(false), barco(nullptr) {}

bool Celda::estaVacia() const {
    return barco == nullptr;
}

bool Celda::isGolpeado() const {
    return golpeado;
}

bool Celda::tieneBarco() const {
    return barco != nullptr;
}

bool Celda::recibirDisparo() {
    golpeado = true;
    return tieneBarco();
}

void Celda::setBarco(Barco* barco) {
    this->barco = barco;
}

Barco* Celda::getBarco() const {
    return barco;
}

int Celda::getX() const { // Añadido
    return fila;
}

int Celda::getY() const { // Añadido
    return columna;
}

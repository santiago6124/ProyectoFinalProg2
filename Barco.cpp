#include "Barco.h"

Barco::Barco(int tamanio) : tamanio(tamanio), hundido(false) {}

void Barco::colocar(const std::vector<Celda*>& celdas) {
    this->celdas = celdas;
}

bool Barco::recibirDisparo(Celda& celda) {
    for (Celda* c : celdas) {
        if (c->getX() == celda.getX() && c->getY() == celda.getY()) {
            c->recibirDisparo();
            break;
        }
    }
    // Verificar si el barco está hundido
    hundido = true;
    for (Celda* c : celdas) {
        if (!c->isGolpeado()) {
            hundido = false;
            break;
        }
    }
    return hundido;
}

bool Barco::isHundido() const {
    return hundido;
}

int Barco::getTamanio() const {
    return tamanio;
}

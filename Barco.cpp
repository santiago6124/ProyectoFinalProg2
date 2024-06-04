#include "Barco.h"

Barco::Barco(int tamanio) : tamanio(tamanio), hundido(false) {}

void Barco::colocar(const std::vector<Celda*>& celdas) {
    this->celdas = celdas;
}


bool Barco::recibirDisparo(Celda& celda) {
    for (auto& c : celdas) {
        if (c->getX() == celda.getX() && c->getY() == celda.getY()) {
            c->recibirDisparo();
            hundido = true;
            for (auto& cell : celdas) {
                if (!cell->isGolpeado()) {
                    hundido = false;
                    break;
                }
            }
            return true;
        }
    }
    return false;
}

bool Barco::isHundido() const {
    return hundido;
}

int Barco::getTamanio() const {
    return tamanio;
}


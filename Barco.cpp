#include "Barco.h"
#include "Celda.h"

Barco::Barco(int tamaño) : tamaño(tamaño), hundido(false) {}

void Barco::colocar(Celda& celda, char orientacion) {
    for (int i = 0; i < tamaño; ++i) {
        celdas.push_back(celda);
        if (orientacion == 'H') {
            celda = Celda(celda.getX() + 1, celda.getY());
        } else {
            celda = Celda(celda.getX(), celda.getY() + 1);
        }
    }
}

bool Barco::recibirDisparo(Celda& celda) {
    for (auto& c : celdas) {
        if (c.getX() == celda.getX() && c.getY() == celda.getY()) {
            c.recibirDisparo();
            hundido = true;
            for (auto& cell : celdas) {
                if (!cell.isGolpeado()) {
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

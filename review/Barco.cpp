#include "Barco.h"

Barco::Barco(int longitud_, bool horizontal_)
    : longitud(longitud_), horizontal(horizontal_), contGolpes(0), hundido(false) {}

void Barco::recibirGolpe() {
    contGolpes++;
    verificarHundido();
}

void Barco::verificarHundido() {
    if (contGolpes == longitud) {
        hundido = true;
    }
}

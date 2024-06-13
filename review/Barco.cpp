#include "Barco.h"

Barco::Barco(int longitud_, bool horizontal_) {
    longitud = longitud_;
    horizontal = horizontal_;
}

bool Barco::verificarHundido() {
    return contGolpes == longitud;
}

void Barco::recibirGolpe() {
    contGolpes++;
    if (verificarHundido()) {
        hundido = true;
    }
}

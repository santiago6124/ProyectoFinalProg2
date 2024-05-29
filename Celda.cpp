#include "Celda.h"
#include "Barco.h"

bool Celda::recibirDisparo() {
    golpeado = true;
    if (barco != nullptr) {
        return barco->recibirDisparo(*this);
    }
    return false;
}

bool Celda::estaVacia()  {
    return barco == nullptr;
}

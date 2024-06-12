#include "Celda.h"

Celda::Celda() : estado(VACIO) {}

EstadoCelda Celda::getEstado() const {
    return estado;
}

void Celda::setEstado(EstadoCelda nuevoEstado) {
    estado = nuevoEstado;
}

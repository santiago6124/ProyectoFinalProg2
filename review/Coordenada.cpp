#include "Coordenada.h"

// Constructores
Coordenada::Coordenada() : letra(""), numero(0) {}

Coordenada::Coordenada(string letra, int numero) : letra(letra), numero(numero) {}

// Métodos de acceso
string Coordenada::getLetra() const {
    return letra;
}

int Coordenada::getNumero() const {
    return numero;
}

bool Coordenada::isTocado() const {
    return tocado;
}

Barco* Coordenada::getBarco() const {
    return barco;
}

// Métodos de modificación
void Coordenada::setBarco(Barco* barco) {
    this->barco = barco;
}

void Coordenada::setTocado(bool tocado) {
    this->tocado = tocado;
}

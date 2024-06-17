#include "Coordenada.h"

Coordenada::Coordenada() : letra(""), numero(0), tocado(false), barco(nullptr) {}

Coordenada::Coordenada(std::string letra, int numero) : letra(letra), numero(numero), tocado(false), barco(nullptr) {}

std::string Coordenada::getLetra() const {
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

void Coordenada::setBarco(Barco* barco) {
    this->barco = barco;
}

void Coordenada::setTocado(bool tocado) {
    this->tocado = tocado;
}

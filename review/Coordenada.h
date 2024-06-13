#pragma once

#include <string>
#include "Barco.h"

#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada {
private:
    std::string letra;
    int numero;
    Barco* barco = nullptr;
    bool tocado = false;

public:
    // Constructores
    Coordenada();
    Coordenada(std::string letra, int numero);

    // Métodos de acceso
    std::string getLetra() const;
    int getNumero() const;
    bool isTocado() const;
    Barco* getBarco() const;

    // Métodos de modificación
    void setBarco(Barco* barco);
    void setTocado(bool tocado);
};

#endif // COORDENADA_H

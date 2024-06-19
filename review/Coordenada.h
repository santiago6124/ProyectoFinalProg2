#pragma once

#include <string>
#include "Barco.h"
using namespace std;

#ifndef Coordenada_H
#define Coordenada_H

class Coordenada {
private:
    string letra;
    int numero;
    Barco* barco = nullptr;
    bool tocado = false;

public:
    // Constructores
    Coordenada();
    Coordenada(string letra, int numero);

    // Metodos de acceso
    string getLetra() const;
    int getNumero() const;
    bool isTocado() const;
    Barco* getBarco() const;

    // Metodos de modificacion
    void setBarco(Barco* barco);
    void setTocado(bool tocado);
};

#endif

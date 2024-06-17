#ifndef COORDENADA_H
#define COORDENADA_H

#include <string>
#include "Barco.h"

class Coordenada {
private:
    std::string letra;
    int numero;
    bool tocado;
    Barco* barco;

public:
    Coordenada();
    Coordenada(std::string letra, int numero);

    std::string getLetra() const;
    int getNumero() const;
    bool isTocado() const;
    Barco* getBarco() const;

    void setBarco(Barco* barco);
    void setTocado(bool tocado);
};

#endif // COORDENADA_H

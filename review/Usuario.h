#ifndef Usuario_H
#define Usuario_H

#include "Jugador.h"

class Usuario : public Jugador {
public:
    // Constructor
    Usuario(string nombre, int sizeTablero);

    // Sobreescribir métodos para interactuar con el tablero
    bool colocarBarco(int x, int y, Barco& barco) override;
    bool atacar(int x, int y) ;
};

#endif
#ifndef Maquina_H
#define Maquina_H

#include "Jugador.h"
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()

class Maquina : public Jugador {
public:
    // Constructor
    Maquina(string nombre, int sizeTablero);

    // Sobreescribir metodos para interactuar con el tablero
    bool colocarBarco(int x, int y, Barco& barco) override;
    bool atacar(Tablero& tableroOponente, int x, int y) ;
};

#endif
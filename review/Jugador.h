#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Tablero.h"

class Jugador {
public:
    Jugador(std::string nombre, int sizeTablero);

    std::string getNombre() const;
    Tablero& getTablero();

    virtual bool colocarBarco(int x, int y, Barco& barco) = 0;

    
    // New method to attack opponent's board
    virtual bool atacar(Tablero& tableroOponente, int x, int y);

    bool todosBarcosHundidos() const;

protected:
    std::string nombre;
    Tablero tablero;
};

#endif // JUGADOR_H

#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Tablero.h"

class Jugador {
protected:
    std::string nombre;
    Tablero tablero;

public:
    Jugador(std::string nombre, int sizeTablero);

    std::string getNombre() const;
    Tablero& getTablero();
    virtual void colocarBarcos() = 0;
    virtual bool realizarAtaque(Jugador& oponente) = 0;
    bool todosBarcosHundidos() const;
};

#endif // JUGADOR_H

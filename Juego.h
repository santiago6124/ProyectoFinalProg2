#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"

class Juego {
private:
    Jugador jugador1;
    Jugador jugador2;
    Jugador* turnoActual;
    std::string estado;

public:
    Juego(const Jugador& j1, const Jugador& j2);

    void iniciar();
    void turno();
    Jugador comprobarVictoria() const;
};

#endif // JUEGO_H
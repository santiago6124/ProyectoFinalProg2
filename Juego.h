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
    Juego( Jugador& j1,  Jugador& j2);

    void iniciar();
    void turno();
    Jugador comprobarVictoria() ;
};

#endif 
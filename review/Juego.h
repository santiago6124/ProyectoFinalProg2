// Juego.h
#ifndef JUEGO_H
#define JUEGO_H

#include <memory>
#include <string>
#include "Jugador.h"
#include "Ranking.h"

class Juego {
public:
    Juego(const std::string& nombreJugador1, const std::string& nombreJugador2, int size);

    void jugar();

private:
    std::unique_ptr<Jugador> jugador1;
    std::unique_ptr<Jugador> jugador2;
    Ranking ranking;

    int ataquesJugador1;
    int ataquesJugador2;
};

#endif // JUEGO_H

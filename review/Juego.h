// Juego.h
#ifndef JUEGO_H
#define JUEGO_H

#include <memory>
#include <string>
#include "Jugador.h"
#include "Ranking.h"
#include "Archivo.h"

class Juego {
public:
    Juego(const std::string& nombreJugador1, const std::string& nombreJugador2, int size);
    ~Juego();  // Destructor para liberar memoria
    void jugar();

private:
    Jugador* jugador1;  // Punteros crudos en lugar de std::unique_ptr
    Jugador* jugador2;
    Ranking ranking;
    Archivo archivo;

    int ataquesJugador1;
    int ataquesJugador2;
};

#endif // JUEGO_H

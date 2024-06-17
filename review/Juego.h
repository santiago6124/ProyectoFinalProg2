#ifndef JUEGO_H
#define JUEGO_H

#include "Usuario.h"
#include "Maquina.h"

class Juego {
private:
    Usuario jugador1;
    Jugador* jugador2;
    bool contraMaquina;

public:
    Juego(const std::string& nombreJugador1, const std::string& nombreJugador2, int sizeTablero, bool contraMaquina);
    void jugar();
    ~Juego();  // Destructor para liberar memoria
};

#endif // JUEGO_H

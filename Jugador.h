#ifndef JUGADOR_H
#define JUGADOR_H

#include "Tablero.h"
#include <string>

class Jugador {
public:
    Jugador(const std::string &nombre, int filas, int columnas);
    const std::string& getNombre() const;
    virtual bool realizarAtaque(Jugador &oponente, int fila, int columna);
    void mostrarTableroOponente() const;
    bool todosBarcosHundidos() const;
    virtual void colocarBarcos() = 0;

protected:
    std::string nombre;
    Tablero tableroPropio;
    Tablero tableroOponente;
};

#endif // JUGADOR_H

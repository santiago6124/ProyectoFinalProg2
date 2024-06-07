#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Tablero.h"

class Jugador {
public:
    Jugador(const std::string &nombre, int filas, int columnas);
    const std::string& getNombre() const;
    void colocarBarcos();
    void colocarBarcosAleatoriamente();
    bool realizarAtaque(Jugador &oponente, int fila, int columna);
    void mostrarTableros() const;
    bool todosBarcosHundidos() const;

protected:
    std::string nombre;
    Tablero tableroPropio;
    Tablero tableroOponente;
};

#endif // JUGADOR_H

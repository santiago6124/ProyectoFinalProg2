#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Tablero.h"
#include "Barco.h"

class Jugador {
private:
    std::string nombre;
    Tablero tableroPropio;
    Tablero tableroRival;
    std::vector<Barco> barcos;

public:
    Jugador(const std::string& nombre, int filas, int columnas);

    void colocarBarcos();
    std::string realizarDisparo(int x, int y);
    bool todosBarcosHundidos() const;
    std::string getNombre() const;
};

#endif

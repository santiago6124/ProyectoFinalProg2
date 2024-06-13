#pragma once

#include <string>
#include <vector>
#include "Tablero.h"
#include "Barco.h"

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {
private:
    std::string nombre;
    Tablero tablero;
    std::vector<Barco*> barcos; // Vector para almacenar los barcos del jugador

public:
    // Constructor
    Jugador(std::string nombre, int sizeTablero);

    // Métodos de acceso
    std::string getNombre() const;
    Tablero& getTablero();

    // Añadir barco al jugador
    void agregarBarco(Barco* barco);

    // Verificar si todos los barcos están hundidos
    bool todosBarcosHundidos() const;

    // Otros métodos, como colocar barcos, realizar disparos, etc.
};

#endif // JUGADOR_H

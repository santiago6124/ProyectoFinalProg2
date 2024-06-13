#pragma once

#include <string>
#include "Tablero.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#ifndef Jugador_H
 #define Jugador_H
        class Jugador {
        private:
            string nombre;
            Tablero tablero;

        public:
            // Constructor
            Jugador(string nombre, int sizeTablero) : nombre(nombre), tablero(sizeTablero) {}

            // Métodos de acceso
            string getNombre() const { return nombre; }
            Tablero& getTablero() { return tablero; }

            // Otros métodos, como colocar barcos, realizar disparos, etc.
    };

#endif

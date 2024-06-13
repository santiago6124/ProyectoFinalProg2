
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Tablero.h"
using namespace std;

#ifndef Juego_H
 #define Juego_H

    class Juego {
        private:
            Tablero tableroJugador1;
            Tablero tableroJugador2;

        public:
            // Constructor
            Juego(int size) : tableroJugador1(size), tableroJugador2(size) {};

            void jugar();
    };

#endif
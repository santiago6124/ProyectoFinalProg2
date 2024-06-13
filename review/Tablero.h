
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Barco.h"
using namespace std;

#ifndef Tablero_H
 #define Tablero_H

    class Tablero {
        private:
            vector<vector<char>> grid;
            int size;

        public:
            // Constructor
            Tablero(int size) : size(size), grid(size, vector<char>(size, '.')) {}

            void mostrarTablero();

            // Colocar un barco en el tablero
            bool colocarBarco(int x, int y, Barco& barco);

            // Atacar una posición
            bool atacar(int x, int y);

    };

#endif
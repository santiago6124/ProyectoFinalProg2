#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Barco.h"
using namespace std;

#ifndef Coordenada_H
 #define Coordenada_H
    class Coordenada {
        private:
            string letra;
            int numero;
            Barco* Barco = nullptr;
            bool tocado = false;

        public:
            // Constructor
            Coordenada();
            Coordenada(string letra, int numero) : letra(letra), numero(numero) {}
    };

#endif
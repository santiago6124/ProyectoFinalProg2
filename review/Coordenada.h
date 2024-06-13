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
            Barco* barco = nullptr;
            bool tocado = false;

        public:
            // Constructores
            Coordenada() : letra(""), numero(0) {}
            Coordenada(string letra, int numero) : letra(letra), numero(numero) {}

            // Métodos de acceso
            string getLetra() const { return letra; }
            int getNumero() const { return numero; }
            bool isTocado() const { return tocado; }
            Barco* getBarco() const { return barco; }

            // Métodos de modificación
            void setBarco(Barco* barco) { this->barco = barco; }
            void setTocado(bool tocado) { this->tocado = tocado; }
};

#endif
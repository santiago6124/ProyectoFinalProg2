#pragma once

#include <string>
#include <vector>
#include "Tablero.h"
#include "Barco.h"
using namespace std;

#ifndef Jugador_H
#define Jugador_H
class Jugador {
private:
    string nombre;
    Tablero tablero;
    vector<Barco*> barcos; // Vector para almacenar los barcos del jugador

public:
    // Constructor
    Jugador(string nombre, int sizeTablero) : nombre(nombre), tablero(sizeTablero) {}

    // Métodos de acceso
    string getNombre() const { return nombre; }
    Tablero& getTablero() { return tablero; }

    // Añadir barco al jugador
    void agregarBarco(Barco* barco) { barcos.push_back(barco); }

    // Verificar si todos los barcos están hundidos
    bool todosBarcosHundidos() const {
        for (const auto& barco : barcos) {
            if (!barco->isHundido()) {
                return false;
            }
        }
        return true;
    }

    // Otros métodos, como colocar barcos, realizar disparos, etc.
};

#endif

#include "Jugador.h"

// Constructor
Jugador::Jugador(std::string nombre, int sizeTablero) : nombre(nombre), tablero(sizeTablero) {}

// Métodos de acceso
std::string Jugador::getNombre() const { 
    return nombre; 
}

Tablero& Jugador::getTablero() { 
    return tablero; 
}

// Métodos para interactuar con el tablero
bool Jugador::colocarBarco(int x, int y, Barco& barco) {
    return tablero.colocarBarco(x, y, barco);
}

bool Jugador::atacar(int x, int y) {
    return tablero.atacar(x, y);
}

// Verificar si todos los barcos están hundidos
bool Jugador::todosBarcosHundidos() const {
    return tablero.todosBarcosHundidos();
}
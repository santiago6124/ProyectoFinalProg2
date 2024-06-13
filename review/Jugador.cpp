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

// Verificar si todos los barcos están hundidos
bool Jugador::todosBarcosHundidos() const {
    return tablero.todosBarcosHundidos();
}

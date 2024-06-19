#include "Jugador.h"

// Constructor
Jugador::Jugador(std::string nombre, int sizeTablero) : nombre(nombre), tablero(sizeTablero) {}

// Metodos de acceso
std::string Jugador::getNombre() const { 
    return nombre; 
}

Tablero& Jugador::getTablero() { 
    return tablero; 
}

// Metodos para interactuar con el tablero
bool Jugador::colocarBarco(int x, int y, Barco& barco) {
    return tablero.colocarBarco(x, y, barco);
}

// Nuevo metodo para atacar el tablero del oponente
bool Jugador::atacar(Tablero& tableroOponente, int x, int y) {
    return tableroOponente.atacar(x, y);
}

// Verificar si todos los barcos estan hundidos
bool Jugador::todosBarcosHundidos() const {
    return tablero.todosBarcosHundidos();
}

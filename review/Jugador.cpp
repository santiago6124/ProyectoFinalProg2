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

// Añadir barco al jugador
void Jugador::agregarBarco(Barco* barco) { 
    barcos.push_back(barco); 
}

// Verificar si todos los barcos están hundidos
bool Jugador::todosBarcosHundidos() const {
    for (const auto& barco : barcos) {
        if (!barco->isHundido()) {
            return false;
        }
    }
    return true;
}

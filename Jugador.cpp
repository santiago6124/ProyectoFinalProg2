#include "Jugador.h"

Jugador::Jugador(const std::string& nombre, int filas, int columnas) 
    : nombre(nombre), tableroPropio(filas, columnas), tableroRival(filas, columnas) {}

void Jugador::colocarBarcos() {
    // Implementar la lógica para colocar los barcos del jugador
}

std::string Jugador::realizarDisparo(int x, int y) {
    return tableroRival.recibirDisparo(x, y);
}

bool Jugador::todosBarcosHundidos() const {
    // Implementar la lógica para verificar si todos los barcos están hundidos
    return false;
}

#include "Jugador.h"

Jugador::Jugador(const std::string& nombre, int filas, int columnas) 
    : nombre(nombre), tableroPropio(filas, columnas), tableroRival(filas, columnas) {}

void Jugador::colocarBarcos() {
    // Example placement, modify to include user input for a more interactive experience
    Barco barco1(5);
    tableroPropio.colocarBarco(barco1, 0, 0, 'H');
    barcos.push_back(barco1);

    Barco barco2(4);
    tableroPropio.colocarBarco(barco2, 2, 2, 'V');
    barcos.push_back(barco2);
}

std::string Jugador::realizarDisparo(int x, int y) {
    return tableroRival.recibirDisparo(x, y);
}

bool Jugador::todosBarcosHundidos() const {
    for (const auto& barco : barcos) {
        if (!barco.isHundido()) {
            return false;
        }
    }
    return true;
}

std::string Jugador::getNombre() const {
    return nombre;
}

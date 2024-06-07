#include "Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string &nombre, int filas, int columnas)
    : nombre(nombre), tableroPropio(filas, columnas), tableroOponente(filas, columnas) {}

const std::string& Jugador::getNombre() const {
    return nombre;
}

void Jugador::colocarBarcos() {
    // Implementación manual de colocación de barcos
}

void Jugador::colocarBarcosAleatoriamente() {
    // Implementación de colocación de barcos aleatoriamente
}

bool Jugador::realizarAtaque(Jugador &oponente, int fila, int columna) {
    return oponente.tableroPropio.recibirAtaque(fila, columna);
}

void Jugador::mostrarTableros() const {
    std::cout << "Tablero de " << nombre << ":\n";
    tableroPropio.mostrarTablero();
    std::cout << "Tablero del oponente:\n";
    tableroOponente.mostrarTablero();
}

bool Jugador::todosBarcosHundidos() const {
    return tableroPropio.todosBarcosHundidos();
}

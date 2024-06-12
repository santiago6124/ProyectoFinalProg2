#include "Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string &nombre, int filas, int columnas)
    : nombre(nombre), tableroPropio(filas, columnas), tableroOponente(filas, columnas) {}

const std::string& Jugador::getNombre() const {
    return nombre;
}

bool Jugador::realizarAtaque(Jugador &oponente, int fila, int columna) {
    bool resultado = oponente.tableroPropio.recibirAtaque(fila, columna);
    if (resultado) {
        tableroOponente.getCeldas()[fila][columna].setEstado(TOCADO);
        std::cout << "¡Tocado!\n";
    } else {
        tableroOponente.getCeldas()[fila][columna].setEstado(AGUA);
        std::cout << "Agua.\n";
    }

    if (oponente.tableroPropio.verificarHundimiento(fila, columna)) {
        std::cout << "¡Barco hundido!\n";
    }

    return resultado;
}

void Jugador::mostrarTableroOponente() const {
    std::cout << "Tablero del oponente:\n";
    tableroOponente.mostrarTablero();
}

bool Jugador::todosBarcosHundidos() const {
    return tableroPropio.todosBarcosHundidos();
}
    
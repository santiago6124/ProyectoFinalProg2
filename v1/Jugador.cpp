#include "Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string &nombre, int filas, int columnas)
    : nombre(nombre), tableroPropio(filas, columnas), tableroOponente(filas, columnas) {}

const std::string& Jugador::getNombre() const {
    return nombre;
}

bool Jugador::realizarAtaque(Jugador &oponente, int fila, int columna) {
    bool resultado = oponente.tableroPropio.recibirAtaque(fila, columna);
    std::vector<std::vector<Celda>>& celdasOponente = const_cast<std::vector<std::vector<Celda>>&>(tableroOponente.getCeldas());
    if (resultado) {
        celdasOponente[fila][columna].setEstado(TOCADO);
    } else {
        celdasOponente[fila][columna].setEstado(AGUA);
    }
    return resultado;
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

#include "Jugador.h"
#include <cctype> 
#include <limits>
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

int Jugador::getFilasTablero() const {
    return tableroPropio.getFilas();
}

int Jugador::getColumnasTablero() const {
    return tableroPropio.getColumnas();
}

bool Jugador::validarFila(const std::string &inputFila, int &fila, int filas) {
    if (inputFila.length() == 1 && isalpha(inputFila[0])) {
        fila = Tablero::convertirFila(toupper(inputFila[0]));
        if (fila >= 0 && fila < filas) {
            return true;
        }
    }
    return false;
}

bool Jugador::validarColumna(int &columna, int columnas) {
    if (std::cin.fail() || columna < 1 || columna > columnas) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Entrada inválida. Intente de nuevo.\n";
        return false;
    } else {
        columna = Tablero::convertirColumna(columna);
        return true;
    }
}


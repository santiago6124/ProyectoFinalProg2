#include "Jugador.h"
#include <cctype>
#include <limits>
#include <iostream>

Jugador::Jugador(const std::string &nombre, int filas, int columnas)
    : nombre(nombre), tableroPropio(filas, columnas), tableroOponente(filas, columnas) {}

const std::string &Jugador::getNombre() const
{
    return nombre;
}

bool Jugador::realizarAtaque(Jugador &oponente, int fila, int columna)
{
    if (tableroOponente.getCeldas()[fila][columna].getEstado() != VACIO)
    {
        return false;
    }

    EstadoCelda resultado = oponente.tableroPropio.recibirAtaque(fila, columna);
    tableroOponente.getCeldas()[fila][columna].setEstado(resultado);
    if (resultado == TOCADO)
    {
        std::cout << "¡Tocado!\n";
    }
    else if (resultado == AGUA)
    {
        std::cout << "Agua.\n";
    }
    else if (resultado == HUNDIDO)
    {
        std::cout << "Barco Hundido!\n";
    }

    return true;
}

void Jugador::mostrarTableroOponente() const
{
    std::cout << "Tablero del oponente:\n";
    tableroOponente.mostrarTablero();
}

void Jugador::mostrarTableroPropio() const
{
    std::cout << "Tu tablero:\n";
    tableroPropio.mostrarTablero();
}

bool Jugador::todosBarcosHundidos() const
{
    return tableroPropio.todosBarcosHundidos();
}

int Jugador::getFilasTablero() const
{
    return tableroPropio.getFilas();
}

int Jugador::getColumnasTablero() const
{
    return tableroPropio.getColumnas();
}

bool Jugador::validarFila(const std::string &inputFila, int &fila, int filas)
{
    if (inputFila.length() == 1 && isalpha(inputFila[0]))
    {
        fila = Tablero::convertirFila(toupper(inputFila[0]));
        if (fila >= 0 && fila < filas)
        {
            return true;
        }
    }
    return false;
}

bool Jugador::validarColumna(int &columna, int columnas)
{
    if (std::cin.fail() || columna < 1 || columna > columnas)
    {
        std::cin.clear();                                                
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        return false;
    }
    else
    {
        columna = Tablero::convertirColumna(columna);
        return true;
    }
}

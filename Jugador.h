#ifndef JUGADOR_H
#define JUGADOR_H

#include "Tablero.h"
#include <string>

class Jugador {
public:
    Jugador(const std::string &nombre, int filas, int columnas);
    const std::string& getNombre() const;
    virtual bool realizarAtaque(Jugador &oponente, int fila, int columna);
    void mostrarTableroOponente() const;
    bool todosBarcosHundidos() const;
    virtual void colocarBarcos() = 0;

    int getFilasTablero() const;
    int getColumnasTablero() const;

    static bool validarFila(const std::string &inputFila, int &fila, int filas);
    static bool validarColumna(int &columna, int columnas);

protected:
    std::string nombre;
    Tablero tableroPropio;
    Tablero tableroOponente;
};

#endif // JUGADOR_H

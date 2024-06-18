#ifndef JUGADOR_H
#define JUGADOR_H

#include "Tablero.h"
#include <string>
using namespace std;

class Jugador
{
public:
    Jugador(const string &nombre, int filas, int columnas);
    const string &getNombre() const;
    virtual bool realizarAtaque(Jugador &oponente, int fila, int columna);
    void mostrarTableroOponente() const;
    bool todosBarcosHundidos() const;
    virtual void colocarBarcos() = 0;
    void mostrarTableroPropio() const;
    
    int getFilasTablero() const;
    int getColumnasTablero() const;

    static bool validarFila(const string &inputFila, int &fila, int filas);
    static bool validarColumna(int &columna, int columnas);

    void incrementarTiros();
    int getTiros() const;

    const Tablero& getTableroPropio() const;
    const Tablero& getTableroOponente() const;
    Tablero& getTableroPropio();
    Tablero& getTableroOponente();

protected:
    string nombre;
    Tablero tableroPropio;
    Tablero tableroOponente;
    int tiros;
};

#endif

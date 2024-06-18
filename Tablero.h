#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Celda.h"
#include "Barco.h"
using namespace std;

class Tablero {
private:
    int filas;
    int columnas;
    vector<vector<Celda>> celdas;
    vector<Barco> barcos;

public:
    Tablero(int filas, int columnas);
    void colocarBarco(Barco &barco, int filaInicio, int columnaInicio, bool horizontal);
    EstadoCelda recibirAtaque(int fila, int columna);
    void mostrarTablero() const;
    bool todosBarcosHundidos() const;
    int getFilas() const;
    int getColumnas() const;
    bool puedeColocarBarco(const Barco &barco, int filaInicio, int columnaInicio, bool horizontal) const;
    vector<vector<Celda>>& getCeldas();
    const vector<vector<Celda>>& getCeldas() const;
    bool verificarHundimiento(int fila, int columna);
    void hundirBarco(int fila, int columna);
    static int convertirFila(char letra);
    static int convertirColumna(int numero);
};

#endif

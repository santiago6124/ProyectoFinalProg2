#ifndef TABLERO_H
#define TABLERO_H

#include "Celda.h"
#include "Barco.h"
#include <vector>

class Tablero {
public:
    Tablero(int filas, int columnas);
    void colocarBarco(Barco &barco, int filaInicio, int columnaInicio, bool horizontal);
    bool recibirAtaque(int fila, int columna);
    void mostrarTablero() const;
    bool todosBarcosHundidos() const;
    bool puedeColocarBarco(const Barco &barco, int filaInicio, int columnaInicio, bool horizontal) const;
    int getFilas() const;
    int getColumnas() const;
    const std::vector<std::vector<Celda>>& getCeldas() const;
    bool verificarHundimiento(int fila, int columna);

private:
    int filas;
    int columnas;
    std::vector<std::vector<Celda>> celdas;
    std::vector<Barco> barcos;
};

#endif // TABLERO_H

#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Celda.h"
#include "Barco.h"

class Tablero {
public:
    Tablero(int filas, int columnas);
    void colocarBarco(const Barco &barco, int filaInicio, int columnaInicio, bool horizontal);
    bool recibirAtaque(int fila, int columna);
    void mostrarTablero() const;
    bool todosBarcosHundidos() const;

private:
    int filas;
    int columnas;
    std::vector<std::vector<Celda>> celdas;
    std::vector<Barco> barcos;
};

#endif // TABLERO_H

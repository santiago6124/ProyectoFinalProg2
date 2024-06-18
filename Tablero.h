#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Celda.h"
#include <string>
#include "Barco.h"
using namespace std;

class Tablero {
public:
    Tablero(int filas, int columnas);

    void colocarBarco(Barco &barco, int filaInicio, int columnaInicio, bool horizontal);
    std::vector<std::pair<int, int>> recibirAtaque(int fila, int columna);
    bool todosBarcosHundidos() const;
    void mostrarTablero() const;

    int getFilas() const;
    int getColumnas() const;

    bool puedeColocarBarco(const Barco &barco, int filaInicio, int columnaInicio, bool horizontal) const;
    vector<vector<Celda>>& getCeldas();
    const vector<vector<Celda>>& getCeldas() const;

    static int convertirFila(char letra);
    static int convertirColumna(int numero);

    std::vector<std::vector<int>> getDatos() const;
    void setDatos(const std::vector<std::vector<int>> &nuevosDatos);
    void cargarDesdeArchivo(const std::string &nombreArchivo);

private:
    int filas;
    int columnas;
    vector<vector<Celda>> celdas;
    vector<Barco> barcos;

    void hundirBarco(int fila, int columna, std::vector<std::pair<int, int>>& celdasAfectadas);
    bool verificarHundimiento(int fila, int columna);
};
#endif // TABLERO_H

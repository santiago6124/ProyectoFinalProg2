#include "Usuario.h"
#include <iostream>
#include <cctype> // Para toupper
#include <limits> // Para numeric_limits

Usuario::Usuario(const string& nombre, int filas, int columnas)
    : Jugador(nombre, filas, columnas) {}

void Usuario::colocarBarcos() {
    int tamanios[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};

     for (int size : tamanios) {
         bool colocado = false;
         while (!colocado) {
             cout << "Colocando barco de tamanio " << size << "\n";
             int fila;
             int columna;
             bool horizontal;
             // Validar fila
             while (true) {
                 string inputFila;
                 cout << "Ingrese la fila inicial (A-" << static_cast<char>('A' + tableroPropio.getFilas() - 1) << "): ";
                 cin >> inputFila;
                 if (inputFila.length() == 1 && isalpha(inputFila[0])) {
                     fila = Tablero::convertirFila(toupper(inputFila[0]));
                     if (fila >= 0 && fila < tableroPropio.getFilas()) {
                         break;
                     }
                 }
                 cout << "Entrada invalida. Intente de nuevo.\n";
             }

             // Validar columna
             while (true) {
                 cout << "Ingrese la columna inicial (1-" << tableroPropio.getColumnas() << "): ";
                 cin >> columna;
                 if (cin.fail() || columna < 1 || columna > tableroPropio.getColumnas()) {
                     cin.clear(); // Clear the error flag
                     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                     cout << "Entrada invalida. Intente de nuevo.\n";
                 } else {
                     columna = Tablero::convertirColumna(columna);
                     break;
                 }
             }

             // Validar orientación
             while (true) {
                 string orientacion;
                 cout << "Ingrese la orientacion (H para horizontal, V para vertical): ";
                 cin >> orientacion;
                 if (orientacion.length() == 1) {
                     char dir = toupper(orientacion[0]);
                     if (dir == 'H' || dir == 'V') {
                         horizontal = (dir == 'H');
                         break;
                     }
                 }
                 cout << "Entrada invalida. Intente de nuevo.\n";
             }

             Barco barco(size);
             if (tableroPropio.puedeColocarBarco(barco, fila, columna, horizontal)) {
                 tableroPropio.colocarBarco(barco, fila, columna, horizontal);
                 tableroPropio.mostrarTablero();  // Mostrar el tablero después de colocar el barco
                 colocado = true;
             } else {
                 cout << "No se puede colocar el barco aqui, intente de nuevo.\n";
             }
         }
     }
};
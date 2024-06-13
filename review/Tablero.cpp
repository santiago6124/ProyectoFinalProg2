#include "Tablero.h"
#include "Barco.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void Tablero::mostrarTablero() {
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool Tablero::colocarBarco(int x, int y, Barco& barco) {

    if (barco.isHorizontal()) {
        if (x + barco.getLongitud() > size) return false;
            for (int i = 0; i < barco.getLongitud(); i++) {
                grid[y][x + i] = 'B';
            }
        } else {
            if (y + barco.getLongitud() > size) return false;
                for (int i = 0; i < barco.getLongitud(); i++) {
                    grid[y + i][x] = 'B';
                }
        }
    
        return true;
}

bool Tablero::atacar(int x, int y){
    if (grid[y][x] == 'B') {
        grid[y][x] = 'X';
        return true;
    } else if (grid[y][x] == '.') {
        grid[y][x] = 'O';
    }
    return false;
}

#include "Archivo.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool Archivo::preguntarContinuar() {
    char respuesta;
    cout << "¿Desea continuar una partida guardada? (S/N): ";
    cin >> respuesta;
    return tolower(respuesta) == 's';
}

bool Archivo::cargarPartida(vector<vector<int>> &tablero1, vector<vector<int>> &tablero2) {
    ifstream archivo("partida_guardada.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de partida guardada." << endl;
        return false;
    }

    string linea;
    int fila = 0;

    // Leer el tablero del primer jugador
    for (int i = 0; i < tablero1.size(); ++i) {
        if (!getline(archivo, linea)) {
            cerr << "Error al leer la línea del tablero del jugador 1, línea: " << i << endl;
            return false;
        }
        stringstream ss(linea);
        for (int j = 0; j < tablero1[i].size(); ++j) {
            if (!(ss >> tablero1[i][j])) {
                cerr << "Error al parsear el valor del tablero del jugador 1 en (" << i << ", " << j << ")" << endl;
                return false;
            }
        }
    }

    // Leer el tablero del segundo jugador
    for (int i = 0; i < tablero2.size(); ++i) {
        if (!getline(archivo, linea)) {
            cerr << "Error al leer la línea del tablero del jugador 2, línea: " << i << endl;
            return false;
        }
        stringstream ss(linea);
        for (int j = 0; j < tablero2[i].size(); ++j) {
            if (!(ss >> tablero2[i][j])) {
                cerr << "Error al parsear el valor del tablero del jugador 2 en (" << i << ", " << j << ")" << endl;
                return false;
            }
        }
    }

    archivo.close();
    return true;
}

void Archivo::guardarPartida(const vector<vector<int>> &tablero1, const vector<vector<int>> &tablero2) {
    ofstream archivo("partida_guardada.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para guardar la partida." << endl;
        return;
    }

    // Guardar el tablero del primer jugador
    for (const auto &fila : tablero1) {
        for (int celda : fila) {
            archivo << celda << " ";
        }
        archivo << endl;
    }

    // Guardar el tablero del segundo jugador
    for (const auto &fila : tablero2) {
        for (int celda : fila) {
            archivo << celda << " ";
        }
        archivo << endl;
    }

    archivo.close();
}

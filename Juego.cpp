#include "Juego.h"
#include "Maquina.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>

Juego::Juego(Jugador& j1, Jugador& j2) : jugador1(j1), jugador2(j2) {}

void Juego::iniciar() {
    cout << "--------------------------------------\n";
    cout << jugador1.getNombre() << ", coloca tus barcos:\n";
    cout << "--------------------------------------\n";
    jugador1.colocarBarcos();
    
    cout << "--------------------------------------\n";
    cout << jugador2.getNombre() << ", coloca tus barcos:\n";
    cout << "--------------------------------------\n";
    jugador2.colocarBarcos();

    Jugador *turnoActual = &jugador1;
    Jugador *oponente = &jugador2;

    while (true) {
        cout << "Turno de " << turnoActual->getNombre() << "\n";

        if (dynamic_cast<Maquina*>(turnoActual)) {
            dynamic_cast<Maquina*>(turnoActual)->realizarAtaque(*oponente);
        } else {
            int fila, columna;
            bool ataqueExitoso = false;

            while (!ataqueExitoso) {
                // Validar fila
                while (true) {
                    cout << "Ingrese la fila a atacar (A-" << static_cast<char>('A' + oponente->getFilasTablero() - 1) << "): ";
                    string inputFila;
                    cin >> inputFila;
                    if (inputFila.length() == 1 && isalpha(inputFila[0])) {
                        fila = Tablero::convertirFila(toupper(inputFila[0]));
                        if (fila >= 0 && fila < oponente->getFilasTablero()) {
                            break;
                        }
                    }
                    cout << "Entrada inválida. Intente de nuevo.\n";
                }

                // Validar columna
                while (true) {
                    cout << "Ingrese la columna a atacar (1-" << oponente->getColumnasTablero() << "): ";
                    cin >> columna;
                    if (cin.fail() || columna < 1 || columna > oponente->getColumnasTablero()) {
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada inválida
                        cout << "Entrada inválida. Intente de nuevo.\n";
                    } else {
                        columna = Tablero::convertirColumna(columna);
                        break;
                    }
                }

                // Realizar ataque y verificar si las coordenadas son válidas
                ataqueExitoso = turnoActual->realizarAtaque(*oponente, fila, columna);
                if (!ataqueExitoso) {
                    cout << "Coordenadas de ataque inválidas o repetidas. Intente de nuevo.\n";
                }
            }
        }

        // Mostrar el tablero del oponente actualizado después del ataque
        turnoActual->mostrarTableroOponente();

        // Verificar si todos los barcos del oponente están hundidos
        if (oponente->todosBarcosHundidos()) {
            cout << turnoActual->getNombre() << " ha ganado!\n";
            break;
        }

        swap(turnoActual, oponente);
    }

    // Guardar el ranking
    vector<pair<string, int>> ranking = cargarRanking("ranking.txt");
    ranking.push_back(make_pair(turnoActual->getNombre(), turnoActual->getTiros()));
    sort(ranking.begin(), ranking.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second; // Ordenar de menor a mayor número de tiros
    });
    if (ranking.size() > 5) {
        ranking.resize(5);
    }
    guardarRanking("ranking.txt", ranking);
}

void Juego::guardarRanking(const string &filename, const vector<pair<string, int>> &ranking) {
    ofstream file(filename);
    if (file.is_open()) {
        // Agregar título explicativo al archivo
        file << "Ranking de Jugadores respecto a tiros hechos\n";
        for (const auto& record : ranking) {
            file << record.first << " " << record.second << "\n";
        }
        file.close();
        cout << "Ranking guardado exitosamente en " << filename << ".\n";
    } else {
        cerr << "No se pudo abrir el archivo " << filename << " para guardar el ranking.\n";
    }
}

vector<pair<string, int>> Juego::cargarRanking(const string &filename) {
    vector<pair<string, int>> ranking;
    ifstream file(filename);
    if (file.is_open()) {
        string nombre;
        int tiros;
        while (file >> nombre >> tiros) {
            ranking.push_back(make_pair(nombre, tiros));
        }
        file.close();
    } else {
        cerr << "No se pudo abrir el archivo " << filename << " para cargar el ranking.\n";
    }
    return ranking;
}

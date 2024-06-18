#include "Juego.h"
#include "Maquina.h"
#include "Archivo.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>

using namespace std;

Juego::Juego(Jugador &j1, Jugador &j2) : jugador1(j1), jugador2(j2) {}

void Juego::iniciar()
{
    if (Archivo::preguntarContinuar())
    {
        vector<vector<int>> tablero1 = jugador1.getTableroPropio().getDatos();
        vector<vector<int>> tablero2 = jugador2.getTableroPropio().getDatos();
        if (!Archivo::cargarPartida(tablero1, tablero2))
        {
            cerr << "Error al cargar la partida guardada." << endl;
        }
        else
        {
            jugador1.getTableroPropio().setDatos(tablero1);
            jugador2.getTableroPropio().setDatos(tablero2);
            cout << "Partida cargada exitosamente." << endl;

            cout << "Tablero del jugador 1:" << endl;
            jugador1.getTableroPropio().mostrarTablero();
            cout << "Tablero del jugador 2:" << endl;
            jugador2.getTableroPropio().mostrarTablero();
        }
    }
    else
    {
        cout << "--------------------------------------\n";
        cout << jugador1.getNombre() << ", coloca tus barcos:\n";
        cout << "--------------------------------------\n";
        jugador1.colocarBarcos();

        cout << "--------------------------------------\n";
        cout << jugador2.getNombre() << ", coloca tus barcos:\n";
        cout << "--------------------------------------\n";
        jugador2.colocarBarcos();
    }

    Jugador *turnoActual = &jugador1;
    Jugador *oponente = &jugador2;

    while (true)
    {
        cout << "Turno de " << turnoActual->getNombre() << "\n";

        if (dynamic_cast<Maquina *>(turnoActual))
        {
            dynamic_cast<Maquina *>(turnoActual)->realizarAtaque(*oponente);
        }
        else
        {
            int fila, columna;
            bool ataqueExitoso = false;

            while (!ataqueExitoso)
            {
                while (true)
                {
                    cout << "Ingrese la fila a atacar (A-" << static_cast<char>('A' + oponente->getTableroPropio().getFilas() - 1) << "): ";
                    string inputFila;
                    cin >> inputFila;
                    if (inputFila.length() == 1 && isalpha(inputFila[0]))
                    {
                        fila = Tablero::convertirFila(toupper(inputFila[0]));
                        if (fila >= 0 && fila < oponente->getTableroPropio().getFilas())
                        {
                            break;
                        }
                    }
                    cout << "Entrada inválida. Intente de nuevo.\n";
                }

                while (true)
                {
                    cout << "Ingrese la columna a atacar (1-" << oponente->getTableroPropio().getColumnas() << "): ";
                    cin >> columna;
                    if (cin.fail() || columna < 1 || columna > oponente->getTableroPropio().getColumnas())
                    {
                        cin.clear();                                         
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Entrada inválida. Intente de nuevo.\n";
                    }
                    else
                    {
                        columna = Tablero::convertirColumna(columna);
                        break;
                    }
                }

                ataqueExitoso = turnoActual->realizarAtaque(*oponente, fila, columna);
                if (!ataqueExitoso)
                {
                    cout << "Coordenadas de ataque inválidas o repetidas. Intente de nuevo.\n";
                }
            }
        }

        turnoActual->mostrarTableroOponente();
        Archivo::guardarPartida(jugador1.getTableroPropio().getDatos(), jugador2.getTableroPropio().getDatos());

        if (oponente->getTableroPropio().todosBarcosHundidos())
        {
            cout << turnoActual->getNombre() << " ha ganado!\n";
            break;
        }

        swap(turnoActual, oponente);
    }

    vector<pair<string, int>> ranking = cargarRanking("ranking.txt");

    ranking.push_back(make_pair(turnoActual->getNombre(), turnoActual->getTiros()));
    sort(ranking.begin(), ranking.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         { return a.second < b.second; });
    if (ranking.size() > 5)
    {
        ranking.resize(5);
    }

    guardarRanking("ranking.txt", ranking);
}

void Juego::guardarRanking(const string &filename, const vector<pair<string, int>> &ranking)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (const auto &record : ranking)
        {
            file << record.first << " " << record.second << "\n";
        }
        file.close();
        cout << "Ranking actualizado y guardado exitosamente en " << filename << ".\n";
    }
    else
    {
        cerr << "No se pudo abrir el archivo " << filename << " para guardar el ranking.\n";
    }
}

vector<pair<string, int>> Juego::cargarRanking(const string &filename)
{
    vector<pair<string, int>> ranking;
    ifstream file(filename);
    if (file.is_open())
    {
        string nombre;
        int tiros;
        while (file >> nombre >> tiros)
        {
            ranking.push_back(make_pair(nombre, tiros));
        }
        file.close();
    }
    else
    {
        cerr << "No se pudo abrir el archivo " << filename << " para cargar el ranking.\n";
        return ranking;

    sort(ranking.begin(), ranking.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         { return a.second < b.second; });

    if (ranking.size() > 5)
    {
        ranking.resize(5);
    }

    return ranking;
}
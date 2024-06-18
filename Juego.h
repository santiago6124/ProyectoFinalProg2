#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <string>
#include <utility>
#include "Jugador.h"
using namespace std;

class Juego {
public:
    Juego(Jugador& j1, Jugador& j2);
    void iniciar();
    void guardarRanking(const string &filename, const vector<pair<string, int>> &ranking);
    vector<pair<string, int>> cargarRanking(const string &filename);

private:
    Jugador& jugador1;
    Jugador& jugador2;
};

#endif

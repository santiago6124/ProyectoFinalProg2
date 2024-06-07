#ifndef JUEGO_H
#define JUEGO_H

#include "Usuario.h"
#include "Maquina.h"
#include "Archivo.h"
#include <vector>

class Juego {
public:
    Juego(Jugador& jugador1, Jugador& jugador2);
    void iniciar();
    void guardarRanking(const std::string &filename, const std::vector<std::pair<std::string, int>> &ranking);
    std::vector<std::pair<std::string, int>> cargarRanking(const std::string &filename);

private:
    Jugador& jugador1;
    Jugador& jugador2;
};

#endif // JUEGO_H

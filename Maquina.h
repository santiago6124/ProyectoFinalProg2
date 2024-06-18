#ifndef MAQUINA_H
#define MAQUINA_H

#include "Jugador.h"
using namespace std;

class Maquina : public Jugador {
public:
    Maquina(const string& nombre, int filas, int columnas);
    void colocarBarcos() override;
    bool realizarAtaque(Jugador &oponente);

private:
    int generarFila();
    int generarColumna();
    bool generarOrientacion();
};

#endif

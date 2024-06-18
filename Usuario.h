#ifndef USUARIO_H
#define USUARIO_H

#include "Jugador.h"
using namespace std;

class Usuario : public Jugador {
public:
    Usuario(const string& nombre, int filas, int columnas);
    void colocarBarcos() override;
};

#endif 

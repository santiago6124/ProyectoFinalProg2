#ifndef USUARIO_H
#define USUARIO_H

#include "Jugador.h"

class Usuario : public Jugador {
public:
    Usuario(const std::string& nombre, int filas, int columnas);
    void colocarBarcos();
};

#endif // USUARIO_H

#ifndef MAQUINA_H
#define MAQUINA_H

#include "Jugador.h"

class Maquina : public Jugador {
public:
    Maquina(const std::string& nombre, int filas, int columnas);
    void colocarBarcos() override;
};

#endif // MAQUINA_H

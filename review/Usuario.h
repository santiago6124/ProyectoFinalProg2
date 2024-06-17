#ifndef USUARIO_H
#define USUARIO_H

#include "Jugador.h"
#include <vector>

class Usuario : public Jugador {
private:
    std::vector<Barco> barcos; // Añadido: vector de barcos

public:
    Usuario(std::string nombre, int sizeTablero);
    void colocarBarcos() override;
    bool realizarAtaque(Jugador& oponente) override;
};

#endif // USUARIO_H

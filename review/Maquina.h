#ifndef MAQUINA_H
#define MAQUINA_H

#include "Jugador.h"
#include <vector>
#include <random>

class Maquina : public Jugador {
private:
    std::vector<Barco> barcos; // Añadido: vector de barcos

public:
    Maquina(std::string nombre, int sizeTablero);
    void colocarBarcos() override;
    bool realizarAtaque(Jugador& oponente) override;

private:
    int generarNumeroAleatorio(int min, int max);
};

#endif // MAQUINA_H

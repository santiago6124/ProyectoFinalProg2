#pragma once

#ifndef Barco_H
#define Barco_H

#include <vector>
#include <utility>

class Barco {
private:
    int longitud; // Número de coordenadas que ocupa
    bool horizontal; // Orientación del barco
    bool hundido = false;
    int contGolpes = 0;
    std::vector<std::pair<int, int>> coordenadas; // Coordenadas del barco

public:
    // Constructor
    Barco(int longitud, bool horizontal);

    // Verificar si el barco está hundido
    bool verificarHundido();

    // Método para registrar un golpe
    void recibirGolpe();

    // Añadir coordenada del barco
    void agregarCoordenada(int x, int y) { coordenadas.push_back({x, y}); }

    // Obtener coordenadas del barco
    const std::vector<std::pair<int, int>>& getCoordenadas() const { return coordenadas; }

    // Métodos de acceso
    int getLongitud() const { return longitud; }
    bool isHorizontal() const { return horizontal; }
    bool isHundido() const { return hundido; }
};

#endif
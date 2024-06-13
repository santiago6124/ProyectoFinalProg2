#pragma once

#ifndef Barco_H
#define Barco_H

class Barco {
private:
    int longitud; // Número de coordenadas que ocupa
    bool horizontal; // Orientación del barco
    bool hundido = false;
    int contGolpes = 0;

public:
    // Constructor
    Barco(int longitud, bool horizontal);

    // Verificar si el barco está hundido
    bool verificarHundido();

    // Método para registrar un golpe
    void recibirGolpe();

    // Métodos de acceso
    int getLongitud() const { return longitud; }
    bool isHorizontal() const { return horizontal; }
    bool isHundido() const { return hundido; }
};

#endif

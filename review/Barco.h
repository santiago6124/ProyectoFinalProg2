#pragma once

#ifndef Barco_H
#define Barco_H

class Barco {
private:
    int longitud; // Numero de coordenadas que ocupa
    bool horizontal; // Orientacion del barco
    bool hundido = false;
    int contGolpes = 0;

public:
    // Constructor
    Barco(int longitud, bool horizontal);

    // Verificar si el barco esta hundido
    bool verificarHundido();

    // Metodo para registrar un golpe
    void recibirGolpe();

    // Metodos de acceso
    int getLongitud() { return longitud; }
    bool isHorizontal() { return horizontal; }
    bool isHundido() { return hundido; }
};

#endif


#include <string>
#include <iostream>
#include "Barco.h"
using namespace std;

class Coordenada {
private:
    string letra;
    int numero;
    Barco* Barco = nullptr;
    bool tocado = false;

public:
    // Constructor
    Coordenada();
    Coordenada(string letra, int numero) : letra(letra), numero(numero) {}
};
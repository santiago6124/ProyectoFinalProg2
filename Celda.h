#ifndef CELDA_H
#define CELDA_H

class Barco;

class Celda {
private:
    int x;
    int y;
    Barco* barco;
    bool golpeado;

public:
    Celda(int x, int y) : x(x), y(y), barco(nullptr), golpeado(false) {}
    
    bool recibirDisparo();
    bool estaVacia() const;
};

#endif // CELDA_H

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
    Celda(int x, int y);

    bool recibirDisparo();
    bool estaVacia() const;
     bool tieneBarco() const;
    int getX() const;
    int getY() const;
    bool isGolpeado() const;
    void setBarco(Barco* barco);
};

#endif

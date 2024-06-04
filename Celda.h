#ifndef CELDA_H
#define CELDA_H

class Barco;

class Celda {
private:
    int fila;
    int columna;
    bool golpeado;
    Barco* barco;

public:
    Celda(int fila, int columna);

    bool estaVacia() const;
    bool isGolpeado() const;
    bool tieneBarco() const;
    bool recibirDisparo();
    void setBarco(Barco* barco);
    Barco* getBarco() const;

    int getX() const; // Añadido
    int getY() const; // Añadido
};

#endif

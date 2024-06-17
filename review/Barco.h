#ifndef BARCO_H
#define BARCO_H

class Barco {
private:
    int longitud;
    bool horizontal;
    int contGolpes;
    bool hundido;

public:
    Barco(int longitud_, bool horizontal_);
    int getLongitud() const { return longitud; }
    bool isHorizontal() const { return horizontal; }
    bool isHundido() const { return hundido; }
    void recibirGolpe();
    void verificarHundido();
};

#endif // BARCO_H

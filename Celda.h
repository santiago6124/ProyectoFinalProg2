#ifndef CELDA_H
#define CELDA_H

enum EstadoCelda { VACIO, BARCO, AGUA, TOCADO, HUNDIDO };

class Celda {
public:
    Celda();
    EstadoCelda getEstado() const;
    void setEstado(EstadoCelda nuevoEstado);

private:
    EstadoCelda estado;
};

#endif

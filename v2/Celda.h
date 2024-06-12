#ifndef CELDA_H
#define CELDA_H

enum class EstadoCelda {
    unknown = 0,
    hit = 1,
    sink = 2,
    miss = 3
};

enum class Orientation {
    unknown = 0,
    horizontal = 1,
    vertical = 2
};

class Celda {
    private:
        EstadoCelda estado;
        Orientation orientation;
        bool barco;
    public:
        Celda();
        EstadoCelda getEstado();
        void setEstado(EstadoCelda estado);
        Orientation getOrientation();
        void setOrientation(Orientation orientation);
        bool getBarco();
        void setBarco(bool barco);
};
#endif
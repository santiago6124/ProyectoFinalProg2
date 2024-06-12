#ifndef BARCO_H
#define BARCO_H

#include <vector>
#include <utility>

class Barco {
public:
    Barco(int size);
    int getSize() const;
    const std::vector<std::pair<int, int>>& getPosiciones() const;
    void addPosicion(int fila, int columna);

private:
    int size;
    std::vector<std::pair<int, int>> posiciones;
};

#endif // BARCO_H

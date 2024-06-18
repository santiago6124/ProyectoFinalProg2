#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <vector>

class Archivo {
public:
    static bool preguntarContinuar();
    static bool cargarPartida(std::vector<std::vector<int>> &tablero1, std::vector<std::vector<int>> &tablero2);
    static void guardarPartida(const std::vector<std::vector<int>> &tablero1, const std::vector<std::vector<int>> &tablero2);
};

#endif // ARCHIVO_H

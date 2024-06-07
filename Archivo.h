#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <vector>
#include <string>

class Archivo {
public:
    static void guardarRanking(const std::string &filename, const std::vector<std::pair<std::string, int>> &ranking);
    static std::vector<std::pair<std::string, int>> cargarRanking(const std::string &filename);
};

#endif // ARCHIVO_H

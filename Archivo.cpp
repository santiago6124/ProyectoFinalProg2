#include "Archivo.h"
#include <fstream>

void Archivo::guardarRanking(const std::string &filename, const std::vector<std::pair<std::string, int>> &ranking) {
    std::ofstream archivo(filename);
    for (const auto &entry : ranking) {
        archivo << entry.first << " " << entry.second << std::endl;
    }
}

std::vector<std::pair<std::string, int>> Archivo::cargarRanking(const std::string &filename) {
    std::vector<std::pair<std::string, int>> ranking;
    std::ifstream archivo(filename);
    std::string nombre;
    int puntaje;
    while (archivo >> nombre >> puntaje) {
        ranking.emplace_back(nombre, puntaje);
    }
    return ranking;
}

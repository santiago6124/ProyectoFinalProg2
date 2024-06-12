#include "Archivo.h"
#include <fstream>
#include <iostream>

void Archivo::guardarRanking(const std::string &filename, const std::vector<std::pair<std::string, int>> &ranking) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto &entry : ranking) {
            file << entry.first << " " << entry.second << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Error al abrir el archivo para guardar el ranking." << std::endl;
    }
}

std::vector<std::pair<std::string, int>> Archivo::cargarRanking(const std::string &filename) {
    std::vector<std::pair<std::string, int>> ranking;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string name;
        int score;
        while (file >> name >> score) {
            ranking.emplace_back(name, score);
        }
        file.close();
    } else {
        std::cerr << "Error al abrir el archivo para cargar el ranking." << std::endl;
    }
    return ranking;
}

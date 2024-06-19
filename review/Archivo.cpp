#include "Archivo.h"
#include <fstream>
#include <iostream>

// Constructor
Archivo::Archivo(const std::string& nombreArchivo) : nombreArchivo(nombreArchivo) {}

// Método para guardar datos en el archivo
void Archivo::guardar(const std::vector<std::string>& datos) {
    std::ofstream archivo(nombreArchivo); // Abre el archivo en modo de adición
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para guardar los datos." << std::endl;
        return;
    }

    for (const auto& linea : datos) {
        archivo << linea << std::endl;
    }

    archivo.close();
}

// Método para cargar datos desde el archivo
std::vector<std::string> Archivo::cargar() {
    std::vector<std::string> datos;
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para cargar los datos." << std::endl;
        return datos;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        datos.push_back(linea);
    }

    archivo.close();
    return datos;
}

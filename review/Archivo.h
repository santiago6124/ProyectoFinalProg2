#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include <vector>

class Archivo {
public:
    // Constructor
    Archivo(const std::string& nombreArchivo);

    // Métodos para guardar y cargar
    void guardar(const std::vector<std::string>& datos);
    std::vector<std::string> cargar();

private:
    std::string nombreArchivo;
};

#endif 

#include "util.h"
#include <cctype>
#include <string>

bool parsearEntrada(const std::string& entrada, int& x, int& y) {
    if (entrada.length() < 2) return false;
    char letra = entrada[0];
    std::string numero = entrada.substr(1);
    if (!std::isdigit(numero[0])) return false;

    y = std::toupper(letra) - 'A';
    x = std::stoi(numero) - 1;

    return x >= 0 && y >= 0; // Verifica que los índices no sean negativos
}

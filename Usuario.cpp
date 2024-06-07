#include "Usuario.h"

Usuario::Usuario(const std::string& nombre, int filas, int columnas)
    : Jugador(nombre, filas, columnas) {}

void Usuario::colocarBarcos() {
    Jugador::colocarBarcos();
}
